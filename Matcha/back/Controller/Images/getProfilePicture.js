import Profiles from "../../Models/profils"
import db from "../../bdd"

const getProfilePicture = async ({ session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 400 }
  }

  const profilePicture = await Profiles.getProfilePricture({ userId, db })
  return {
    error: false,
    message: "profilePicture got",
    status: 200,
    profilePicture
  }
}

export default getProfilePicture
