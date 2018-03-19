const path = require('path')
const fs = require('fs-extra')
const config = require('./config')

fs.emptyDirSync(config.resolveApp('dist'))
