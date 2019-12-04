open ArticleList 
open Api

type state = {
  posts: list(post)
};

type action =
  | UpdatePosts(list(post))

let defaultState = {posts: []};

[@react.component]
let make = () => {
    let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | UpdatePosts(posts) => { posts: posts }
        },
        defaultState,
    );

    React.useEffect0(
        () => {
            FetchApi.fetchPosts()
                |> Js.Promise.then_(results => {
                dispatch(UpdatePosts(results))
                Js.Promise.resolve(results);
            })
            None
        },

    );
    let url = ReasonReactRouter.useUrl();

    let filterPosts = (~id: string, ~posts: list(post)) => {
        posts
        /* Convert to list to an array for ReasonReact's type bindings */
        |> List.filter((post) => post.id == id)
        |> Array.of_list
        /* Map each array item to a <Card /> component */
    }

    let getPost = (~id: string, ~posts: list(post)) => {
        filterPosts(id, posts)[0]
    }

    switch (url.path) {
    | ["post", id] => {
        (<Article post={getPost(id, state.posts)} />)
    }
    | [] => (
        <ArticleList posts={state.posts}/>
    )
    | _ => (<ArticleList  posts={state.posts}/>)
    };
}

