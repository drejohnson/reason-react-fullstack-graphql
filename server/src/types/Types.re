type t;

type schema;

type db;

type request;

type parent;

type info;

type context = {
  .
  "db": db,
  "request": request,
};

type resolvers = {
  .
  "Query": {. "hello": (parent, {. "name": string}) => string},
};
