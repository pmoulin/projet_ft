export default  {
    async create(db, id_user, type, message) {
        return await db.query('INSERT INTO notif (id_user, type, message) VALUES ($1, $2, $3)', [
            id_user,
            type,
            message
        ]);
    },
    async update(db, id_user, type, message, id) {
        return await db.query('UPDATE notif SET id_user=$1, type=$2, message=$3) WHERE id=$4', [
            id_user,
            type,
            message,
            id
        ]);
        //??
    },
    async delete(db, id = null, id_user = null) {
        return await db.query('DELETE FROM notif WHERE id=$1 OR id_user=2', [
            id,
            id_user
        ]);
    }
}