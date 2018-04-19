module Config = {
  module type t = (module type of NotFound);
};

module Loadable = ReLoadable.WithRender(Config);

let make = _children =>
  Loadable.make(
    ~fetch=() => DynamicImport.import("./NotFound.bs.js"),
    ~render=((module NotFound)) => <NotFound />,
    [||],
  );