import Tags from "../../Models/Tags"
import db from "../../bdd"

const getAllTags = async (req, res) => {
  const tags = await Tags.getAll({ db })
  return { error: false, tags, message: "tags gotten", status: 200 }
}

export default getAllTags
