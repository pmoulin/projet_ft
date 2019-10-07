import Tags from "../../Models/Tags"
import UsersTags from "../../Models/UsersTags"
import db from "../../bdd"

const selectTag = async ({ tagId, userId, db }) => {
  await UsersTags.addOne({ tagId, userId, db })
  await Tags.addOneSelection({ tagId, db })
}

const updateTag = async ({ tag, userId, db }) => {
  const { id, name } = tag
  if ((await UsersTags.findOne({ tagId: id, userId, db }))[0]) {
    return { error: true, message: "user already has this tag", status: 200 }
  }
  await selectTag({ tagId: id, userId, db })
  return { error: false, message: `${name} tag update`, status: 200 }
}

const createTag = async ({ tagName, userId, db }) => {
  await Tags.createOne({ tagName, db })
  const tag = (await Tags.findOneByName({ tagName, db }))[0]
  if (!tag) {
    return { error: true, message: `${tagname} tag not created`, status: 200 }
  }
  await selectTag({ tagId: tag.id, userId, db })
  return { error: false, message: `${tagName} tag created`, status: 200 }
}

const addTag = async ({ body, session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 401 }
  }
  const { tagName } = body
  const tag = (await Tags.findOneByName({ tagName, db }))[0]
  if (tag) {
    return await updateTag({ tag, userId, db })
  }
  return await createTag({ tagName, userId, db })
}

export default addTag
