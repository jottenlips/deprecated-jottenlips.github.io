open Json.Decode;

type post = {
  id: string,
  file: string,
  title: string,
  tags: array(string),
};

module FetchApi = {
  let decodePosts =
    list(json =>
      {
        id: field("id", string, json),
        file: field("file", string, json),
        title: field("title", string, json),
        tags: field("tags", array(string), json),
      }
    );

  let fetchPost = (~postName: string) => {
    Js.Promise.(
      Fetch.fetchWithInit(
        "https://s3.amazonaws.com/jottenlips.github/posts/" ++ postName,
        Fetch.RequestInit.make(~method_=Get, ()),
      )
      |> then_(Fetch.Response.text)
    );
  };
  let fetchPosts = () => {
    Js.Promise.(
      Fetch.fetchWithInit(
        "https://s3.amazonaws.com/jottenlips.github/posts/posts.json",
        Fetch.RequestInit.make(~method_=Get, ()),
      )
      |> then_(Fetch.Response.json)
      |> then_(json => decodePosts(json) |> resolve)
    );
  };
};