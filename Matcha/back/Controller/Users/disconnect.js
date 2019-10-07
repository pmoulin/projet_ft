const disconnect = (req) => {
  req.session.destroy()
  return {
    error: false,
    message: "disconnected",
    connected: false,
    status: 200
  }
}

export default disconnect
