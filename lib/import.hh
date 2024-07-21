#pragma once
#include "trundle.hh"

namespace trundle::import {
    struct ModuleSpecifier {
        bool Remote;
        std::string PathOrURL;

        ModuleSpecifier(std::string& specifier);

        auto Fetch() -> std::promise<std::string>;
    };

    auto Parse(std::istream& source) -> std::vector<ModuleSpecifier>;
}