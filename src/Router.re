module Config = {
  /** Declare routes. */
  type route =
    | Home
    | About
    | NotFound;
  /** URL -> Route. */
  let routeFromUrl = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | [] => Home
    | ["about"] => About
    | _ => NotFound
    };
  /** Route -> URL. */
  let routeToUrl = (route: route) =>
    switch (route) {
    | Home => "/"
    | About => "/about"
    | NotFound => ""
    };
};

include ReRoute.CreateRouter(Config);