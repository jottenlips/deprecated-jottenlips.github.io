
open Routes
[@react.component]
let make = (~content: content) => {
    let backgroundColor= content.format == "code" ? "#EEE" : "#FFF";
    <div  style=(ReactDOMRe.Style.make(~padding="20px", ~flex="1", ~backgroundColor=backgroundColor, ~whiteSpace="pre-wrap", ()))  >
    {ReasonReact.string(content.text)}
    </div>;
  };
  

//   style=(
    //     ReactDOMRe.Style.make(~color="#000000", ~backgroundColor="#EEEEEE" ~fontSize="16px",  ~whiteSpace="pre-wrap", ())
    //   )>