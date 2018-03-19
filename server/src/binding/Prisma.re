open Types;

type serverOptions = {
  .
  "typeDefs": Js.Nullable.t(string),
  "resolvers": Js.Nullable.t(resolvers),
  "schema": Js.Nullable.t(schema),
  "context": Js.Nullable.t(context),
};

[@bs.module "graphql-yoga"] [@bs.new]
external makeGraphQLServer : serverOptions => 'a = "GraphQLServer";

[@bs.send.pipe: 'a] external start : 'a => 'a = "";

let createGraphQLServer =
    (~typeDefs=?, ~resolvers=?, ~schema=?, ~context=?, ()) => {
  let graphQLServerOptions = {
    "typeDefs": Js.Nullable.fromOption(typeDefs),
    "resolvers": Js.Nullable.fromOption(resolvers),
    "schema": Js.Nullable.fromOption(schema),
    "context": Js.Nullable.fromOption(context),
  };
  makeGraphQLServer(graphQLServerOptions);
};

let graphQLServer = createGraphQLServer(~typeDefs="./src/schema.graphql", ());
