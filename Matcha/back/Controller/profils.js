import Profile from '../Models/profils'
import blocke from './blocked'
import like from './like'
import view from './view'
import Tags from '../Models/UsersTags';
// import Tags from './Tags';
// import req.app.db from '../bdd'

    const show_profile = async (req, res) => {
        if (req.session.idUsers) {
            let profileUsers = await Profile.findById(req.params.id, req.app.db);
            profileUsers.tags = await Tags.getAllUserTags({userId : req.params.id, db : req.app.db})
            if (req.session.idUsers != req.params.id) {// other profile
                let isLiked = await like.get(req.params.id, req.session.idUsers, req.app.db);
                let isBlocked = await blocke.get(req.session.idUsers, req.params.id, req.app.db);
                view.create(req.session.idUsers, req.params.id);
                Profile.updateNbView(req.params.id, req.app.db);
                res.send({profile : profileUsers, like : isLiked, blocke : isBlocked}).status(200);
            } else { // my profile
                res.send({profile : profileUsers, like : null, blocke : null}).status(200);
            }
        } else {
            res.send('Non Connecter').status(401);
        }
    }

    const update_profile = async (req, res) => {
        console.log("update_profile");
        if (req.session.idUsers && req.session.idUsers === req.params.id) {
            if (req.session.idUsers === req.params.id) {
                    // req.parseInt(age); 
                if (await Profile.updateProfile(req.body.profile, req.session.idUsers, req.app.db)) {
                    res.send().status(200)
                    return true;
                }
            } else
                res.send('acces non autoriser').status(403)
              
        } else
            res.send('Non Connecter').status(401);
    }

    const create_profile = async (req, res) => {
        console.log("create_profile");
        if (await Profile.createProfile(new_profil, this.id, req.app.db)) {
            return true;
        } else
            return false;
    }

export default {create_profile, update_profile, show_profile}