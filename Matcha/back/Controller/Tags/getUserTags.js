import UsersTags from "../../Models/UsersTags"
import db from "../../bdd"

const getUserTags = async ({ session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 401 }
  }
  const tags = await UsersTags.getAllUserTags({ userId, db })
  return { error: false, message: "userTags well gotten", tags, status: 200 }
}

export default getUserTags
