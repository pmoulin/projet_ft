import Images from "../../Models/Images"
import mkdirp from "mkdirp"
import db from "../../bdd"

const makeUploads = async ({ files, picked, userId }) => {
  const directoryPath = `../front/public/Images/${userId}`
  await mkdirp(directoryPath)
  for (let file of files) {
    const filePath = `${directoryPath}/${file.name}`
    await file.mv(filePath)
    const path = `Images/${userId}/${file.name}`
    await Images.addOne({ path, userId, db })
    const image = await Images.findOne({ path, db })
    if (!image) {
      return { error: true, message: "error uploading image", status: 200 }
    }
  }
  return { error: false, message: "images uploaded successfully", status: 200 }
}

const uploadImages = async ({ files, body, session }) => {
  const userId = session.idUsers
  if (!userId) {
    return { error: true, message: "user not connected", status: 400 }
  }
  if (!files) {
    return { error: true, message: "no files uploaded", status: 400 }
  }
  return await makeUploads({
    files: Object.values(files),
    picked: parseInt(body.picked),
    userId
  })
}

export default uploadImages
