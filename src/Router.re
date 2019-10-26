[@react.component]
let make = () => {
    let url = ReasonReactRouter.useUrl();
    switch (url.path) {
    | ["post", id] => (<Article id={id}/>)
    | [] => (<ArticleList/>)
    | _ => (<ArticleList/>)
    };
}
