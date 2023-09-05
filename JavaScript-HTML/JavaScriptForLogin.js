const express = require('express')
const app = express()
const port = 3000

app.use(express.static('public'))

app.get('/index.html',function(req,res) { 
    res.sendFile(__dirname + "/" + "index.html")
})

const validCredentials = { 
    'user': 'password',
    'john': '123456',
    'jane': 'abc123',
    'bob': 'WSd!$&'
}

app.get('/process_get',function(req,res) { 
    const name = req.query.name;
    const password = req.query.password;

    response = { 
        Name: name,
        Password: password,
    };

    console.log(response);

    if(validCredentials[name] === password) { 
        res.write(JSON.stringify("Hello " + name))
    } else { 
        res.write(JSON.stringify("Error: Invalid name or password!"))
    }
    res.end()
})

var server = app.listen(port,function () { 
    console.log(`Server listening on port ${port}`)
})
