open Api;

[@react.component]
let make = (~file: string) => {
  let (article, setArticle) = React.useState(() => "");

  React.useEffect0(() => {
    FetchApi.fetchPost(file)
    |> Js.Promise.then_(results => {
         Js.log(results);
         let htmlStr = MarkyMarkdown.make(results);
         setArticle(_ => htmlStr);

         Js.Promise.resolve(results);
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
  // <ArticleContent key={post.title} post={post}/>
};