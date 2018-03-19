module Component =
  ReLoadable.Create(
    {
      module type t = ImportableNotFound.t;
    },
  );

let make = _children =>
  Component.make(
    ~fetch=() => DynamicImport.import("./ImportableNotFound.bs"),
    ~onLoading=() => <Placeholder />,
    ~onFail=err => <div> (err |> Utils.text) </div>,
    ~render=((module LoadedComponent)) => <LoadedComponent />,
    [||],
  );