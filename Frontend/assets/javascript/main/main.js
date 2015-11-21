// create a renderer instance width=640 height=480
var renderer = PIXI.autoDetectRenderer(640,480);

// create an empty container
var gameContainer = new PIXI.Graphics();
   // add the renderer view element to the DOM
document.body.appendChild(renderer.view);

// set background color grey
renderer.backgroundColor = 0x888888;

loadCircles();

function loadCircles(){
  gameContainer.beginFill(255,1);
    gameContainer.drawCircle(10, 10, 10);
  gameContainer.endFill();

  requestAnimationFrame(animate);
}
function animate() {
  requestAnimationFrame(animate);
  renderer.render(gameContainer);
}

function drawRoad() {

}

function drawCar() {
  
}