var SCREEN_HEIGHT = screen.height;
var SCREEN_WIDTH = screen.width;

var CAR_WIDTH = 4;
var LANE_WIDTH = 8;

var renderer = PIXI.autoDetectRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, { antialias: true });
var cars = [];
var roads = [];

document.body.appendChild(renderer.view);

// create the root of the scene graph
var stage = new PIXI.Container();
stage.interactive = true;

var graphics = new PIXI.Graphics();
graphics.beginFill(0xFFFF00);
graphics.lineStyle(5, 0xFF0000);
graphics.drawRect(0, 0, 300, 200);
stage.addChild(graphics);

var container = new PIXI.Container();
stage.addChild(container);

function initializeCars(numCars) {
  for (var i = numCars; i >= 0; i--) {
    var x = Math.random() * SCREEN_WIDTH;
    var y = Math.random() * SCREEN_HEIGHT;

    var colour;
    var randNum = Math2.random(0,100);
    if (randNum >= 80) {
      colour = 'red';
    } else if (randNum >= 60) {
      colour = 'green';
    } else if (randNum >= 40) {
      colour = 'purple';
    } else if (randNum >= 20) {
      colour = 'blue';
    } else {
      colour = 'yellow';
    }

    car = new PIXI.Sprite.fromImage(colour + '-car.png');
    car.position.x = x;
    car.position.y = y;
    car.anchor.y = 1;
    car.scale.y = 1;
    cars.push(car);

    container.addChild(car);
  }
}

function initialize() {
  drawAllRoads();
  $.when( initializeCars(10000) ).then(animate());
}

function drawAllRoads() {

}

function drawRoad(x1, x2, y1, y2) {
  graphics.moveTo(x1, y2);
  graphics.lineTo(x1, y2);
  graphics.lineTo(x2, y2);
  graphics.lineTo(x2, y2);
  graphics.lineTo(x1, y2);
  graphics.endFill();
}

function drawIntersection() {

}

function drawCar(pt) {

}

function animate() {
  renderer.render(stage);

  for (var i = cars.length - 1; i >= 0; i--) {
    if (cars[i].position.x < SCREEN_WIDTH) cars[i].position.x++;
  };

  requestAnimationFrame( animate );
}

$(document).ready(initialize());
