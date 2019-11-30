open Api
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
    let (state, dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Click => {...state, count: state.count + 1}
    | Toggle => {...state, show: !state.show}
    }, {count: 0, show: false});
    let content = List.hd(post.content)
    let text = content.text;
    let length = String.length(text)
    let overFifty = length > 50
    let cutoffLength = overFifty ? 50 : length
    let cutoffPost = String.sub(text, 0, cutoffLength) ++"..."
    let height = "50";
    <div style=ReactDOMRe.Style.make(~height=height, ~padding="50", ())>
        <h2 style=(
          ReactDOMRe.Style.make(~color="#000000", ())
        )>{ReasonReact.string(post.title)}</h2>
        <br/>
        <button style=ReactDOMRe.Style.make(~color="#000000", () ) 
          onClick={_event => ReasonReactRouter.push("/post/"++post.id)}>
          {ReasonReact.string("Read Article >")}
        </button>
        <br/>
        <button style=ReactDOMRe.Style.make(~color="#000000", () ) 
          onClick={_event => dispatch(Toggle)}>
          {!state.show ? ReasonReact.string("Preview >") : ReasonReact.string("Preview v")  }
        </button>
        <p style=(
          ReactDOMRe.Style.make(~color="#000000", ~fontSize="16pt", ())
        )>{state.show ? ReasonReact.string(cutoffPost) : ReasonReact.null}</p>
        <div style=(ReactDOMRe.Style.make(~height="2px", ~width="100%", ~backgroundColor="#000000", ()))/>
    </div>;
};
  