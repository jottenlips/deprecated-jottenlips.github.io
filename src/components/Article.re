
[@react.component]
let make = (~title) => {
  <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
  {ReasonReact.string("Article"++title)}
  </div>;
};
