const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const history = require('connect-history-api-fallback');
const convert = require('koa-connect');
const WorkboxPlugin = require('workbox-webpack-plugin');
const { BundleAnalyzerPlugin } = require('webpack-bundle-analyzer');
const WebpackBar = require('webpackbar');

const env = process.env.NODE_ENV;
const isDev = env === 'development';
const isProd = env === 'production';

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
    new WebpackBar(),
    new HtmlWebpackPlugin({
      title: 'Webpack ReasonML',
      inject: true,
      template: './public/index.html'
    }),
    new WorkboxPlugin.GenerateSW({
      swDest: 'sw.js',
      clientsClaim: true,
      skipWaiting: true,
      // Exclude images from the precache
      exclude: [/\.(?:png|jpg|jpeg|svg)$/],
      // Define runtime caching rules.
      runtimeCaching: [
        {
          urlPattern: /^(https?.*)/,
          handler: 'networkFirst',
          options: {
            cacheName: 'cache-https',
            expiration: {
              maxEntries: 50
            },
            networkTimeoutSeconds: 3
          }
        },
        {
          // Match any request ends with .png, .jpg, .jpeg or .svg.
          urlPattern: /\.(?:png|jpg|jpeg|svg)$/,

          // Apply a cache-first strategy.
          handler: 'cacheFirst',

          options: {
            cacheName: 'images-cache',
            // Only cache 10 images.
            expiration: {
              maxEntries: 50
            },
            cacheableResponse: {
              statuses: [0, 200]
            }
          }
        }
      ]
    }),
    ...(!isDev ? [new BundleAnalyzerPlugin()] : [])
  ],
  optimization: {
    splitChunks: {
      cacheGroups: {
        commons: {
          test: /node_modules/,
          chunks: 'initial',
          name: 'vendor',
          priority: 10,
          enforce: true
        }
      }
    }
  },
  stats: {
    colors: true,
    reasons: isDev,
    timings: true
  }
};

if (env === 'development') {
  module.exports.serve = {
    content: [__dirname],
    port: 8888,
    add: (app, middleware, options) => {
      const historyOptions = {
        // ... see: https://github.com/bripkens/connect-history-api-fallback#options
      };

      app.use(convert(history(historyOptions)));
    }
  };
}
