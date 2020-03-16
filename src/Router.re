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

  let getPost = (~id: string, ~posts: list(post)) => {
    switch (List.find(post => post.id == id, posts).file) {
    | exception Not_found => "Welcome.md"
    | post => post
    };
  };

  switch (url.search) {
  | "" => <ArticleList posts={state.posts} />
  | search => <Article file={getPost(search, state.posts)} />
  | _ => <ArticleList posts={state.posts} />
  };
};