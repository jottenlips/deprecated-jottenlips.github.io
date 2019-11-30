
open Routes
[@react.component]
let make = (~content: content) => {
    let backgroundColor= content.format == "code" ? "#EEE" : "#FFF";
    <div  style=(ReactDOMRe.Style.make(~padding="20px", ~fontSize="1vw", ~backgroundColor=backgroundColor, ~whiteSpace="pre-wrap", ()))  >
    {ReasonReact.string(content.text)}
    </div>;
  };