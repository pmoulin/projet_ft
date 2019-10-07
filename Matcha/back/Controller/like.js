import Like from '../Models/like'

import Profile from '../models/profils'

import match from './matche'
import notif from './Notif'
import db from '../bdd'

    const get = async(idUserLiked, idEmitLike, db) => {
        let test = await Like.get(idEmitLike, idUserLiked, db)
        if (test[0]) {
            return 1;
        }
        return 0;
    }

    const create = async (req, res) => {
        if (req.session.idUsers) {
            const idUserLiked = req.params.id;
            const idEmitLike =  req.session.idUsers;
            if (await Like.create(idEmitLike, idUserLiked, db)) {
                Profile.updateNbLike(idUserLiked, 1, db);



                
                /**
                 * if user liked as likes user emit like 
                 */
                console.log('getlike === ' + await get(idEmitLike, idUserLiked, db));
                if (await get(idEmitLike, idUserLiked, db) === 1 && await match.match(idUserLiked, idEmitLike, db)) {
                    console.log('test 11111');
                    await notif.match(idUserLiked, idEmitLike, db, req.app.io);
                    await notif.match(idEmitLike, idUserLiked, db, req.app.io);
                } else {
                    console.log('id = ', idUserLiked);
                    console.log('notif send?');
                    notif.like(idUserLiked, idEmitLike, db, req.app.io);
                }
                res.send({data : 1}).status(200)
            }
        } else
            res.send({data : 0}).status(401)
    }

    const remove = async(req, res) => {
        if (req.session.idUsers) {
            const idUserLiked = req.params.id;
            const idEmitLike =  req.session.idUsers;
            if (await Like.remove(idEmitLike, idUserLiked, db)) {
                Profile.updateNbLike(idUserLiked, -1, db);
                /**
                 * if user liked as likes user emit like 
                 */
                console.log('getlike === ' + await get(idEmitLike, idUserLiked, db));
                if (await match.unMatch(idUserLiked, idEmitLike, db)) {
                    notif.unMatch(idUserLiked, idEmitLike, db, req.app.io);
                    notif.unMatch(idEmitLike, idUserLiked, db, req.app.io);
                } else
                    notif.dislike(idUserLiked, idEmitLike, db, req.app.io);
                res.send({data : 1}).status(200);
            }
        } else
            res.send({data : 0}).status(401);
    }

export default {get, create, remove}