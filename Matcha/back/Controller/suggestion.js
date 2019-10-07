import Profile from "../Models/profils"
/**
    *  ORIEN : 0 = femme, 1 = homme, 2 = les deux, 3 = non binaire, 4 = trans, 5 = tous
    *  GENRE : 0 = femme, 1 = homme, 2 = non binaire, 3 = trans
*/
    const get = async (req, res) => {
        console.log("bou");
        const userId = req.session.idUsers
        if (userId) {
            let profile = await Profile.findById(userId, req.app.db);
            let candidate;
            console.log(profile);
            const {lat, lon, genre, orientation, id, profile_picture_id} = profile
            if (!lat || !lon || !genre || !orientation || !id || !profile_picture_id)
                res.send({candidate:'profile non complet'}).status(200)
            else if (orientation == 0) // rien qui marche lol
                candidate = await Profile.searchF(genre, id, lat, lon, req.app.db);
            else if (orientation == 1)
                candidate = await Profile.searchM(genre, id, lat, lon, req.app.db);
            else if (orientation == 2)
                candidate = await Profile.searchFAndM(genre, id, lat, lon, req.app.db);
            else if (orientation == 3)
                candidate = await Profile.searchNonBinaire(genre, id, lat, lon, req.app.db);
            else if (orientation == 4)
                candidate = await Profile.searchTrans(genre, id, lat, lon, req.app.db);
            else if (orientation == 5)
                candidate = await Profile.searchAll(genre, id, lat, lon, req.app.db);
            else
                res.send({candidate : 'error orientation'}).status(200);
            if (candidate)
                res.send({ candidate }).status(200)
        }
        else {
            res.send({candidate: "user not connnected"}).status(401)
        }
    }
export default {get}
