import uploadImages from "./Images/uploadImages"
import getUserImages from "./Images/getUserImages"
import setProfilePicture from "./Images/setProfilePicture"
import deleteImage from "./Images/deleteImage"
import getProfilePicture from "./Images/getProfilePicture"

export default {
  async uploadImages(req, res) {
    const result = await uploadImages(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async getUserImages(req, res) {
    const result = await getUserImages(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async setProfilePicture(req, res) {
    const result = await setProfilePicture(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async deleteImage(req, res) {
    const result = await deleteImage(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async getProfilePicture(req, res) {
    const result = await getProfilePicture(req)
    console.log(result.message)
    res.send(result).status(result.status)
  }
}
