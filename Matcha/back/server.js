import express from "express"
import cors from "cors"
import cookieParser from "cookie-parser"
import session from "express-session"
import fileUpload from "express-fileupload"
import io from 'Socket.io'
import db from './bdd'

import Users from './models/Users'
var bodyParser = require("body-parser")
let app = express()
  
const server = app.listen(3000, () => console.log("Example app listening on port 3000!"))

app.io = require('socket.io')(server);
//Set db
app.db = db;

app.use(fileUpload())

app.use(cookieParser())
app.use(
  session({
    secret: "Shh, its a secret!",
    resave: false,
    saveUninitialized: true
  })
)

app.use(
  cors({
    origin: "http://localhost:8080",
    credentials: true
  })
)

app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())
app.io.on('connection', (socket) => {
  socket.on('first', async (id_user) => {
    if (id_user !== -1){
      console.log('first, define socketid id user = >', id_user, socket.id)
      await Users.setSocketId(socket.id, id_user, db);
    }
  });
console.log('serveur ++ ', socket.id);

});
require("./routes")(app, io)

