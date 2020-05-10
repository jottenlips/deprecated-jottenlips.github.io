open Api;

module StringCmp =
  Belt.Id.MakeComparable({
    type t = string;
    let cmp = Pervasives.compare;
  });

[@react.component]
let make = (~posts: list(post)) => {
  let (value, onChange) = React.useState(() => "");
  <div
    style={ReactDOMRe.Style.make(
      ~padding="20px",
      ~flex="1",
      ~fontSize="18px",
      (),
    )}>
    <Emoji emoji={j|✨|j} />
    <h3> {ReasonReact.string("Hi! My name is John, ")} </h3>
    <br />
    <h3 style={ReactDOMRe.Style.make(~width="90%", ())}>
      {ReasonReact.string(
         "Welcome to my blog. I am a musician and software developer living in Nashville TN. For more info check out my first post.",
       )}
    </h3>
    <br />
    <input
      placeholder="Search"
      style={ReactDOMRe.Style.make(
        ~padding="10px",
        ~flex="1",
        ~fontSize="18px",
        ~background="#000000",
        ~color="#ffffff",
        ~borderRadius="6px",
        ~borderColor="#ff00ff",
        ~width="200px",
        (),
      )}
      onChange={event => {
        let value = ReactEvent.Form.target(event)##value;
        onChange(value);
      }}
      value
    />
    <br />
    <button onClick={_event => onChange(_ => "")}>
      {ReasonReact.string("clear")}
    </button>
    <br />
    {posts
     /* Convert to list to an array for ReasonReact's type bindings */
     |> List.map(post => post.tags |> Array.to_list)
     |> List.flatten
     |> Array.of_list
     |> Belt.Set.fromArray(~id=(module StringCmp))
     |> Belt.Set.toArray
     /* Map each array item to a <Card /> component */
     |> Array.map(tag =>
          <button onClick={_event => onChange(_ => tag)}>
            {ReasonReact.string("#" ++ tag)}
          </button>
        )
     //  onclick={() => onChange(tag)}
     |> ReasonReact.array} /* Transform the array into a valid React node, similar to ReasonReact.string */
    {posts
     |> List.filter(post =>
          Js.String.includes(
            String.lowercase(value),
            String.lowercase(post.title),
          )
          || Js.Array.(post.tags |> includes(String.lowercase(value)))
        )
     /* Convert to list to an array for ReasonReact's type bindings */
     |> Array.of_list
     /* Map each array item to a <Card /> component */
     |> Array.map(post => <Post key={post.file} post />)
     /* Transform the array into a valid React node, similar to ReasonReact.string */
     |> ReasonReact.array}
  </div>;
};