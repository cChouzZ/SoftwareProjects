// The following is an example of what the server sees

const express = require('express')
const app = express()
const port = 3000
app.use(express.static('public'))
app.get('/index.html', function (req, res) {
      res.sendFile( __dirname + "/" + "index.html" )
})

app.get('/add', function (req, rse) {
    let x = parseInt(req.query.val1)
    let y = parseInt(req.query.val2)
    let ans = x + y
    response = {
          x : req.query.val1,
          y : req.query.val2,
          z : ans
    };
    console.log(response)
    res.end(JSON.stringify(response))
})
var server = app.listen(port, function () {
  console.log(`Server listening on port ${port}`)
})