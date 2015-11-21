var SCREEN_HEIGHT = screen.height;
var SCREEN_WIDTH = screen.width;

var CAR_WIDTH = 4;
var LANE_WIDTH = 8;

var renderer = PIXI.autoDetectRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, { antialias: true });
var cars = [new Point(100, 100), new Point(200, 200), new Point(300, 300)];

document.body.appendChild(renderer.view);

// create the root of the scene graph
var stage = new PIXI.Container();

stage.interactive = true;

var graphics = new PIXI.Graphics();

// set a fill and line style
graphics.beginFill(0xFF3300);
graphics.lineStyle(10, 0xffd900, 1);

// draw a shape
// graphics.moveTo(50,50);
// graphics.lineTo(250, 50);
// graphics.lineTo(100, 100);
// graphics.lineTo(250, 220);
// graphics.lineTo(50, 220);
// graphics.lineTo(50, 50);
// graphics.endFill();

// // set a fill and line style again
// graphics.lineStyle(10, 0xFF0000, 0.8);
// graphics.beginFill(0xFF700B, 1);

// // draw a second shape
// graphics.moveTo(210,300);
// graphics.lineTo(450,320);
// graphics.lineTo(570,350);
// graphics.quadraticCurveTo(600, 0, 480,100);
// graphics.lineTo(330,120);
// graphics.lineTo(410,200);
// graphics.lineTo(210,300);
// graphics.endFill();

// // draw a rectangle
// graphics.lineStyle(2, 0x0000FF, 1);
// graphics.drawRect(50, 250, 100, 100);

// // draw a circle
// graphics.lineStyle(0);
// graphics.beginFill(0xFFFF0B, 0.5);
// graphics.drawCircle(470, 200,100);
// graphics.endFill();

// graphics.lineStyle(20, 0x33FF00);
// graphics.moveTo(30,30);
// graphics.lineTo(600, 300);


stage.addChild(graphics);

// let's create a moving shape
var thing = new PIXI.Graphics();
stage.addChild(thing);
thing.position.x = SCREEN_WIDTH/2;
thing.position.y = SCREEN_HEIGHT/2;

var count = 0;

// // Just click on the stage to draw random lines
// stage.on('click', onClick);
// stage.on('tap', onClick);

// function onClick()
// {
//     graphics.lineStyle(Math.random() * 30, Math.random() * 0xFFFFFF, 1);
//     graphics.moveTo(Math.random() * SCREEN_WIDTH,Math.random() * SCREEN_HEIGHT);
//     graphics.bezierCurveTo(Math.random() * SCREEN_WIDTH,Math.random() * SCREEN_HEIGHT,
//                             Math.random() * SCREEN_WIDTH,Math.random() * SCREEN_HEIGHT,
//                             Math.random() * SCREEN_WIDTH,Math.random() * SCREEN_HEIGHT);
// }

function Point(x, y) {
  this.x = x;
  this.y = y;
}

function drawAllRoads(roadsArray) {

}

function drawRoad(pt1, pt2) {
  graphics.moveTo(pt1.x,pt1.y);
  graphics.lineTo(pt1.x, pt2.y);
  graphics.lineTo(pt2.x, pt2.y);
  graphics.lineTo(pt2.x, pt1.y);
  graphics.lineTo(pt1.x, pt1.y);
  graphics.endFill();
}

function drawIntersection() {

}

function drawCar(pt) {

}

// run the render loop
animate();

function animate() {

    thing.clear();

    count += 0.1;

    thing.clear();
    thing.lineStyle(10, 0xff0000, 1);
    thing.beginFill(0xffFF00, 0.5);

    thing.moveTo(-120 + Math.sin(count) * 20, -100 + Math.cos(count)* 20);
    thing.lineTo( 120 + Math.cos(count) * 20, -100 + Math.sin(count)* 20);
    thing.lineTo( 120 + Math.sin(count) * 20, 100 + Math.cos(count)* 20);
    thing.lineTo( -120 + Math.cos(count)* 20, 100 + Math.sin(count)* 20);
    thing.lineTo( -120 + Math.sin(count) * 20, -100 + Math.cos(count)* 20);
    thing.endFill();

    thing.lineStyle(10, 0xffa130, 1);
    for (var i = 2; i >= 0; i--) {
      // uses radius
      thing.drawCircle(cars[i].x, cars[i].y, CAR_WIDTH/2);
    };
    thing.endFill();

    renderer.render(stage);
    requestAnimationFrame( animate );
}
