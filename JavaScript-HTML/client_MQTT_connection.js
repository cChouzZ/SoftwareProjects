// Connecting mqtt through code through client
// const mqtt = require("mqtt");
// var client = mqtt.connect("mqtt://localhost");
// client.on("connect", function () {
//   client.subscribe("/home/attic");
//   client.subscribe("/home/garage");
//   console.log("Subscribed to attic and garage");
// });
// client.on("message", function (topic, message) {
//   if (topic == "/home/attic") {
//     console.log("attic: ", message.toString());
//   } else if (topic == "/home/garage") {
//     console.log("garage: ", message.toString());
//   }
// });

// example for above through express, web app, with temperature example
const express = require("express"),
  mqtt = require("mqtt");
app = express();
app.listen(3000, function () {
  console.log("App listening on port 3000");
});
app.get("/stream", function (req, res) {
  res.writeHead(200, {
    "Content-Type": "text/event-stream",
    "Cache-Control": "no-cache",
    Connection: "keep-alive",
  });
  res.write("\n");
  var timer = setInterval(() => {
    res.write("#");
  }, 1000);
  var client = mqtt.connect("mqtt://127.0.0.1");
  client.on("connect", () => {
    client.subscribe("/home/temperature", function () {});
  });
  client.on("message", (topic, msg) => {
    res.write(msg);
  });
  req.on("close", () => {
    clearTimeout(timer);
    client.end();
  });
});
