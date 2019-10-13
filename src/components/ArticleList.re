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
  let make = () => {
    let (_state, _dispatch) = React.useReducer((state, action) =>
    switch (action) {
    | Click => {...state, count: state.count + 1}
    | Toggle => {...state, show: ! state.show}
    }, {count: 0, show: true});
    <div>
      {
        posts
        /* Convert to list to an array for ReasonReact's type bindings */
        |> Array.of_list
        /* Map each array item to a <Card /> component */
        |> Array.map((post) => <Post post={post}/>)
        /* Transform the array into a valid React node, similar to ReasonReact.string */
        |> ReasonReact.array
      }
    </div>;
  };
  