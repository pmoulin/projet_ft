export default {

    /**
     *  Get "nb" id_profile_visitor de mon profile | de la plus recente a la plus ancienne
     * @param {int} id_user 
     * @param {int} nb 
     * @param {*} db 
     */
    async get_visitor(id_user, nb, db) {
        return await db.query('SELECT id_user_visitor, MAX(created_at) FROM views WHERE id_user_viewed = $1 GROUP BY id_user_visitor ORDER BY MAX(created_at) DESC', [
            parseInt(id_user),
        ])
    },
    /**
     *    Get id profile que j'ai visiter (du plus recent au plus vieux)
    */
    async get_viewed(id_user, nb, db) {
        // SELECT id_user_visitor, MAX(created_at) FROM views GROUP BY id_user_visitor
        return await db.query('SELECT id_user_viewed, MAX(created_at) FROM views WHERE id_user_visitor = $1 GROUP BY id_user_viewed ORDER BY MAX(created_at) DESC', [
            parseInt(id_user),
        ])
    },

    async create(id_visitor, id_viewed, db) {
        console.log(id_visitor, id_viewed);

        return await db.query('INSERT INTO views(id_user_visitor, id_user_viewed) VALUES ($1, $2)', [
        parseInt(id_visitor),
        parseInt(id_viewed) 
        ]);
    }

}