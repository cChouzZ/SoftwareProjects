require('dotenv').config()
var express = require('express');
var mysql = require('mysql');
const bodyParser = require('body-parser');

var app = express();
app.use(bodyParser.json());

var env_user = process.env.user
var env_password = process.env.password
var env_database = process.env.database
var env_host = process.env.host
console.log(env_user, env_password, env_database, env_host)

var db_conn = mysql.createConnection({
host: env_host,
user: env_user,
password: env_password,
database: env_database
});

db_conn.connect((err => { 
    if (err) throw err;
    console.log('MySQL Connected');
}));

app.get('/user', (req, res) => {
    let sql = 'SELECT * FROM user';
    db_conn.query(sql, (err, result) => {
    if (err) throw err;
    console.log(result);
    res.json(result);
    });
});

app.post('/user', (req, res) => {
    let { name, email, password } = req.body;
    const query = "INSERT INTO user (name, email, password) VALUES ('Jack Smith','Jack.smith@example.com','lettersAndnumbers!')";
    db_conn.query(query, [name, email, password], (err, results) => {
    if (err) {
    console.error('Error inserting into the database:', err);
    res.status(500).json({ error: 'Error inserting into the database' });
    return;
    }
    res.json({ results });
    });
});

app.put('/user', (req, res) => {
    let { name, email, password } = req.body;
    const query = "UPDATE user SET password = 'exampletest' WHERE name = 'Jack Smith'";
    db_conn.query(query, [name, email, password], (err, results) => {
    if (err) {
    console.error('Error updating the database:', err);
    res.status(500).json({ error: 'Error updating the database' });
    return;
    }
    if (results.affectedRows === 0) {
        res.status(404).json({ error: 'user not found' });
        return;
        }
        res.json({ results });
    });
});

app.delete('/user', (req, res) => {
    let {name, email, password} = req.body;
    const query = "DELETE FROM user WHERE name = 'Jack Smith'";
    db_conn.query(query, [name, email, password], (err, results) => {
    if (err) {
    console.error('Error deleting from the database:', err);
    res.status(500).json({ error: 'Error deleting from the database' });
    return;
    }
    if (results.affectedRows === 0) {
        res.status(404).json({ error: 'user not found' });
        return;
        }
        res.json({ message: 'user deleted successfully' });
    });
});

app.listen(3000, () => { 
    console.log("server listening on port 3000")
});