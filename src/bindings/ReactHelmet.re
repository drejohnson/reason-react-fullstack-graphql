type base;

type bodyAttributes;

type htmlAttributes;

type link;

type meta;

type noscript;

type script;

type style;

type titleAttributes;

[@bs.deriving abstract]
type jsProps = {
  base: Js.nullable(base),
  bodyAttributes: Js.nullable(bodyAttributes),
  defaultTitle: Js.nullable(string),
  htmlAttributes: Js.nullable(htmlAttributes),
  link: Js.nullable(array(link)),
  meta: Js.nullable(array(meta)),
  noscript: Js.nullable(array(noscript)),
  script: Js.nullable(array(script)),
  style: Js.nullable(array(style)),
  title: Js.nullable(string),
  titleAttributes: Js.nullable(titleAttributes),
  titleTemplate: Js.nullable(string),
};

[@bs.module "react-helmet"] external helmet: ReasonReact.reactClass = "Helmet";

let make =
    (
      ~base=?,
      ~bodyAttributes=?,
      ~defaultTitle=?,
      ~htmlAttributes=?,
      ~link=?,
      ~meta=?,
      ~noscript=?,
      ~script=?,
      ~style=?,
      ~title=?,
      ~titleAttributes=?,
      ~titleTemplate=?,
      children,
    ) => {
  let props =
    jsProps(
      ~base=base->Js.Nullable.fromOption,
      ~bodyAttributes=bodyAttributes->Js.Nullable.fromOption,
      ~defaultTitle=defaultTitle->Js.Nullable.fromOption,
      ~htmlAttributes=htmlAttributes->Js.Nullable.fromOption,
      ~link=link->Js.Nullable.fromOption,
      ~meta=meta->Js.Nullable.fromOption,
      ~noscript=noscript->Js.Nullable.fromOption,
      ~script=script->Js.Nullable.fromOption,
      ~style=style->Js.Nullable.fromOption,
      ~title=title->Js.Nullable.fromOption,
      ~titleAttributes=titleAttributes->Js.Nullable.fromOption,
      ~titleTemplate=titleTemplate->Js.Nullable.fromOption,
    );
  ReasonReact.wrapJsForReason(~reactClass=helmet, ~props, children);
};