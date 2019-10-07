import faker from "faker/locale/fr"
import bcrypt from "bcrypt"
import Users from "../Models/Users"
import FakerModels from "../Models/Faker"
import UsersTags from "../Models/UsersTags"
import Tag from "../Models/Tags"
/**
    *  ORIEN : 0 = femme, 1 = homme, 2 = les deux, 3 = non binaire, 4 = trans, 5 = tous
    *  GENRE : 0 = femme, 1 = homme, 2 = non binaire, 3 = trans
 */

    /**
     * Create fake profile FR
     * @param {\} req 
     * @param {*} res 
     */
    const seed = async(req, res) => {
        let i = 0;
        while (i < 3) {
            /**
             * create Users Account
             */
            let user = {
                login: faker.internet.userName(),
                pwd:  bcrypt.hashSync(faker.internet.password(8, true), 10),
                email: faker.internet.email(),
                active: faker.random.boolean(),
            }
            await FakerModels.create_user(user, req.app.db);
            /**
             * create profile
             */
            let id_user = await Users.getByLogin(user.login, req.app.db);
            
            let profile = 
            {
                user_id : parseInt(id_user[0].id),
                first_name : faker.name.firstName(),
                last_name : faker.name.lastName(),
                genre : faker.random.number({min:0, max:3}),
                orientation : faker.random.number({min:0, max:1}),
                birthday : faker.date.between('1945-01-01', '1999-12-31').toISOString().slice(0, 19).replace('T', ' '),
                bio : faker.lorem.paragraph(),
                lat : faker.address.latitude(),
                lon : faker.address.longitude(),
                country : faker.address.country(),
            }
            /**
             * define position in french country
             */
            while (parseFloat(profile.lat) <= 43.0 || parseFloat(profile.lat) >= 51.0) {
                profile.lat = faker.address.latitude();
            }
            
            while (parseFloat(profile.lon) <= 1.0 || parseFloat(profile.lon) >= 3.0){
                profile.lon = faker.address.longitude();
            }
            await FakerModels.create_profile(profile, req.app.db);
            /**
             * asigne tag to profile
             */
            let nbTag = await FakerModels.count_tag(req.app.db);
            let tmp = faker.random.number({min:0, max: parseInt(nbTag)});
            let tag_select = 0;
            let array1 = [];
            if (tmp > 0) {
                tag_select = tag_select = faker.random.number({min:1, max: parseInt(nbTag)});
                array1[0] = faker.random.number({min:1, max: parseInt(nbTag)});
            }
            while (tmp > 0) {
                // verif tag not already select
                if (array1 === null || array1.indexOf(tag_select) === -1)
                {
                // add tag to users
                    array1.push(tag_select);
                    await UsersTags.addOne({tagId : parseInt(tag_select), userId : parseInt(id_user[0].id), db : req.app.db});
                    await Tag.addOneSelection({tagId : parseInt(tag_select), db : req.app.db})
                    tmp--;
                }
                tag_select = faker.random.number({min:1, max: parseInt(nbTag)});
            }
            i++;
        }
        console.log("SEED FINISH")
        res.send("success").status(200);
    }

export default {seed}