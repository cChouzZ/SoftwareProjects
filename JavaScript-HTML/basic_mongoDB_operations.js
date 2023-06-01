// connects to mongodb and lists all known databases
// const { MongoClient } = require("mongodb")
// // Define connection string
// const uri = "mongodb://127.0.0.1"
// // Create the MongoClient instance
// const client = new MongoClient(uri)
// // Establishes a connection to the database using the MongoClient instance
// const main = async () => {
// try {
// await client.connect()
// console.log("Connected to MongoDB ...")
// const dbs = await client.db().admin().listDatabases() // list out all databases
// console.table(dbs.databases)
// } catch (error) { console.error(error) }
// finally { await client.close() }
// }
// // Run function, catch any errors and finally close the connection
// main().catch((err) => console.log(err))
// .finally(() => client.close())

// insert document to database
// const { MongoClient } = require("mongodb");
// // Defining the DB instance, database, and collection
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// const sampleAccount = {
//   account: "Bill Gates II",
//   account_id: "ACC234890",
//   account_type: "checking",
//   balance: 34567000,
//   last_update: new Date(),
// };
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = await accountsCollection.insertOne(sampleAccount);
//     console.log(`Inserted document: ${result.insertedId}`);
//   } catch (err) {
//     console.error(`Error inserting document: ${err}`);
//   } finally {
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// insert multiple document to database
// const { MongoClient } = require("mongodb");
// // Defining the DB instance, database, and collection
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// const sampleAccounts = [
//   {
//     account: "Sergey Brin II",
//     account_id: "ACC4572321",
//     account_type: "checking",
//     balance: 9776751,
//     last_update: new Date(),
//   },
//   {
//     account: "Larry Page II",
//     account_id: "ACC111752",
//     account_type: "savings",
//     balance: 289546001,
//     last_update: new Date(),
//   },
// ];
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = await accountsCollection.insertMany(sampleAccounts);
//     console.log(`Inserted document: ${result.insertedCount} documents`);
//     console.log(result);
//   } catch (err) {
//     console.error(`Error inserting document: ${err}`);
//   } finally {
//     console.log("Closing connection");
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// find a item from collection single
// const { MongoClient } = require("mongodb");
// // Defining the DB instance, database, and collection
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// const documentsToFind = { balance: { $gt: 10555000 } };
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = accountsCollection.find(documentsToFind);
//     let docCount = accountsCollection.countDocuments(documentsToFind);
//     await result.forEach((doc) => console.log(doc));
//     console.log(`Found ${await docCount} documents`);
//   } catch (err) {
//     console.error(`Error finding document: ${err}`);
//   } finally {
//     console.log("Closing connection");
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// Find example 2 using object
// const { MongoClient } = require("mongodb");
// var ObjectId = require("mongodb").ObjectId;
// const documentToFind = { _id: new ObjectId("64111a5b4e14ba9e4b68fdf0") };
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = await accountsCollection.find(documentToFind);
//     await result.forEach((doc) => console.log(doc));
//   } catch (err) {
//     console.error(`Error finding document: ${err}`);
//   } finally {
//     console.log("Closing connection");
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// Updated a single document
// const { MongoClient } = require("mongodb");
// var ObjectId = require("mongodb").ObjectId;
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// const documentToUpdate = { _id: new ObjectId("64111a5b4e14ba9e4b68fdf0") };
// const update = { $inc: { balance: 100 } };
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = await accountsCollection.updateOne(documentToUpdate, update);
//     result.modifiedCount == 1
//       ? console.log("updated one document")
//       : console.log("No documents updated");
//   } catch (err) {
//     console.error(`Error inserting document: ${err}`);
//   } finally {
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// // Updates multiple documents
// const { MongoClient } = require("mongodb");
// var ObjectId = require("mongodb").ObjectId;
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// const documentsToUpdate = { account_type: "checking" };
// const update = { $push: { transfers_complete: "TR123" } };
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = await accountsCollection.updateMany(documentsToUpdate, update);
//     result.modifiedCount > 0
//       ? console.log(`updated ${result.modifiedCount} docs`)
//       : console.log("No documents updated");
//   } catch (err) {
//     console.error(`Error inserting document: ${err}`);
//   } finally {
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// Delete document
// const { MongoClient } = require("mongodb");
// var ObjectId = require("mongodb").ObjectId;
// const uri = "mongodb://127.0.0.1";
// const client = new MongoClient(uri);
// const dbname = "bookstore";
// const collectionName = "bank";
// async function connectToDatabase() {
//   // Establish a connection to the database
//   try {
//     await client.connect();
//     console.log("Connected to MongoDB ...");
//   } catch (error) {
//     console.error(`error connecting to ${dbname} database`);
//   }
// }
// const documentToDelete = { _id: new ObjectId("64112a67a13b87b1feed4de7") };
// main = async () => {
//   try {
//     await connectToDatabase();
//     const accountsCollection = client.db(dbname).collection(collectionName);
//     let result = await accountsCollection.deleteOne(documentToDelete);
//     result.deletedCount == 1
//       ? console.log("Deleted one document")
//       : console.log("No documents deleted");
//   } catch (err) {
//     console.error(`Error deleting document: ${err}`);
//   } finally {
//     await client.close();
//   }
// };
// main()
//   .catch((err) => console.log(err))
//   .finally(() => client.close());

// Delete multiple document example in slide

// Express server with a database in the backend
express = require("express");
const app = express();
const port = 3000;
const bodyParser = require("body-parser");
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
const { MongoClient } = require("mongodb");
// Defining the DB instance, database, and collection
const uri = "mongodb://127.0.0.1";
const client = new MongoClient(uri);
const dbname = "bookstore";
const collectionName = "bank";
async function connectToDatabase() {
  // Establish a connection to the database
  try {
    await client.connect();
    console.log("Connected to MongoDB ...");
  } catch (error) {
    console.error(`error connecting to ${dbname} database`);
  }
}
// get method lists all databases from mongodb to postman
app.get("/accounts", async (req, res) => {
  try {
    const accountsCollection = client.db(dbname).collection(collectionName);
    let result = accountsCollection.find();
    let docCount = accountsCollection.countDocuments();
    let accounts = [];
    await result.forEach((doc) => {
      console.log(doc);
      accounts.push(doc);
    });
    console.log(`Found ${await docCount} documents`);
    res.send(JSON.stringify(accounts));
  } catch (err) {
    console.error(`Error finding document: ${err}`);
  } finally {
    // commented to keep connection open, advised
    // console.log('Closing connection')
    // await client.close()
  }
});
// Using the put method, add something to the body in postman
app.put("/accounts", async (req, res) => {
  docToInsert = {
    account: req.body.account,
    account_id: req.body.account_id,
    account_type: req.body.account_type,
    balance: req.body.balance,
  };
  try {
    const accountsCollection = client.db(dbname).collection(collectionName);
    let result = await accountsCollection.insertOne(docToInsert);
    console.log(`Inserted document: ${result.insertedId}`);
    res.status(200).json(result);
  } catch (err) {
    console.error(`Error inserting document: ${err}`);
  } finally {
    await client.close();
  }
});
app.listen(port, async () => {
  console.log(`Connected to the Express server on port ${port}`);
  await connectToDatabase();
});
