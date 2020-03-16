open Api;

[@react.component]
let make =
    (~id: string, ~getFileName: (~id: string, ~posts: list(post)) => string) => {
  let (article, setArticle) = React.useState(() => "");

  React.useEffect0(() => {
    FetchApi.fetchPosts()
    |> Js.Promise.then_(allPosts => {
         let file = getFileName(id, allPosts);
         FetchApi.fetchPost(file)
         |> Js.Promise.then_(results => {
              let htmlStr = MarkyMarkdown.make(results);
              setArticle(_ => htmlStr);
              Js.Promise.resolve(results);
            });
         Js.Promise.resolve(allPosts);
       });
    None;
  });

  <div style={ReactDOMRe.Style.make(~padding="20px", ~flex="1", ())}>
    <button
      onClick={_event => ReasonReactRouter.push("/")}
      style={ReactDOMRe.Style.make(~color="#000000", ())}>
      {ReasonReact.string("< Back")}
      <br />
    </button>
    <div dangerouslySetInnerHTML={"__html": article} />
  </div>;
};