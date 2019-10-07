export default {
  async getAll(db) {
    return await db.query("SELECT * FROM users")
  },

  async getByLogin(login, db) {
    return await db
      .query("SELECT * FROM users WHERE login=$1", login)
      
  },

  async getByEmail(email, db) {
    return await db
      .query("SELECT * FROM users WHERE email=$1", email)
      
  },

  async getById(id, db) {
    return await db.query("SELECT * FROM users WHERE id=$1", id)
  },

  async addOne({login, pwd, email, db}) {
    return await db
      .query("INSERT INTO users(login, pwd, email) VALUES ($1, $2, $3)", [
        login,
        pwd,
        email,
      ])
  },
  //id_user
  async  setSocketId(socket_id, id, db) {
    return await db.query("UPDATE users SET socket_id =$1 WHERE id=$2", [
      socket_id,
      id,
    ]);
  },
  
  async getSocketId(id, db) {
    let a = await db.query("SELECT socket_id FROM users WHERE id=$1", [
      id,
    ]);
    console.log(a[0].socket_id);
    return a[0].socket_id;
  },

  async setLocation({lati, longi, userId, db}) {
    return await db.query("UPDATE users SET lati=$1, longi=$2 WHERE id=$3", [
      lati,
      longi,
      userId
    ])
  }
}
