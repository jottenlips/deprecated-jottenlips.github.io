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
      <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
      <Emoji emoji={j|✨|j}/>
      {ReasonReact.string("Hi! My name is John, 
      I'm a software developer, that lives in Nashville. 
      I love to learn and spread knowledge about
      programming, cooking, and music, so I decided to start this blog.
      Welcome!")}
      <Emoji emoji={j|✨|j}/>
        {
          state.posts
          /* Convert to list to an array for ReasonReact's type bindings */
          |> Array.of_list
          /* Map each array item to a <Card /> component */
          |> Array.map((post) => <Post key={post.title} post={post}/>)
          /* Transform the array into a valid React node, similar to ReasonReact.string */
          |> ReasonReact.array
        }
      </div>
};