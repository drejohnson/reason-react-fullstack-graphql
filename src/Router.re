module Config = {
  type route =
    | Home
    | About
    | NotFound;
  let routeFromUrl = (url: ReasonReact.Router.url) =>
    switch (url.path) {
    | [] => Home
    | ["about"] => About
    | _ => NotFound
    };
  let routeToUrl = (route: route) =>
    switch (route) {
    | Home => "/"
    | About => "/about"
    | NotFound => ""
    };
  let routeToTitle = route =>
    switch (route) {
    | Home => "Home"
    | About => "About"
    | NotFound => "Not Found"
    };
};

module WithRouter = {
  type action =
    | ChangeRoute(Config.route);
  type state = Config.route;

  let component = ReasonReact.reducerComponent("withRouter");
  let make = children => {
    ...component,
    initialState: () =>
      ReasonReact.Router.dangerouslyGetInitialUrl() |> Config.routeFromUrl,
    reducer: (action, _state) =>
      switch (action) {
      | ChangeRoute(route) => ReasonReact.Update(route)
      },
    didMount: self => {
      let watcherId =
        ReasonReact.Router.watchUrl(url =>
          self.send(ChangeRoute(url |> Config.routeFromUrl))
        );
      self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
    },
    render: self => children(~currentRoute=self.state),
  };
};

module Link = {
  let component = ReasonReact.statelessComponent("Link");
  let make = (~route, ~className, children) => {
    ...component,
    render: self => {
      let href = Config.routeToUrl(route);
      <a
        href
        className
        onClick={
          self.handle((event, _self) => {
            ReactEvent.Synthetic.preventDefault(event);
            ReasonReact.Router.push(href);
          })
        }>
        ...children
      </a>;
    },
  };
};