open ArticleList;
open Api;

type state = {posts: list(post)};

type action =
  | UpdatePosts(list(post));

let defaultState = {posts: []};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | UpdatePosts(posts) => {posts: posts}
        },
      defaultState,
    );

  React.useEffect0(() => {
    FetchApi.fetchPosts()
    |> Js.Promise.then_(results => {
         dispatch(UpdatePosts(results));
         Js.Promise.resolve(results);
       });
    None;
  });
  let url = ReasonReactRouter.useUrl();

  let filterPosts = (~id: string, ~posts: list(post)) => {
    posts |> List.filter(post => post.id == id) |> Array.of_list;
  };

  let getPost = (~id: string, ~posts: list(post)) => {
    let post = filterPosts(id, posts)[0];
    post.file;
  };

  switch (url.path) {
  | ["post", id] => <Article file={getPost(id, state.posts)} />
  | [] => <ArticleList posts={state.posts} />
  | _ => <ArticleList posts={state.posts} />
  };
};