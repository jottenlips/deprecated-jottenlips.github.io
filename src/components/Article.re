open Api

[@react.component]
let make = (~post: post) => {
  <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
  <button onClick={_event => ReasonReactRouter.push("/")} style=(
    ReactDOMRe.Style.make(~color="#000000", ())
  )>
  {ReasonReact.string("< Back")}
  <br/>
  </button>
  <ArticleContent key={post.title} post={post}/>
  </div>;
};
