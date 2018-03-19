let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <Fragment>
      <ReactHelmet>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <title> ("ReasonReact Fullstack" |> Utils.text) </title>
        /* Search Engine */
        <meta
          name="description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
        <meta name="image" content="https://example.com/images/image.png" />
        /* Twitter */
        <meta name="twitter:card" content="summary" />
        <meta name="twitter:title" content="ReasonReact Fullstack" />
        <meta
          name="twitter:description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
        <meta name="twitter:site" content="@twitterHandle" />
        <meta name="twitter:creator" content="@twitterHandle" />
        <meta
          name="twitter:image:src"
          content="https://example.com/images/image.png"
        />
        /* Open Graph general (Facebook, Pinterest & Google+) */
        <meta name="og:title" content="ReasonReact Fullstack" />
        <meta
          name="og:description"
          content="Reason lets you write simple, fast and quality type safe code while leveraging both the JavaScript & OCaml ecosystems."
        />
        <meta
          name="og:image"
          content="https://example.com/images/preview.png"
        />
        <meta name="og:url" content="https://example.com" />
        <meta name="og:site_name" content="ReasonReact Fullstack" />
        <meta name="og:locale" content="en_US" />
        <meta name="og:type" content="website" />
        /* PWA Specific */
        <meta name="theme-color" content="#000000" />
        <link rel="manifest" href="/manifest.json" />
        <link rel="shortcut icon" href="/favicon.ico" />
      </ReactHelmet>
      <Layout>
        <Routes.Container>
          ...(
               (~currentRoute) =>
                 switch (currentRoute) {
                 | Home => <Home />
                 | About => <About />
                 | _ => <NotFound />
                 }
             )
        </Routes.Container>
      </Layout>
    </Fragment>,
};
