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

module Client =
  ReasonApollo.CreateClient(
    {
      let apolloClient =
        ReasonApollo.createApolloClient(
          ~cache=inMemoryCache,
          ~link=httpLink,
          (),
        );
    },
  );
