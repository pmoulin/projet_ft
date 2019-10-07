export default {
    /**
     * user_id2 is bloquer by user_id1 ?
     */

    async search(db, id_user1, id_user2) {
        const res = await db.query('SELECT * FROM user_blocked WHERE id_user=$1 AND id_user_blocked=$2', [
            id_user1,
            id_user2,
        ]);
        return (res[0] ? true : false);
    },
    /**
     * blocke user
     */
    async create(db, id_user, id_user_blocked) {
        return await db.query('INSERT INTO user_blocked (id_user, id_user_blocked) VALUES ($1, $2)',[
            id_user,
            id_user_blocked
        ]);
    },
    /**
     * deBlock user
     */
    async remove(db, id_user, id_user_blocked) {
        return await db.query('DELETE FROM user_blocked WHERE id_user=$1 AND id_user_blocked=$2', [
            id_user,
            id_user_blocked,
        ]);
    }
}