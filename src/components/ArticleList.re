open Routes
[@react.component]
let make = () => {
  <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
  {ReasonReact.string("Hi! my name is John Ottenlips, I am a software developer that lives in Nashville. Welcome to my blog.")}
    {
      posts
      /* Convert to list to an array for ReasonReact's type bindings */
      |> Array.of_list
      /* Map each array item to a <Card /> component */
      |> Array.map((post) => <Post key={post.title} post={post}/>)
      /* Transform the array into a valid React node, similar to ReasonReact.string */
      |> ReasonReact.array
    }
  </div>;
};
  