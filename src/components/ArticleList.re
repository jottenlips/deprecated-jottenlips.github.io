open Api;

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
    {ReasonReact.string("Hi! My name is John, ")}
    <br />
    <br />
    {ReasonReact.string(
       "Welcome to my blog. I am a musician and software developer living in Nashville TN. For more info check out my first post.",
     )}
    <br />
    <br />
    <input
      placeholder="Search"
      onChange={event => {
        let value = ReactEvent.Form.target(event)##value;
        onChange(value);
      }}
      value
    />
    {posts
     |> List.filter(post =>
          Js.String.startsWith(
            String.lowercase(value),
            String.lowercase(post.title),
          )
        )
     /* Convert to list to an array for ReasonReact's type bindings */
     |> Array.of_list
     /* Map each array item to a <Card /> component */
     |> Array.map(post => <Post key={post.file} post />)
     /* Transform the array into a valid React node, similar to ReasonReact.string */
     |> ReasonReact.array}
  </div>;
};