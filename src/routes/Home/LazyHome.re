module Config = {
  module type t = (module type of Home);
};

module Loadable = ReLoadable.WithRender(Config);

let make = _children =>
  Loadable.make(
    ~fetch=() => DynamicImport.import("./Home.bs.js"),
    ~render=((module Home)) => <Home />,
    [||],
  );