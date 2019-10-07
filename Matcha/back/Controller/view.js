import View from '../Models/View'
import Profile from '../Models/profils'
import blockedController from "./blocked"
import db from '../bdd'

    /**
     * GET PROFILE que j'ai vue (sauf ce blocker que j'ai blocker)
     * @param {*} req
     * @param {*} res
     */
    const get_profiles_view = async (req, res) => {
        if (req.session.idUsers) {
            if (req.params.id == req.session.idUsers) {
                let nb = 10;
                //get id profile profil_viewed
                let id_profiles = await View.get_viewed(req.session.idUsers, nb, db);
                let profile = [];
                let tmp = null;
                // get profile
                for (let i = 0; id_profiles[i]; i++) {
                    if (await blockedController.get(req.session.idUsers, id_profiles[i].id_user_viewed) === 0)
                        profile.push(await Profile.findById(id_profiles[i].id_user_viewed, db));
                
                }
                
                res.send({profile : profile}).status(200);
            } else
                res.send({profile : 'hello'}).status(200);
        } else 
            res.send({profile : null}).status(401);
    }

    /**
     * GET PROFILE des visiteur de mon profile (sauf que j'ai blocker)
     * @param {*} req 
     * @param {*} res 
     */
    /** TODO FAIRE LE TRUE DES PROFIL BLOCKER */
    const get_profiles_visitor = async (req, res) => {
        if (req.session.idUsers) {
            if (req.params.id == req.session.idUsers) {
                console.log('second')
                let nb = 10;
            //get id profile profil_visitor
                let id_profiles = await View.get_visitor(req.session.idUsers, nb, db);
                let profile = [];
            // get profile
                
                for (let i = 0; id_profiles[i]; i++) {
                    if (await blockedController.get(req.session.idUsers, id_profiles[i].id_user_visitor) === 0)
                        profile.push(await Profile.findById(id_profiles[i].id_user_visitor, db));
                }
                res.send({profile : profile}).status(200);
            } else
                res.send({profile : 'hello'}).status(200);
        } else 
            res.send({profile : null}).status(401);
    }
    
    const create = async (id_visitor, id_viewed) => {
        return await View.create(id_visitor, id_viewed, db);
    }

export default {get_profiles_view, get_profiles_visitor, create}