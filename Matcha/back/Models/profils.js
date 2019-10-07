export default {
  async findById(id, db) {
    return (await db.query("SELECT * from profils WHERE user_id=$1", [id]))[0]
  },

    async findById(id, db) {
        const resp = await db.query("SELECT * from profils WHERE user_id=$1", [
            id
        ])
        return resp[0];
    },
/**
    *  ORIEN : 0 = femme, 1 = homme, 2 = les deux, 3 = non binaire, 4 = trans, 5 = tous
    *  GENRE : 0 = femme, 1 = homme, 2 = non binaire, 3 = trans
*/
/// last test : 

/** FONCTIONNE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN((48.8958718 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS(48.8958718 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN((2.3165512 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation='1' OR orientation='5' OR orientation='2') AND genre='0' AND A.tag_id = B.tag_id AND A.user_id = 100 AND profils.user_id != 100 AND B.user_id != 100 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist
 */



    async searchF(my_genre, my_id, lat, lon, db) {
        if (my_genre === 0 || my_genre === 1) {       
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5' OR orientation='2') AND genre='0' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
           //  old return await db.query("SELECT *, (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(("+ lat +" - abs(cast(lat as float))) * pi()/180 / 2),2) + COS("+ lat +" * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(("+ lon +" - cast(lon as float)) *  pi()/180 / 2), 2) ))) as dist FROM profils WHERE orientation=0 OR orientation=5 OR orientation=2 AND genre=0 ORDER BY dist)", [
            //     my_genre,
            // ])
        } else {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5') AND genre='0' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // OLD return await db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 AND genre=0", [
            //     my_genre,
            // ])
        }

    },
///////////////////////// modifier les autre plus tard quand jaurais moin la flemme...........................
    async searchM(my_genre, my_id, lat, lon, db) {
        if (my_genre === 0 || my_genre === 1) {
            //OLD  return await db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 OR orientation=2 AND genre=1", [
            //     my_genre,
            // ])
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5' OR orientation=2) AND genre='1' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
        } else {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5') AND genre='1' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            //OLD  return await db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 AND genre=1", [
            //     my_genre,
            // ])
        }
    },
    // mal au crannnnneeeee
    async searchFAndM(my_genre, my_id, lat, lon, db) {
        if (my_genre === 0 || my_genre === 1) {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5' OR orientation=2) AND (genre='1' OR genre='0') AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // OLD  db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 OR orientation=2 AND genre=0 OR genre=1", [
            //     my_genre,
            // ])
        } else {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5') AND (genre='1' OR genre='0') AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // OLD db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 AND genre=0 OR genre=1", [
            //     my_genre,
            // ])
        }
    },
    async searchNonBinaire(my_genre, my_id, lat, lon, db) {
        if (my_genre === 1 || my_genre === 0) {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5' OR orientation='2') AND genre='2' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 OR orientation=2 AND genre=2", [
            //     my_genre,
            // ])
        } else {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5') AND genre='2' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // OLD db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 AND genre=2", [
            //     my_genre,
            // ])
        }
    },
    async searchTrans(my_genre, my_id, lat, lon, db) {
        if (my_genre === 1 || my_genre === 0) {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5' OR orientation='2') AND genre='3' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 OR orientation=2 AND genre=3", [
            //     my_genre,
            // ])
        } else {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5') AND genre='3' AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5 AND genre=3", [
            //     my_genre,
            // ])
        }
    },
    async searchAll(my_genre, my_id, lat, lon, db) {
        if (my_genre === 1 || my_genre === 0) {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5' OR orientation='2') AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // db.query("SELECT * FROM profils WHERE orientation=5 OR orientation=2 OR orientation = 1 OR orientation = 0")
        } else {
            return await db.query("SELECT profils.*, count(B.tag_id), count(profils.user_id), (1.6 * 3956 * 2 * ASIN(SQRT( POWER(SIN(($1 - abs(cast(lat as float))) * pi()/180 / 2),2) + COS($1 * pi()/180 ) * COS(abs(cast(lat as float)) *  pi()/180) * POWER(SIN(($2 - cast(lon as float)) *  pi()/180 / 2), 2) ))) AS dist FROM profils, users_tags A, users_tags B WHERE (orientation=$3 OR orientation='5') AND A.tag_id = B.tag_id AND A.user_id = $4 AND profils.user_id != $4 AND B.user_id != $4 AND B.user_id = profils.user_id group by profils.id, B.user_id ORDER BY dist", [
                lat,
                lon,
                my_genre,
                my_id,
            ])
            // db.query("SELECT * FROM profils WHERE orientation=$1 OR orientation=5", [
            //     my_genre
            // ])
        }
    },
    async updateProfile(profile, id_user, db) {
        return await db.query('UPDATE profils SET genre=$1, orientation=$2, bio=$3, age=$4, first_name=$5,last_name=$6 WHERE user_id=$7', [
            profile.genre,
            profile.orientation,
            profile.bio,
            profile.age,
            profile.first_name,
            profile.last_name,
            id_user,
        ])
    },

  async updateProfilePicture({ profilePictureId, userId, db }) {
    return await db.query(
      "UPDATE profils SET profile_picture_id=$1 WHERE user_id=$2",
      [profilePictureId, userId]
    )
  },

  async deleteProfilePicture({ userId, db }) {
    return await db.query(
      "UPDATE profils SET profile_picture_id=null WHERE user_id=$1",
      userId
    )
  },

  async getProfilePricture({ userId, db }) {
    return await db.query(
      "SELECT images.* FROM profils INNER JOIN images ON profils.profile_picture_id = images.id WHERE profils.user_id = $1",
      userId
    )
  },

  async create({ first_name, last_name, user_id, db }) {
    console.log(first_name, last_name, user_id)
    return await db.query(
      "insert into profils (user_id, first_name, last_name) VALUES ($1, $2, $3)",
      [user_id, first_name, last_name]
    )
  },

  async updateAtConnection({ lat, lon, user_id, db }) {
    return await db.query(
      "UPDATE profils SET lat=$1, lon=$2, last_connection=now() WHERE user_id=$3",
      [lat, lon, user_id]
    )
  },
  async updateNbLike(id_user, value, db) {
    return await db.query(
      "update profils set nb_like= nb_like + $1 WHERE user_id=$2",
      [value, id_user]
    )
  },
  async updateNbView(id_user, db) {
    return await db.query(
      "update profils set nb_vue= nb_vue + 1 WHERE user_id=$1",
      [id_user]
    )
  }
}
