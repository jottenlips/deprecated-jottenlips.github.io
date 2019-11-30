
open Routes

[@react.component]
let make = (~post: post) => {
    <div style=ReactDOMRe.Style.make(~height="100%",())>
    <h2 style=(
      ReactDOMRe.Style.make(~color="#000000", ~fontSize="20pt", ())
    )>{ReasonReact.string(post.title)}</h2>
    <br/>    
    
    {
        post.content
        /* Convert to list to an array for ReasonReact's type bindings */
        |> Array.of_list
        /* Map each array item to a <Card /> component */
        |> Array.map((content) => (<TextWithFormat content={content}/>))
        /* Transform the array into a valid React node, similar to ReasonReact.string */
        |> ReasonReact.array
      }
    
    <div style=(ReactDOMRe.Style.make(~height="2px", ~width="100%", ~backgroundColor="#000000", ()))/>
</div>;
};
// let markdown = (input: string): Js.Array => {
//     input
//     |> Js.String.split("```")
// }