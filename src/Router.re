[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();
    switch (url.path) {
    | ["article", title] => Article.make(title)
    | [] => ArticleList()
    | _ => ArticleList()
    };
}
