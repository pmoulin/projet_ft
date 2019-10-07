import addTag from "./Tags/addTag"
import getAllTags from "./Tags/getAllTags"
import getUserTags from "./Tags/getUserTags"
import deleteTag from "./Tags/deleteTag"

export default {
  async addTag(req, res) {
    const result = await addTag(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async getAllTags(req, res) {
    const result = await getAllTags()
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async getUserTags(req, res) {
    const result = await getUserTags(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async deleteTag(req, res) {
    const result = await deleteTag(req)
    console.log(result.message)
    res.send(result).status(result.status)
  }
}
