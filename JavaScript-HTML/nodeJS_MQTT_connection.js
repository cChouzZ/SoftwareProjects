// connect to mqtt through node.js example
const mqtt = require("mqtt");
var client = mqtt.connect("mqtt://localhost");
client.on("connect", function () {
  client.subscribe("/home/attic");
  client.subscribe("/home/garage");
  console.log("Subscribed to attic and garage");
});
client.on("message", function (topic, message) {
  if (topic == "/home/attic") {
    console.log("attic: ", message.toString());
  } else if (topic == "/home/garage") {
    console.log("garage: ", message.toString());
  }
});

setTimeout(() => {
  client.publish("/home/garage", "open");
}, 3500);
setTimeout(() => {
  client.publish("/home/attic", "motion detected");
}, 2000);
setTimeout(() => {
  client.end();
}, 4000);
