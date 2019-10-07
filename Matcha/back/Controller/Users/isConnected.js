const isConnected = ({ session }) => {
  if (session.idUsers)
    return {
      error: false,
      message: "user connected",
      connected: true,
      id: session.idUsers,
      status: 200
    }
  return {
    error: false,
    message: "user not connected",
    connected: false,
    id: -1,
    status: 200
  }
}

export default isConnected
