import Users from "../../Models/Users"
import Profils from "../../Models/profils"
import geolocation from "./geolocation.js"
import db from "../../bdd"
import bcrypt from "bcrypt"

const updateLocation = async ({ lat, lon, user_id, db }) => {
  await Profils.updateAtConnection({
    lat,
    lon,
    user_id,
    db
  })
}

const getPosition = async () => {
  const geoloc = new geolocation()
  return await geoloc.getPos(await geoloc.getIp())
}

const getUser = async ({ login, pwd, db }) => {
  const user = (await Users.getByLogin(login, db))[0]
  if (!user) {
    return {
      error: true,
      message: "user doesn't exist"
    }
  }
  if (await bcrypt.compare(pwd, user.pwd)) {
    return {
      error: false,
      message: "user exists and passwords match",
      user
    }
  }
  return {
    error: true,
    message: "user exists but passwords dont match"
  }
}

const connectUser = async ({ user_id, lat, lon, session, db }) => {
  await updateLocation({ lat, lon, user_id, db })
  session.idUsers = user_id
  return {
    error: false,
    message: `user connected with location: lat: ${lat} and lon: ${lon}`,
    connected: true,
    status: 200
  }
}

const connection = async ({ body: { login, pwd, pos }, session }) => {
  const { lat, lon } = pos ? pos : await getPosition()

  if (session.idUsers) {
    return {
      error: true,
      message: "user already connected",
      connected: true,
      status: 200
    }
  }

  const userGot = await getUser({ login, pwd, db })

  if (userGot.error) return userGot

  return await connectUser({ user_id: userGot.user.id, lat, lon, session, db })
}

export default connection
