function handleClickAdd() {
  var table = document.getElementById("charlie");

  var newRow = table.insertRow(-1);
  var Select = newRow.insertCell(0);
  var Name = newRow.insertCell(1);
  var City = newRow.insertCell(2);
  var Email = newRow.insertCell(3);

  Select.innerHTML = '<input type = "checkbox">';
  Name.innerHTML = '<input type = "text">';
  City.innerHTML = '<input type = "text">';
  Email.innerHTML = '<input type = "text">';
}
    
	
function handleClickDelete() {
	var table = document.getElementById("charlie");
	let rowCount = table.rows.length;
	
	for (i = rowCount - 1; i>0; i--) { 
		let row = table.rows[i];
		let chkbox = row.cells[0].childNodes[0];
		if(chkbox && chkbox.checked) { 
			table.deleteRow(i);
		}
	}
}
	 
function displayCity() {
  var city = document.getElementById("cityInput").value.trim().toLowerCase();
  var table = document.getElementById("charlie");
  var rows = table.rows;
  var found = false;
  
    for (var i = 1; i < rows.length; i++) {
    var nameInput = rows[i].cells[1].getElementsByTagName('input')[0].value.trim();
    var cityInput = rows[i].cells[2].getElementsByTagName('input')[0].value.trim();
    var emailInput = rows[i].cells[3].getElementsByTagName('input')[0].value.trim();
    
    if (nameInput === "" || cityInput === "" || emailInput === "") {
      alert("Fill out all entries then try again");
      return;
    }
  }
	 
	for (var i = 1; i < rows.length; i++) {
    
    var cityInput = rows[i].cells[2].getElementsByTagName('input')[0].value.trim().toLowerCase();

    if (cityInput === city) { 
	  found = true;
      var nameElement = document.createElement("p");
      nameElement.innerHTML = "Name: " + rows[i].cells[1].getElementsByTagName('input')[0].value;
      document.body.appendChild(nameElement);

      var emailElement = document.createElement("p");
      emailElement.innerHTML = "Email: " + rows[i].cells[3].getElementsByTagName('input')[0].value;
      document.body.appendChild(emailElement);
	}
  } 
  
    if (!found) { 
		var errorElement = document.createElement("p");
		errorElement.innerHTML = "Error: No matching city found";
		document.body.appendChild(errorElement);
	}  	
}


			
		