open Types;

let typeDefs = {j|
     type Query {
       hello(name: String!): String
     }
   |j};

let resolvers: resolvers = {
  "Query": {
    "hello": (_, n) => {
      let name = n##name;
      let value = {j|Hello $name|j};
      value;
    },
  },
};

let server = Prisma.createGraphQLServer(~typeDefs, ~resolvers, ());

server
|> Prisma.start(() => Js.log("Server is running on http://localhost:4000"));
