import Notif from '../Models/Notif'
import Blocked from '../Models/blocked'
import Profile from '../Models/profils'
import Users from '../models/Users'


/**
 * MATCH 
 */
    const match = async(idUserReceive, idUserEmit, db, io) => {
        if (await Blocked.search(db, idUserReceive, idUserEmit) === false)
        {
            const profile = await Profile.findById(idUserEmit, db);
            await Notif.create(db, idUserReceive, 'Match', 'vous venez de matchez avec : ' + profile['first_name'] + ' ' + profile['last_name']);
            // console.log('socket id ====' + req.app.socket.id)
            let socket_id = await Users.getSocketId(idUserReceive, db);
            io.to(socket_id).emit({type : 'Match', message : 'vous venez de matchez avec : ' + profile['first_name'] + ' ' + profile['last_name']})
            return true;
        }
        return false;
    }

    const unMatch = async(idUserReceive, idUserEmit, db, io) => {
        if (await Blocked.search(db, idUserReceive, idUserEmit) === false)
        {
            const profile = await Profile.findById(idUserEmit, db);
            await Notif.create(db, idUserReceive, 'unMatch', 'vous venez de perdre un matchez avec : ' + profile['first_name'] + ' ' + profile['last_name']);
            
            let socket_id = await Users.getSocketId(idUserReceive, db);
            io.to(socket_id).emit({type : 'unMatch', message : 'vous venez de perdre un matchez avec : ' + profile['first_name'] + ' ' + profile['last_name']})
            return true;
        }
        return false;
    }

/**
 * LIKE
 */

    const like = async (idUserReceive, idUserEmit, db, io) => {
        if (await Blocked.search(db, idUserReceive, idUserEmit) === false) {
            console.log('User emit Like => ',idUserEmit, 'user receive like =>', idUserReceive);
            const profile = await Profile.findById(idUserEmit, db);
            await Notif.create(db, idUserReceive, 'Like', profile['first_name'] + ' ' + profile['last_name'] + ' s\'interesse a vous !');
            
            let socket_id = await Users.getSocketId(idUserReceive, db);
            io.to(socket_id).emit('notif', {type : 'like', messsage : profile['first_name'] + ' ' + profile['last_name'] + ' s\'interesse a vous !'});
            // io.sockets.socket(socket_id).emit('notif', 'Like', profile['first_name'] + ' ' + profile['last_name'] + ' s\'interesse a vous !') // emit an event to the socket

            return true;
        } else
            return false
    }
    const dislike = async (idUserReceive, idUserEmit, db, io) => {
        if (await Blocked.search(db, idUserReceive, idUserEmit) === false) {
            const profile = Profile.findById(idUserEmit, db);
            await Notif.create(db, idUserReceive, 'Dislike', profile['first_name'] + ' ' + profile['last_name'] + ' ne s\'interesse plus a vous !');

            let socket_id = await Users.getSocketId(idUserReceive, db);
            io.to(socket_id).emit({type : 'Dislike', message : profile['first_name'] + ' ' + profile['last_name'] + ' ne s\'interesse plus a vous !'})
            return true;
        } else
            return false
    }


/**
 * J C PAS ENCORE
 */
export default {match, like, unMatch, dislike}