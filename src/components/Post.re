open Routes
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
    let height = state.show ? "100vw" : "100%";
    <div style=ReactDOMRe.Style.make(~height=height,())>
        <h2 style=(
          ReactDOMRe.Style.make(~color="#000000", ~fontSize="24px", ())
        )>{ReasonReact.string(post.title)}</h2>
        <br/>
        <button onClick={_event => dispatch(Toggle)}>
          <h3 style=(
            ReactDOMRe.Style.make(~color="#000000", ~fontSize="18px", ())
          )>{!state.show ? ReasonReact.string("Read Article >") : ReasonReact.string("Hide Article v")  }</h3>
        </button>
        <p style=(
          ReactDOMRe.Style.make(~color="#000000", ~fontSize="16px", ())
        )>{state.show ? ReasonReact.string(post.content) : ReasonReact.null}</p>

    </div>;
};
  