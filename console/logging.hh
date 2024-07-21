#pragma once
#include <string>

namespace trundle::console {
    struct Logging {
        Logging(std::string tag) : tag(tag) {}

        void Log(int color, std::string level, std::string);

        void Info(std::string);
        void Warn(std::string);
        void Error(std::string);
        void Croak(std::string);
    
    private:
        const std::string tag;
    };
}