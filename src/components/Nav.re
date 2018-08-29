let nav =
  Css.[
    display(flexBox),
    flexDirection(row),
    alignItems(center),
    justifyContent(spaceBetween),
  ];

let navlink =
  Css.[
    borderLeft(px(1), solid, hex("38393a")),
    marginLeft(rem(0.75)),
    paddingLeft(rem(0.75)),
  ];

let noBorder = Css.[borderLeft(zero, none, transparent)];

let component = ReasonReact.statelessComponent("Nav");

let make = _children => {
  ...component,
  render: _self =>
    <nav className={Css.style(nav)}>
      <Router.Link
        route=Home
        className=Css.(
          style([borderLeft(zero, none, transparent), ...navlink])
        )>
        {"Home" |> Utils.text}
      </Router.Link>
      <Router.Link route=About className={Css.style(navlink)}>
        {"About" |> Utils.text}
      </Router.Link>
    </nav>,
};