export default {
    async create_user(user, db) {
        return await db.query("INSERT INTO users(login, pwd, email, active) VALUES ($1, $2, $3, $4)", [
            user.login,
            user.pwd,
            user.email,
            user.active
        ])
    },

    async create_profile(profile, db) {
        return await db.query("INSERT INTO profils(user_id, genre, orientation, bio, first_name, last_name, birthday, lat, lon) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)", [
            profile.user_id,
            profile.genre,
            profile.orientation,
            profile.bio,
            profile.first_name,
            profile.last_name,
            profile.birthday,
            profile.lat,
            profile.lon,
        ])
    },
    async count_tag(db) {
        let tmp =  await db.query('SELECT COUNT(*) FROM tags');
        return tmp[0].count;
    }
}
    