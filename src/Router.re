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

  let setPosts = () =>
    FetchApi.fetchPosts()
    |> Js.Promise.then_(results => {
         dispatch(UpdatePosts(results));
         Js.Promise.resolve(results);
       });

  React.useEffect0(() => {
    setPosts();
    None;
  });

  let url = ReasonReactRouter.useUrl();

  let getFileName = (~id: string, ~posts: list(post)) => {
    switch (List.find(post => post.id == id, posts).file) {
    | exception Not_found => "NotFound.md"
    | post => post
    };
  };

  switch (url.search) {
  | "" => <ArticleList posts={state.posts} />
  | search => <Article id=search getFileName />
  };
};