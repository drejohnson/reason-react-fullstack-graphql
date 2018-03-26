type t;

type schema;

type connection;

type db;

type request;

type parent;

type info;

type resolvers = {
  .
  "Query": {. "hello": (parent, {. "name": string}) => string},
};
