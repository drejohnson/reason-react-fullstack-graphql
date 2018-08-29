module CSSTransition = {
  [@bs.deriving abstract]
  type jsProps = {
    key: Js.nullable(string),
    [@bs.as "in"]
    in_: Js.nullable(bool),
    timeout: Js.nullable(int),
    classNames: Js.nullable(string),
  };
  [@bs.module "react-transition-group"]
  external reactClass: ReasonReact.reactClass = "CSSTransition";
  let make = (~key=?, ~in_=?, ~timeout=?, ~classNames=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        jsProps(
          ~key=key->Js.Nullable.fromOption,
          ~in_=in_->Js.Nullable.fromOption,
          ~timeout=timeout->Js.Nullable.fromOption,
          ~classNames=classNames->Js.Nullable.fromOption,
        ),
      children,
    );
};

module TransitionGroup = {
  [@bs.deriving abstract]
  type jsProps = {component: Js.nullable(Js.null(Dom.htmlElement))};
  [@bs.module "react-transition-group"]
  external reactClass: ReasonReact.reactClass = "TransitionGroup";
  let make = (~component=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=jsProps(~component=component->Js.Nullable.fromOption),
      children,
    );
};