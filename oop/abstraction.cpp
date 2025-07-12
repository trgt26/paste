#include <iostream>
using namespace std;

// Interface-like abstract class for Database
class IDatabase {
public:
    virtual void connect() = 0;
    virtual void executeQuery(const string& query) = 0;
    virtual void disconnect() = 0;

    virtual ~IDatabase() {}
};

// MySQL implementation of IDatabase interface
class MySQL : public IDatabase {
public:
    void connect() override {
        cout << "Connecting to MySQL database..." << endl;
    }

    void executeQuery(const string& query) override {
        cout << "Executing query on MySQL: " << query << endl;
    }

    void disconnect() override {
        cout << "Disconnecting from MySQL database." << endl;
    }
};

// PostgreSQL implementation of IDatabase interface
class PostgreSQL : public IDatabase {
public:
    void connect() override {
        cout << "Connecting to PostgreSQL database..." << endl;
    }

    void executeQuery(const string& query) override {
        cout << "Executing query on PostgreSQL: " << query << endl;
    }

    void disconnect() override {
        cout << "Disconnecting from PostgreSQL database." << endl;
    }
};

int main() {
    IDatabase* db;

    // Using MySQL database
    db = new MySQL();
    db->connect();
    db->executeQuery("SELECT * FROM users;");
    db->disconnect();
    delete db;

    cout << endl;

    // Using PostgreSQL database
    db = new PostgreSQL();
    db->connect();
    db->executeQuery("SELECT * FROM employees;");
    db->disconnect();
    delete db;

    return 0;
}
