
open Routes
[@react.component]
let make = (~content: content) => {
    <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ()))  >
    {ReasonReact.string(content.text)}

  
    </div>;
  };
  