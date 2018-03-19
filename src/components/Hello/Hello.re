module HelloQuery = [%graphql
  {|
    query getHello($name: String!) {
      hello(name: $name)
    }
|}
];

module Query = Apollo.Client.Query;

let styles =
  Css.(
    {
      "hello": [
        display(flexBox),
        flexDirection(column),
        alignItems(flexStart),
        color(hex("7d7e7f")),
        paddingLeft(rem(2.)),
        paddingRight(rem(2.)),
      ],
    }
  );

let component = ReasonReact.statelessComponent("Hello");

let make = (~name, _children) => {
  ...component,
  render: _self => {
    let helloQuery = HelloQuery.make(~name, ());
    <Fragment>
      <div className=(Css.style(styles##hello))>
        <Query query=helloQuery>
          ...(
               (response, parse) =>
                 switch (response) {
                 | Loading => <Placeholder />
                 | Failed(error) => <div> (error |> Utils.text) </div>
                 | Loaded(result) =>
                   let hello = parse(result)##hello;
                   switch (hello) {
                   | Some(n) => <h1> (n |> Utils.text) </h1>
                   | None => <h1> ("Hello World" |> Utils.text) </h1>
                   };
                 }
             )
        </Query>
      </div>
    </Fragment>;
  },
};
