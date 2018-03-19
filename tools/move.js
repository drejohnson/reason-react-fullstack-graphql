const path = require('path')
const fs = require('fs-extra')
const config = require('./config')

const renameClient = async (i, o) => {
  const exists = await fs.pathExists(i)
  if (exists) {
    await fs.moveSync(config.resolveApp(i), config.resolveApp(o), {
      overwrite: true
    })
  }
}

const renameServer = async (i, o) => {
  const exists = await fs.pathExists(i)
  if (exists) {
    await fs.moveSync(config.resolveApp(i), config.resolveApp(o), {
      overwrite: true
    })
  }
}

renameClient('dist/client/Client.bs.js', 'dist/client/client.js')
renameServer('dist/server/Server.bs.js', 'dist/server/index.js')
