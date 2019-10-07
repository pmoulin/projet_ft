export default {

    /**
     * @param {int} user_one 
     * @param {int} user_two 
     * @param {*} db 
     */
    async search(user_one, user_two, db) {
        const resp = await db.query('SELECT * FROM match WHERE id_user_one=$1 AND id_user_two =$2 OR id_user_one=$2 AND id_user_two =$1',  [
        parseInt(user_one),
        parseInt(user_two)
        ]);
        return (resp[0] ? true : false)
    },

    /**
     * @param {int} user_one 
     * @param {int} user_two 
     * @param {*} db 
     */
    async create(user_one, user_two, db) {
        return await db.query('INSERT INTO match (id_user_one, id_user_two) VALUES ($1, $2)', [
        parseInt(user_one),
        parseInt(user_two)
        ])
    },

    /**
     * @param {int} user_one 
     * @param {int} user_two 
     * @param {*} db 
     */
    async remove(user_one, user_two, db) {
        console.log('remove');
        await db.query('DELETE FROM match WHERE id_user_one=$1 AND id_user_two=$2 OR id_user_one=$2 AND id_user_two=$1', [
        parseInt(user_one), 
        parseInt(user_two)
        ]);
    }
}