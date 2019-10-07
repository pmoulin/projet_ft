import Images from "../../Models/Images"
import Profiles from "../../Models/profils"
import db from "../../bdd"
import fs from "fs"

const deleteImage = async ({ body, session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 400 }
  }

  const { image } = body
  const { profile_picture_id } = await Profiles.findById(userId, db)
  if (profile_picture_id === image.id) {
    await Profiles.deleteProfilePicture({
      userId,
      db
    })
    console.log("no more profile picture for this account")
  }
  await Images.deleteById({ imageId: image.id, db })
  fs.unlink(`../front/public/${image.path}`, err => {
    if (err) console.log(err)
  })
  return { error: false, message: "image well deleted", status: 200 }
}

export default deleteImage
