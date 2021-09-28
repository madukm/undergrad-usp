document.addEventListener('DOMContentLoaded', (event) => {
  document.getElementById('change_heading').innerHTML = 'Congrats! You changed it!';
  
  var color_brown = document.getElementsByClassName('brown')[0];
  var color_green = document.getElementsByClassName('green')[0];
  var color_blue = document.getElementsByClassName('blue')[0];
  var color_yellow = document.getElementsByClassName('yellow')[0];

  color_brown.addEventListener("mouseover", function(event) {
    document.getElementsByClassName('selected')[0].textContent = 'brown';
  });
  color_green.addEventListener("mouseover", function(event) {
    document.getElementsByClassName('selected')[0].textContent = 'green';
  });
  color_blue.addEventListener("mouseover", function(event) {
    document.getElementsByClassName('selected')[0].textContent = 'blue';
  });
  color_yellow.addEventListener("mouseover", function(event) {
    document.getElementsByClassName('selected')[0].textContent = 'yellow';
  });

  color_change = document.createElement('div');
  color_change.className = 'random';
  document.getElementsByTagName('section')[0].appendChild(color_change);
  var ok = setInterval(change_color, 500);

  colors = new Array('purple', 'pink', 'black', 'orange');
    
  tic = 0;

  function change_color(){
    tic = tic % colors.length;
    color_change.style.backgroundColor = colors[tic];
    tic += 1;
  }

});

