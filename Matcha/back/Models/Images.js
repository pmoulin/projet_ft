export default {
  async findOne({ path, db }) {
    return (await db.query("SELECT * FROM images WHERE path=$1", path))[0]
  },

  async findByUser({ userId, db }) {
    return await db.query("SELECT * FROM images WHERE user_id=$1", userId)
  },

  async addOne({ path, userId, db }) {
    return await db.query("INSERT INTO images(path, user_id) VALUES ($1, $2)", [
      path,
      userId
    ])
  },

  async deleteById({ imageId, db }) {
    return await db.query("DELETE FROM images WHERE id=$1", imageId)
  }
}
