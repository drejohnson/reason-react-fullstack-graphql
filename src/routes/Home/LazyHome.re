module Component =
  ReLoadable.Create(
    {
      module type t = ImportableHome.t;
    },
  );

let make = _children =>
  Component.make(
    ~fetch=() => DynamicImport.import("./ImportableHome.bs"),
    ~onLoading=() => <Placeholder />,
    ~onFail=err => <div> (err |> Utils.text) </div>,
    ~render=((module LoadedComponent)) => <LoadedComponent />,
    [||],
  );