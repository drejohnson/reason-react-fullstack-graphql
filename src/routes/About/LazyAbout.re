module Component =
  ReLoadable.Create(
    {
      module type t = ImportableAbout.t;
    },
  );

let make = _children =>
  Component.make(
    ~fetch=() => DynamicImport.import("./ImportableAbout.bs"),
    ~onLoading=() => <Placeholder />,
    ~onFail=err => <div> (err |> Utils.text) </div>,
    ~render=((module LoadedComponent)) => <LoadedComponent />,
    [||],
  );