import Match from "../Models/Match"

    const match = async  (idUserLiked, idEmitLike, db) => {
        if (await Match.search(idUserLiked, idEmitLike, db) === false) {
            await Match.create(idUserLiked, idEmitLike, db);
            return true;
        } else
            return false;
    }

    const unMatch = async (idUserLiked, idEmitLike, db) => {
        if (await Match.search(idUserLiked, idEmitLike, db) === true) {
            await Match.remove(idUserLiked, idEmitLike, db);
            return true;
        } else
            return false;
    }

export default {match, unMatch}