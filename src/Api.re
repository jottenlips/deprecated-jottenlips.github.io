open Json.Decode;


type content = {
    format: string,
    text: string
};

type post = {
    id: string,
    title: string,
    content: list(content)
  };

module Api = {

let decodeContent = json =>
  Json.Decode.{
    format: json |> field("format", string),
    text: json |> field("text", string)
  };

let decodePosts =
    list(
      (json =>
        {
          id: field("id", string, json),
          title: field("title", string, json),
          content: json |> field("content", list(decodeContent))
        }
      ),
    );

let fetchPosts =
  Js.Promise.(
    Fetch.fetchWithInit("https://s3.amazonaws.com/jottenlips.github/posts.json", 
    Fetch.RequestInit.make(
        ~method_=Get,
        /* ~mode="no-cors", */
        ()
      )
    )
    |> then_(Fetch.Response.json)
    |> then_(json => decodePosts(json) |> resolve)
  );
}