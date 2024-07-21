#pragma once
#include <sqlite3.h>
#include "console/console.hh"

namespace trundle::web {
    class DB : private trundle::console::Logging {
        sqlite3* client;
    public:
        DB();
        ~DB();

        auto Client() -> sqlite3*;
    };
}