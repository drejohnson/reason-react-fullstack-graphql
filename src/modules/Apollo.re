/* open ApolloLinks; */
open ApolloInMemoryCache;

type dataObject = {
  .
  "__typename": string,
  "id": string,
};

/* Create an InMemoryCache */
let inMemoryCache =
  createInMemoryCache(~dataIdFromObject=(obj: dataObject) => obj##id, ());

/* Create an HTTP Link */
let httpLink = ApolloLinks.createHttpLink(~uri="http://localhost:4000/", ());

let client =
  ReasonApollo.createApolloClient({
    "link": httpLink,
    "cache": inMemoryCache,
    "ssrMode": Js.Nullable.undefined,
    "ssrForceFetchDelay": Js.Nullable.undefined,
    "connectToDevTools": Js.Nullable.undefined,
    "queryDeduplication": Js.Nullable.undefined,
  });