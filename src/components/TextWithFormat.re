open Api;
[@react.component]
let make = () => {
  <div
    style={ReactDOMRe.Style.make(
      ~padding="20px",
      ~fontSize="12pt",
      ~whiteSpace="pre-wrap",
      (),
    )}
  />;
};