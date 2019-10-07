import Profiles from "../../Models/profils"
import db from "../../bdd"

const setProfilePicture = async ({ body, session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 400 }
  }

  const { imageId } = body
  await Profiles.updateProfilePicture({
    profilePictureId: imageId,
    userId,
    db
  })

  return {
    error: false,
    message: `profile picture set to imageId: ${imageId}`,
    status: 200
  }
}

export default setProfilePicture
