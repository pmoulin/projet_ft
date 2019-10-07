import bcrypt from "bcrypt"
import Users from "../../Models/Users"
import Profile from "../../Models/profils"
import db from "../../bdd"

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
      message: `user and user profile created. userId: ${user_id}`,
      status: 200
    }
  }
  return {
    error: true,
    message: "error creating profile",
    status: 200
  }
}

const createUser = async ({ login, pwd, email, first_name, last_name }, db) => {
  await Users.addOne({
    login,
    pwd: bcrypt.hashSync(pwd, 10),
    email,
    db
  })
  const { id } = (await Users.getByLogin(login, db))[0]
  if (!id) {
    return { error: true, message: "error creating user", status: 200 }
  }
  return createProfile({ user_id: id, first_name, last_name, db })
}

const register = async userParams => {
  const { login, email } = userParams
  if (!isValidLogin(login, db) || !isValidEmail(email, db)) {
    return {
      error: true,
      message: "login or email already taken",
      status: 200
    }
  }
  return createUser(userParams, db)
}

export default register
