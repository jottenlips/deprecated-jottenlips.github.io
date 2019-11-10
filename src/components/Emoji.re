[@react.component]
let make = (~emoji: string) => {
    <span role="img" ariaHidden=true> {React.string({j| $emoji |j})} </span>
};

