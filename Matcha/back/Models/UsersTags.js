export default {
  async getAllUserTags({ userId, db }) {
    return await db.query(
      "SELECT users_tags.id, tag_id, user_id, name FROM users_tags INNER JOIN tags ON users_tags.tag_id = tags.id WHERE users_tags.user_id = $1",
      userId
    )
  },

  async addOne({ tagId, userId, db }) {
    return await db.query(
      "INSERT INTO users_tags(tag_id, user_id) VALUES ($1, $2)",
      [tagId, userId]
    )
  },

  async deleteOne({ tagId, userId, db }) {
    return await db.query(
      "DELETE FROM users_tags WHERE tag_id = $1 AND user_id = $2",
      [tagId, userId]
    )
  },

  async findOne({ tagId, userId, db }) {
    return await db.query(
      "SELECT * FROM users_tags WHERE tag_id = $1 AND user_id = $2",
      [tagId, userId]
    )
  }
}
