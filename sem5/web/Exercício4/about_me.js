let body = document.getElementsByTagName('body')[0]
body.style.fontFamily = "Arial, Helvetica, sans-serif";

let nickname = document.getElementById('nickname')
let favorites = document.getElementById('favorites')
let hometown = document.getElementById('hometown')

nickname.innerHTML = "Madu"
favorites.innerHTML = "<br> Food: Sushi <br> Music: Rock <br>"
hometown.innerHTML = "Guaratinguetá"

let image = document.createElement('img')
image.src = "profile.jpeg"
image.style.width = "200px"
image.style.margin = "10px"
body.appendChild(image)