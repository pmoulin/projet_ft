import Images from "../../Models/Images"
import db from "../../bdd"

const getUserImages = async ({ session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 400 }
  }
  const images = await Images.findByUser({ userId, db })
  return {
    error: false,
    message: "user image got successfully",
    images,
    status: 200
  }
}

export default getUserImages
