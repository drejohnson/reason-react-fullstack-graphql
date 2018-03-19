module type t = (module type of About);

let importable: (module t) = (module About);