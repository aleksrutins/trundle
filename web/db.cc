#include "db.hh"

#include <filesystem>

using namespace trundle::web;
using namespace trundle::console;

DB::DB() : Logging("db") {
    std::filesystem::create_directories("data");

    if(sqlite3_open("data/data.db", &client) != SQLITE_OK) Croak("failed to open database");
}

DB::~DB() {
    sqlite3_close(client);
}

sqlite3 *DB::Client() {
    return client;
}