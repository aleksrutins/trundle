#include <iostream>

#include "console/logging.hh"
#include "httplib.h"
#include "db.hh"
#include "console/console.hh"

using namespace std;
using namespace trundle::web;
using namespace trundle::console;

int main(void) {
    Logging log("web");

    httplib::Server svr;

    log.Info("initializing database");
    DB db = DB();

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello World!", "text/plain");
    });

    log.Info("starting server on http://localhost:8080");
    svr.listen("0.0.0.0", 8080);
}