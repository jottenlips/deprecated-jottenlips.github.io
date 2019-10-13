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
    <div>
        {ReasonReact.string(post.title)}
        <br/>
        <button onClick={_event => dispatch(Toggle)}>
          {ReasonReact.string("Read Article")}
        </button>
        <p>{state.show ? ReasonReact.string(post.content) : ReasonReact.null}</p>

    </div>;
};
  