import connection from "./Users/connection"
import isConnected from "./Users/isConnected"
import disconnect from "./Users/disconnect"
import register from "./Users/register"

export default {
  async connection(req, res) {
    const result = await connection(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  async register(req, res) {
    const result = await register(req.body)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  isConnected(req, res) {
    const result = isConnected(req)
    console.log(result.message)
    res.send(result).status(result.status)
  },

  disconnect(req, res) {
    const result = disconnect(req)
    console.log(result.message)
    res.send(result).status(200)
  }
}
