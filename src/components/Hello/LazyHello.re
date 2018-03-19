module Component =
  ReLoadable.Create(
    {
      module type t = ImportableHello.t;
    },
  );

let make = (~name, _children) =>
  Component.make(
    ~fetch=() => DynamicImport.import("./ImportableHello.bs"),
    ~onLoading=() => <Placeholder />,
    ~onFail=err => <div> (err |> Utils.text) </div>,
    ~render=((module LoadedComponent)) => <LoadedComponent name />,
    [||],
  );
