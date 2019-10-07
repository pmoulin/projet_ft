import bcrypt from "bcrypt"
import Users from "../Models/Users"
import Profile from "../Models/profils"

const isValidLogin = async (login, db) => {
  if (!login) return false
  if ((await Users.getByLogin(login, db))[0]) return false
  return true
}

const isValidEmail = async (email, db) => {
  if (!email) return false
  if ((await Users.getByEmail(email, db))[0]) return false
  return true
}

const createProfile = async ({ user_id, first_name, last_name, db }) => {
  if (user_id) {
    await Profile.create({ first_name, last_name, user_id, db })
    return {
      error: false,
      message: "User created"
    }
  }
  return {
    error: true,
    message: "Error creating profile"
  }
}

const register = async ({ login, pwd, email, first_name, last_name, db }) => {
  if (!isValidLogin(login, db) || !isValidEmail(email, db)) {
    return {
      error: true,
      message: "Login or email already taken"
    }
  }
  await Users.addOne({
    login,
    pwd: bcrypt.hashSync(pwd, 10),
    email,
    db
  })
  const { id } = (await Users.getByLogin(login, db))[0]
  console.log("[id] =>>> ", id)
  return createProfile({ user_id: id, first_name, last_name, db })
}

export default register