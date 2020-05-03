open Api;
/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Click
  | Toggle;

[@react.component]
let make = (~post: post) => {
  let height = "50";
  <div style={ReactDOMRe.Style.make(~height, ~padding="50", ())}>
    <h2 style={ReactDOMRe.Style.make(~color="#000000", ())}>
      {ReasonReact.string(post.title)}
    </h2>
    <br />
    <button onClick={_event => ReasonReactRouter.push("?" ++ post.id)}>
      <Emoji emoji={j|📖|j} />
      {ReasonReact.string("Read >")}
    </button>
    <br />
    <p
      style={ReactDOMRe.Style.make(~color="#000000", ~fontSize="16pt", ())}
    />
    <div
      style={ReactDOMRe.Style.make(
        ~height="2px",
        ~width="100%",
        ~backgroundColor="#000000",
        (),
      )}
    />
  </div>;
};