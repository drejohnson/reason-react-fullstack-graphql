[@bs.val] external window : Dom.window = "window";

[@bs.val] external requireAssetURI : string => string = "require";

[@bs.val] external parseInt : (string, int) => int = "";

let parseInt_ = (int, string) => parseInt(string, int);

/* Copied from Vrroom */
module Text = {
  let string = ReasonReact.string;
  let int = n => n |> string_of_int |> string;
  let float = f => f |> string_of_float |> string;
  let any = v => v |> Js.String.make |> string;
};

let text = Text.string;

/* Array to List helper */
let list = list => list |> Belt.List.toArray |> ReasonReact.array;

/* Array to Element helper */
let array = array => array |> ReasonReact.array;