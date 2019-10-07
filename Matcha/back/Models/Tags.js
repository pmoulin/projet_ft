export default {
  async getAll({ db }) {
    return await db.query("SELECT * FROM tags")
  },

  async addOneSelection({ tagId, db }) {
    return await db.query(
      "UPDATE tags SET nb_selected = nb_selected + 1 WHERE id = $1",
      tagId
    )
  },

  async deleteOneSelection({ tagId, db }) {
    return await db.query(
      "UPDATE tags SET nb_selected = nb_selected - 1 WHERE id = $1",
      tagId
    )
  },

  async findOneByName({ tagName, db }) {
    return await db.query("SELECT * FROM tags WHERE name = $1", tagName)
  },

  async createOne({ tagName, db }) {
    return await db.query("INSERT INTO tags(name) VALUES ($1)", tagName)
  }
}
