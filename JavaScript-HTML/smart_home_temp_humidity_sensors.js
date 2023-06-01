var mqtt = require("mqtt");
var client = mqtt.connect("mqtt://127.0.0.1");
client.on("connect", function () {
  var count = 0;
  var intervalObject = setInterval(() => {
    count++;
    t = Math.floor(Math.random() * 30 + 50);
    h = Math.floor(Math.random() * 30 + 50);
    console.log(t, h);
    client.publish("/home/temperature", "" + t);
    client.publish("/home/humidity", "" + h);
    if (count == 100) {
      console.log("exiting");
      clearInterval(intervalObject);
    }
  }, 2000);
});
