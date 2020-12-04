const { parse } = require("path");
const path = require("path");
const blogAddon = require("./build/Release/BlogParser.node");

const parseFile = (filepath) => {
  //   console.log(path.resolve(filepath));
  const res = blogAddon.getJson(Date.now(), path.resolve(filepath));
  return res;
};

// console.log(JSON.parse(parseFile("./sample.txt")));

module.exports = parseFile;
