const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const history = require('connect-history-api-fallback')
const convert = require('koa-connect')

const env = process.env.NODE_ENV
const isDev = env === 'development'
const isProd = env === 'production'

module.exports = {
  mode: env || 'development',
  entry: './src/Index.bs',
  output: {
    path: path.resolve(__dirname, './dist'),
    filename: isDev ? '[name].js' : '[name].[chunkhash:8].js',
    publicPath: '/'
  },
  module: {
    rules: [
      {
        test: /\.svg$/,
        loader: 'svg-sprite-loader'
      }
    ]
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: 'Webpack ReasonML',
      inject: true,
      template: './public/index.html'
    })
  ],
  optimization: { splitChunks: { chunks: 'all', name: 'vendor' } }
}

if (env === 'development') {
  module.exports.serve = {
    content: [__dirname],
    port: 8888,
    open: true,
    add: (app, middleware, options) => {
      const historyOptions = {
        // ... see: https://github.com/bripkens/connect-history-api-fallback#options
      }

      app.use(convert(history(historyOptions)))
    }
  }
}
