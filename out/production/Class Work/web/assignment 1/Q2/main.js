window.onload = ()=>{
    let name = document.getElementById("name");
    let email = document.getElementById("email");
    let password = document.getElementById("password");
    let confirmPassword = document.getElementById("confirmPassword");
    let phone = document.getElementById("phone");
    let address = document.getElementById("address");
    let form = document.getElementById("form");
    let error = document.getElementById("error");


    form.addEventListener("submit", (e)=>{
        let messages = [];
        if(name.value === "" || name.value == null){
            messages.push("Name is required");
        }
        if(email.value === "" || email.value == null){
            messages.push("Email is required");
        }
        if(password.value === "" || password.value == null){
            messages.push("Password is required");
        }
        if(confirmPassword.value === "" || confirmPassword.value == null){
            messages.push("Confirm Password is required");
        }
        if(password.value !== confirmPassword.value){
            messages.push("Password do not match");
        }
        if(phone.value === "" || phone.value == null){
            messages.push("Phone is required");
        }
        if(address.value === "" || address.value == null){
            messages.push("Address is required");
        }
        if(messages.length > 0){
            e.preventDefault();
            error.innerHTML = messages.join("<br/> ");
        }
    });
}