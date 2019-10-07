import promise from "bluebird"
// import getAllPuppies from "./exempleConnectMysql"

var options = {
    // Initialization Options
    promiseLib: promise
  };
  var pgp = require('pg-promise')(options);

  var connectionString = 'postgres://matcha:123456789@51.38.187.177:5432/matcha'
  const db = pgp(connectionString);
  // db.connect();
  // add query functions
  // You are connected to database "matcha" as user "phmoulin" via socket in "/var/run/postgresql" at port "5432".
export default db;