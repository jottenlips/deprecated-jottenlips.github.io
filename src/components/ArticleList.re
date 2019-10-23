open Routes
[@bs.module] external trumpet : string = "../../assets/trumpet.svg";
[@react.component]
let make = () => {
  <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
  <img src=trumpet className="App-logo" alt="logo" />
  {ReasonReact.string("Welcome to bopdev")}
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
  