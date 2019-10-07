import Users from "../Models/Users"
import Profils from "../Models/profils"
import bcrypt from "bcrypt"

const updateLocation = async ({ lat, lon, user_id, db }) => {
  if (lat && lon) {
    console.log("avant")
    await Profils.updateAtConnection({
      lat,
      lon,
      user_id,
      db
    })
    console.log("apres update")
    return true
  }
  return false
}

const connection = async ({ login, pwd, lat, lon, db }) => {
  const user = (await Users.getByLogin(login, db))[0]
  if (!user) {
    return {
      error: true,
      message: "Error login"
    }
  }
  const match = await bcrypt.compare(pwd, user.pwd)
  if (match) {
    console.log("lat | lon", lat, "|", lon)
    if (await updateLocation({ lat, lon, user_id: user.id, db })) {
      return {
        error: false,
        message: "Login in with location",
        data: user
      }
    }
    return {
      error: false,
      message: "Login in without location",
      data: user
    }
  }
  return {
    error: true,
    message: "Error login"
  }
}

export default connection