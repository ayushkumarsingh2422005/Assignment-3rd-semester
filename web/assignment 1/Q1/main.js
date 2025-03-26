window.onload = function(){
    let container = document.getElementById("container");
    container.addEventListener("mouseover", ()=>{
        document.body.style.backgroundColor = "red";
    });
    container.addEventListener("mouseout", ()=>{
        document.body.style.backgroundColor = "white";
    });
}