Css.(
  global("html", [backgroundColor(hex("262728")), minHeight(vh(100.))]),
  global("body", [backgroundColor(hex("262728")), color(hex("aaabac"))]),
  global("a, a:hover", [color(currentColor), textDecoration(none)]),
  global("a:active, a:hover", [outline(zero, none, transparent)]),
  global("button:focus", [outline(zero, none, transparent)]),
  global(
    "icon",
    [display(inlineBlock), width(rem(1.)), height(rem(1.))],
  ),
);

module AppContainer = {
  [@bs.module "react-hot-loader"]
  external appContainer : ReasonReact.reactClass = "AppContainer";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=appContainer,
      ~props=Js.Obj.empty(),
      children,
    );
};

ReactDOMRe.renderToElementWithId(
  <ReasonApollo.Provider client=Apollo.client>
    <App />
  </ReasonApollo.Provider>,
  "root",
);

[@bs.val] external hot : bool = "module.hot";

[@bs.val] external accept : unit => unit = "module.hot.accept";

if (hot) {
  accept();
};