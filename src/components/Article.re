open Api
[@react.component]
let make = (~id: string) => {
  <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
  <button onClick={_event => ReasonReactRouter.push("/")} style=(
    ReactDOMRe.Style.make(~color="#000000", ())
  )>
  {ReasonReact.string("< Back")}
  <br/>
  </button>
  /* {
    Api.fetchPosts()
    /* Convert to list to an array for ReasonReact's type bindings */
    |> List.filter((post) => post.id == id)
    |> Array.of_list
    /* Map each array item to a <Card /> component */
    |> Array.map((post) => <ArticleContent key={post.title} post={post}/>)
    /* Transform the array into a valid React node, similar to ReasonReact.string */
    |> ReasonReact.array
  } */

  </div>;
};
