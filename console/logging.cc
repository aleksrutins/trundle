#include "logging.hh"

#include <iostream>
#include <cstdlib>

using namespace std;
using namespace trundle::console;

void Logging::Log(int color, std::string level, std::string message) {
    cout << "\e[" << color << 'm' 
         << tag << "::" << level
         << ":\e[0m " << message << endl;
}

void Logging::Info(string message) {
    Log(94, "info", message);
}

void Logging::Warn(string message) {
    Log(33, "warn", message);
}

void Logging::Error(string message) {
    Log(31, "error", message);
}

void Logging::Croak(string message) {
    Log(91, "fatal", message);

    exit(1);
}

