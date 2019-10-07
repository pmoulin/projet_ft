export default {
    async get(id_emit, id_receive, db) {
        return await db.query("SELECT * FROM likes WHERE id_user_emit=$1 AND id_user_received=$2", [
            id_emit,
            id_receive,
        ])
    },
    
    async create(id_emit, id_receive, db) {
        return await db.query('INSERT INTO likes (id_user_emit, id_user_received) VALUES ($1, $2)', [
            id_emit,
            id_receive,
        ])
    },
    async remove(id_emit, id_receive, db) {
        return await db.query('DELETE FROM likes WHERE id_user_emit=$1 AND id_user_received=$2', [
            id_emit,
            id_receive,
        ])
    },
}