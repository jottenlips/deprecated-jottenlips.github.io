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
              Js.log(htmlStr);
              Js.Promise.resolve(results);
            });
         Js.Promise.resolve(allPosts);
       });
    None;
  });

  <div style={ReactDOMRe.Style.make(~padding="20px", ~flex="1", ())}>
    <button onClick={_event => ReasonReactRouter.push("/")}>
      {ReasonReact.string("< Back")}
      <br />
    </button>
    <div
      style={ReactDOMRe.Style.make(
        ~alignItems="center",
        ~justifyContent="center",
        ~marginLeft="auto",
        ~marginRight="auto",
        ~width="50%",
        ~minWidth="300px",
        (),
      )}>
      <div dangerouslySetInnerHTML={"__html": article} />
    </div>
  </div>;
};