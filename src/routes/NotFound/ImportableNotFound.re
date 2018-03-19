module type t = (module type of NotFound);

let importable: (module t) = (module NotFound);