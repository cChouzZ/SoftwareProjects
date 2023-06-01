express = require("express");
const app = express();
const port = 3000;
const bodyParser = require("body-parser");
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
const { MongoClient } = require("mongodb");
const uri = "mongodb://127.0.0.1";
const client = new MongoClient(uri);
const dbname = "myDB";
const collectionName = "temperature_sensor";
const CollectionName = "humidity_sensor";

async function connectToDatabase() {
  try {
    await client.connect();
    console.log("Connected to MongoDB ...");
  } catch (error) {
    console.error(`error connecting to ${dbname} database`);
  }
}

app.get("/temperature", async (req, res) => {
  target_date = new Date().getTime() - 2 * 60 * 1000;
  const documentsToFind = { time: { $gte: target_date } };
  try {
    const temperatureCollection = client.db(dbname).collection(collectionName);
    let result = temperatureCollection
      .find(documentsToFind)
      .project({ _id: 0, temp: 1 });
    let docCount = temperatureCollection.countDocuments(documentsToFind);
    let temperature = [];
    await result.forEach((doc) => {
      console.log(doc);
      temperature.push(doc);
    });
    console.log(`Found ${await docCount} documents`);
    res.send(JSON.stringify(temperature));
  } catch (err) {
    console.error(`Error inserting document: ${err}`);
  } finally {
    //console.log("Closing connection");
    //await client.close();
  }
});

app.get("/humidity", async (req, res) => {
  target_date = new Date().getTime() - 2 * 60 * 1000;
  const documentsToFind = { time: { $gte: target_date } };
  try {
    const humidityCollection = client.db(dbname).collection(CollectionName);
    let result = humidityCollection
      .find(documentsToFind)
      .project({ _id: 0, humidity: 1 });
    let docCount = humidityCollection.countDocuments(documentsToFind);
    let humidity = [];
    await result.forEach((doc) => {
      console.log(doc);
      humidity.push(doc);
    });
    console.log(`Found ${await docCount} documents`);
    res.send(JSON.stringify(humidity));
  } catch (err) {
    console.error(`Error inserting document: ${err}`);
  } finally {
    //console.log("Closing connection");
    //await client.close();
  }
});

app.get("/averageTemperature", async (req, res) => {
  target_date = new Date().getTime() - 2 * 60 * 1000;
  const documentsToFind = { time: { $gte: target_date } };

  try {
    const temperatureCollection = client.db(dbname).collection(collectionName);
    let result = temperatureCollection
      .find(documentsToFind)
      .project({ _id: 0, temp: 1 });
    let docCount = temperatureCollection.countDocuments(documentsToFind);
    let temperature = [];
    await result.forEach((doc) => {
      console.log(doc);
      temperature.push(doc);
    });

    let sum = 0;
    const average = sum / temperature.length;

    for (let i = 0; i < temperature.length; i++) {
      sum += temperature[i];
    }

    console.log(`The average temperature is: ${average}`);
    res.send(JSON.stringify(average));
    console.log(`Found ${docCount} documents`);
  } catch (err) {
    console.error(`Error inserting document: ${err}`);
  } finally {
    //console.log("Closing connection");
    //await client.close();
  }
});

app.get("/minTemperature", async (req, res) => {
  target_date = new Date().getTime() - 2 * 60 * 1000;
  const documentsToFind = { time: { $gte: target_date } };

  try {
    let temperature = [];
    const temperatureCollection = client.db(dbname).collection(collectionName);
    let result = temperatureCollection
      .find(documentsToFind)
      .project({ _id: 0, temp: 1 });
    let docCount = temperatureCollection.countDocuments(documentsToFind);
    await result.forEach((doc) => {
      console.log(doc);
      temperature.push(doc);
    });

    const minTemp = Math.min(...temperature);

    console.log(`The minimum temperature value is: ${minTemp}`);
    console.log(`Found ${await docCount} documents`);
    res.send(JSON.stringify(minTemp));
  } catch (err) {
    console.error(`Error inserting document: ${err}`);
  } finally {
    //console.log("Closing connection");
    //await client.close();
  }
});

app.get("/deleteTemperature", async (req, res) => {
  target_date = new Date().getTime() - 2 * 60 * 1000;
  const documentsToFind = { time: { $gte: target_date } };

  try {
    const temperatureCollection = client.db(dbname).collection(collectionName);
    let result = await temperatureCollection.deleteOne(documentsToFind);
    result.deletedCount == 1
      ? console.log("Deleted one document")
      : console.log("No documented deleted");
  } catch (err) {
    console.error(`Error inserting document: ${err}`);
  } finally {
    //console.log("Closing connection");
    //await client.close();
  }
});

app.listen(port, async () => {
  console.log(`Connected to the Express server on port ${port}`);
  await connectToDatabase();
});
