const mqtt = require("mqtt");
var client = mqtt.connect("mqtt://127.0.0.1");

const dbname = "myDB";
const collectionName = "temperature_sensor";
const CollectionName = "humidity_sensor";

const { MongoClient } = require("mongodb");
const uri = "mongodb://127.0.0.1";
const Client = new MongoClient(uri);

try {
  Client.connect();
  console.log("Connected to MongoDB ...");
} catch (error) {
  console.error(error);
} finally {
  //await client.close();
}

client.on("connect", function () {
  console.log("Connected to broker");
  client.subscribe("/home/temperature");
});

client.on("message", async function (topic, message) {
  if (topic == "/home/temperature") {
    console.log("temperature: ", message.toString());
    const sampleTemperature = {
      time: new Date().getTime(),
      temp: message.toString(),
    };

    try {
      const Collection = Client.db(dbname).collection(collectionName);
      let result = await Collection.insertOne(sampleTemperature);
      console.log(`Inserted document: ${result.insertedId}`);
    } catch (err) {
      console.error(`Error inserting document: ${err}`);
    } finally {
      //await client.close();
    }
  }
});

client.on("connect", function () {
  console.log("Connected to broker");
  client.subscribe("/home/humidity");
});

client.on("message", async function (topic, message) {
  if (topic == "/home/humidity") {
    console.log("humidity: ", message.toString());
    const sampleHumidity = {
      time: new Date().getTime(),
      humidity: message.toString(),
    };

    try {
      const Collection = Client.db(dbname).collection(CollectionName);
      let result = await Collection.insertOne(sampleHumidity);
      console.log(`Inserted document: ${result.insertedId}`);
    } catch (err) {
      console.error(`Error inserting document: ${err}`);
    } finally {
      //await client.close();
    }
  }
});
