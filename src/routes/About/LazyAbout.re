module Config = {
  module type t = (module type of About);
};

module Loadable = ReLoadable.WithRender(Config);

let make = _children =>
  Loadable.make(
    ~fetch=() => DynamicImport.import("./About.bs.js"),
    ~render=((module About)) => <About />,
    [||],
  );