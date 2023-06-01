const express = require('express')

const app = express()

const port = 3000 

const bodyParser = require('body-parser')

app.use(bodyParser.json())

let globals = require('./globals')

employee_id = globals.id
employee_name = globals.name
employee_department = globals.department
employee_salary = globals.salary

app.get("/employee", ((req,res) => { 
    for(i=0; i<employee_id.length; i++) {
        emps = { 
            name: employee_name[i],
            id: employee_id[i],
            dept: employee_department[i],
            salary: employee_salary[i]
    }
    res.write(JSON.stringify(emps))
}
res.end()

}) )

app.get("/employee/id", ((req,res) => { 

    const id = parseInt(req.query.id)
    const index = employee_id.indexOf(id);

    const emps = {
       Name: employee_name[index],
       id: employee_id[index],
       Department: employee_department[index],
       Salary: employee_salary[index]
    }

    res.write(JSON.stringify(emps))

res.end()

}) )

app.delete("/employee", ((req,res) => {
    
    const id = parseInt(req.query.id);
    const index = employee_id.indexOf(id);

    if (id > -1) { 
            employee_name.splice(index,1)
            employee_id.splice(index,1)
            employee_department.splice(index,1)
            employee_salary.splice(index,1)
    }

    res.write(JSON.stringify(employee_name,employee_id,employee_department,employee_salary))

    res.end()

}) )

app.post("/employee/id",((req,res) => {
    
         employee_name.push(req.body.name);
         employee_id.push(req.body.id);
         employee_department.push(req.body.dept);
         employee_salary.push(req.body.salary);

    res.write(JSON.stringify("name: " + req.body.name 
        + " \ " + "id: " + req.body.id + " \ " + "department: " + req.body.dept
        + " \ " + "salary: " + req.body.salary))

    res.end()

}) )

app.put("/inventory/id",((req,res) => {
    
    const data = [req.body.name,req.body.id,req.body.dept,req.body.salary];
    
    res.write(JSON.stringify(data))

    res.end()

}) )

var server = app.listen(port, function () {
    console.log(`Server listening on port ${port}`)
  })

 