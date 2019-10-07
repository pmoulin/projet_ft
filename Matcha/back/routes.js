import Users from "./Controller/Users"
import Tags from "./Controller/Tags"
import Images from "./Controller/Images"
import profileController from "./Controller/profils.js"
import likeController from "./Controller/like"
import blockeController from "./Controller/blocked"
import viewController from "./Controller/view"
import suggestion from "./Controller/suggestion"

import seed from "./Controller/faker"
import db from "./bdd"

module.exports = (app, socket) => {
  app.socket = socket

  app.get("/", async (req, res) => {
    console.log(req.cookies)
    res.send(req.cookies)
  })

  app.get("/seed", seed.seed)

  /* USERS */

  app.get("/isConnected", Users.isConnected)

  app.get("/disconnect", Users.disconnect)

  app.post("/connection", Users.connection)

  app.post("/register", Users.register)

  /**
   * PROFILS
   */

  /**
   * edit
   */
  app.post("/profile/:id/edit", profileController.update_profile)
  // async (req, res) => {
  //   if (req.session.idUsers) {

  //     let profileController = new ControllerProfiles(req.session.idUsers, db);
  //     if (profileController.update(req.body.profile)) {
  //       console.log(req.body.profile)
  //       res.send('success').status(200);//good
  //     }
  //     else {
  //       res.send('fail update').status(200);
  //     }
  //   } else
  //       res.send('non connecter').status(401);//error
  // })

  app.get("/profile/:id/edit", profileController.show_profile)
  //   async (req, res) => {
  //     if (req.session.idUsers) {
  //     let profileController = new ControllerProfiles(req.session.idUsers, db);

  //         let profile = await profileController.show(req.session.idUsers)
  //         if (profile){
  //           res.send({profile : profile}).status(200);//good
  //         }
  //         else
  //           res.send('error get profil').status(200);//error
  //       } else {
  //         res.send('Non Connecter').status(401);
  //       }
  // })
  /**
   * Return profile
   */

  app.get("/profile/:id", profileController.show_profile)
  //   async (req, res) => {
  //     // console.log('idUser => ', req.session.idUsers, ' || id => ', req.body)
  //     if (req.session.idUsers) {
  //       // let profileController = new ControllerProfiles(req.session.idUsers, db);

  //       const {profile, like} = await show(req.params.id);

  //       res.send({profile, like}).status(200);
  //     } else {
  //       res.send('Non Connecter').status(401);
  //     }
  // })

  app.post("/profile/:id/create", async (req, res) => {
    let profile = new ControllerProfiles(req.session.idUsers, db)
    if (profile.create(req.body.profile)) {
      res.send("success").status(200) //good
    } else res.send("failed create profil").status(500) //error
  })

  /**
   * LIKE
   */
  app.post("/profile/:id/addLike", likeController.create)
  // async (req, res) => {
  //   let like = new ControllerLike(req.session.idUsers, db);
  //   console.log('ROUTE LIKE')
  //   if (like.create(req.body.id)) {
  //     res.send('success').status(200);//good
  //   } else
  //     res.send('failed add').status(500);//error
  // })

  app.post("/profile/:id/disLike", likeController.remove)
  // async (req, res) => {
  //   console.log('ROUTE UNLIKE')
  //   let like = new ControllerLike(req.session.idUsers, db);
  //   if (like.remove(req.body.id)) {
  //     res.send('success').status(200);//good
  //   } else
  //     res.send('failed dislike profil').status(500);//error
  // })
  /**
   * BLOCK
   */
  // app.get('/profile/:id/block', blockeController.show);

  app.post("/profile/:id/block", blockeController.create)

  app.post("/profile/:id/unblock", blockeController.remove)

  app.get("/profile/:id/viewed", viewController.get_profiles_view)

  app.get("/profile/:id/visitor", viewController.get_profiles_visitor)

  // app.post('/profile/:id/block', async (req, res) => {

  // })

  // app.post('/profile/:id/unBlock', async (req, res) => {

  // })

  /* IMAGES*/

  app.get("/getUserImages", Images.getUserImages)

  app.get("/getProfilePicture", Images.getProfilePicture)

  app.post("/uploadImages", Images.uploadImages)

  app.post("/deleteImage", Images.deleteImage)

  app.post("/setProfilePicture", Images.setProfilePicture)

  /* TAGS */

  app.get("/getAllTags", Tags.getAllTags)

  app.get("/getUserTags", Tags.getUserTags)

  app.post("/addTag", Tags.addTag)

  app.post("/deleteTag", Tags.deleteTag)

  /**
   * UTILS
   */

  /**
   * suggestion
   */
  app.get("/suggestion", suggestion.get)
}

/**
 *
 * http error :
 * 200 : succès de la requête ;
 * 301 et 302 : redirection, respectivement permanente et temporaire ;
 * 401 : utilisateur non authentifié ;
 * 403 : accès refusé ;
 * 404 : page non trouvée ;
 * 500 et 503 : erreur serveur ;
 * 504 : le serveur n'a pas répondu.
 */
