require('dotenv').config()
var express = require('express');
var app = express();
//console.log(process.env)

const sql = require('mssql');

var DbUserName = process.env.DbUsername
var DbUserPassword = process.env.DbUserPassword
var DbName = process.env.DbName
var DbServerName = process.env.DbServerName

var config = {
    user: DbUserName,
    password: DbUserPassword,
    server: DbServerName,
    database: DbName
};

app.get('/', function (req, res) {
    sql.connect(config, function (err) {
    if (err) console.log(err);
    var request = new sql.Request();
    request.query('select * from consultants', function (err, result) {
    if (err) console.log("ERROR: " + err)
    console.log("rows returned: " + result.recordset.length)
    res.setHeader('Content-Type', 'text/html');
    for(let i=0; i<result.recordset.length; i++){
    console.log(result.recordset[i]);
    res.write(JSON.stringify(result.recordset[i]))
    }
    res.send()
    })
    });
})

app.get('/most_experience', async (req, res) => {
       try {
         const skillName = req.query.skill_name;
     
         // Connect to the database
         const pool = await sql.connect(config);
     
         // Execute SQL query to get consultant with most experience for the skill
         const result = await pool.request()
           .input('skill', sql.NVarChar, skillName)
           .query('SELECT TOP 1 * FROM consultants WHERE skill = @skill ORDER BY experience DESC');
     
         // Return result as JSON response
         res.json(result.recordset[0]);
       } catch (err) {
         console.error(err);
         res.status(500).send('Internal Server Error');
       }
});

app.get('/lowest_rate', async (req, res) => {
       try {
         const skillName = req.query.skill_name;
     
         // Connect to the database
         const pool = await sql.connect(config);
     
         // Execute SQL query to get consultant with lowest hourly rate for the skill
         const result = await pool.request()
           .input('skill', sql.NVarChar, skillName)
           .query('SELECT TOP 1 * FROM consultants WHERE skill = @skill ORDER BY hourlyRate ASC');
     
         // Return result as JSON response
         res.json(result.recordset[0]);
       } catch (err) {
         console.error(err);
         res.status(500).send('Internal Server Error');
       }
});

var server = app.listen(80, function () {
    console.log('Server is running ...');
    });

