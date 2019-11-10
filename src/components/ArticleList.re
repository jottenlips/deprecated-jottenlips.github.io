open Routes
[@react.component]
let make = () => {
  <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
  <Emoji emoji={j|✨|j}/>
  {ReasonReact.string("Hi! My name is John, 
  I'm a software developer, that lives in Nashville. 
  I love to learn and spread knowledge about
  programming, cooking, and music, so I decided to start this blog.
  Welcome!")}
  <Emoji emoji={j|✨|j}/>

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

