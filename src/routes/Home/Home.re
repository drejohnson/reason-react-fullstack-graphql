let component = ReasonReact.statelessComponent("Home");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <title> ("ReasonReact Fullstack" |> Utils.text) </title>
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
      </ReactHelmet>
      <section>
        <ContentHeader section="ReasonReact" title="Fullstack Example" />
        <Hello name="John Snow" />
      </section>
    </Fragment>,
};
