
open Routes
[@react.component]
let make = (~post: post) => {
    <div style=ReactDOMRe.Style.make(~height="100%",())>
    <h2 style=(
      ReactDOMRe.Style.make(~color="#000000", ~fontSize="24px", ())
    )>{ReasonReact.string(post.title)}</h2>
    <br/>    
    <p style=(
      ReactDOMRe.Style.make(~color="#000000", ~fontSize="16px", ())
    )>{ReasonReact.string(post.content)}</p>
    <div style=(ReactDOMRe.Style.make(~height="2px", ~width="100%", ~backgroundColor="#000000", ()))/>
</div>;
};