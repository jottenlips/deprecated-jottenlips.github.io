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
    let (_state, _dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Click => {...state, count: state.count + 1}
    | Toggle => {...state, show: ! state.show}
    }, {count: 0, show: true});

    <div>
        {ReasonReact.string(post.title)}
        {ReasonReact.string(post.content)}

    </div>;
  };
  