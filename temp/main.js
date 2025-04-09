const mysql = require('mysql');

function createConnection(hostName, userName, userPassword, dbName) {
    const connection = mysql.createConnection({
        host: hostName,
        user: userName,
        password: userPassword,
        database: dbName
    });

    connection.connect((err) => {
        if (err) {
            console.error(`The error '${err}' occurred`);
            return null;
        }
        console.log("Connection to MySQL DB successful");
    });

    return connection;
}

// Example usage
const connection = createConnection("localhost", "root", "2005", "automobile");
connection.query("SHOW FULL TABLES IN automobile;", (error, results) => {
    if (error) throw error;
    console.log("Tables in the database:", results);
});

connection.query("SHOW TABLE STATUS FROM automobile;", (error, results) => {
    if (error) throw error;
    console.log("Table status information:", results);
});

connection.query("SELECT * FROM information_schema.tables WHERE table_schema = 'automobile';", (error, results) => {
    if (error) throw error;
    console.log("Detailed table information:", results);
});