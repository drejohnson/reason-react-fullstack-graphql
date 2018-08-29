type fragmentReplacements;

[@bs.deriving abstract]
type prismaProps = {
  fragmentReplacements: Js.nullable(fragmentReplacements),
  typeDefs: Js.nullable(string),
  endpoint: Js.nullable(string),
  secret: Js.nullable(string),
  debug: Js.nullable(bool),
};

[@bs.module "prisma-binding"] [@bs.new]
external makePrisma: prismaProps => 'a = "Prisma";

let createPrisma =
    (
      ~fragmentReplacements=?,
      ~typeDefs=?,
      ~endpoint=?,
      ~secret=?,
      ~debug=?,
      (),
    ) => {
  let prismaOptions =
    prismaProps(
      ~fragmentReplacements=Js.Nullable.fromOption(fragmentReplacements),
      ~typeDefs=Js.Nullable.fromOption(typeDefs),
      ~endpoint=Js.Nullable.fromOption(endpoint),
      ~secret=Js.Nullable.fromOption(secret),
      ~debug=Js.Nullable.fromOption(debug),
    );
  makePrisma(prismaOptions);
};