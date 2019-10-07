import Blocked from '../Models/blocked' 
import db from '../bdd'
/**
 * Verif si user 1 a blocker user 2
 * @param {int} idUser1
 * @param {int} idUser2
 */
    const get = async (idUser1, idUser2) => {
        return (await Blocked.search(db, idUser1, idUser2) ? 1 : 0);
    }

    const create = async (req, res) => {
        if (req.session.idUsers) {
            if (req.session.idUsers !== req.params.id){
                await Blocked.create(db, req.session.idUsers, req.params.id);
                res.send({data : 1}).status(200);
            } else
                res.send({data : false}).status(200);
        } else 
            res.send({data : false}).status(401);
    }

    const remove = async (req, res) => {
        if (req.session.idUsers) {
            if (req.session.idUsers !== req.params.id) {
                await Blocked.remove(db, req.session.idUsers, req.params.id);
                res.send({data : 1}).status(200);
            } else
                res.send({data : false}).status(200);
        } else
            res.send({data : false}).status(401)
    }

export default {get, create, remove}