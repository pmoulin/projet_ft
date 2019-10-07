import UserTags from "../../Models/UsersTags"
import Tags from "../../Models/Tags"
import db from "../../bdd"

const deleteTag = async ({ body, session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 401 }
  }
  const { tagId } = body
  await UserTags.deleteOne({ tagId, userId, db })
  await Tags.deleteOneSelection({ tagId, db })
  return { error: false, message: "tag well deleted", status: 200 }
}

export default deleteTag
