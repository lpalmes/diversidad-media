const express = require('express');
const {readFileSync} = require("fs");
const path = require("path");
const loaders = require("../../graph/loaders");
const resolvers = require("../../graph/resolvers");
const {makeExecutableSchema} = require("graphql-tools");
const {graphqlExpress, graphiqlExpress} = require("graphql-server-express");
const typeDefs = readFileSync(path.resolve(__dirname, "../../graph/typeDefs.graphql"), "utf8");

const router = express.Router();

const schema = makeExecutableSchema({typeDefs, resolvers});

router.use("/graph", graphqlExpress(res =>({
  context: {loaders},
  schema
})));

router.use("/iql", graphiqlExpress({endpointURL: '/graph'}));

module.exports = router;