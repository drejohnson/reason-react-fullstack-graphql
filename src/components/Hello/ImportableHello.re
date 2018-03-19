module type t = (module type of Hello);

let importable: (module t) = (module Hello);