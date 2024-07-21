#pragma once
#include "trundle.hh"

namespace trundle::util {
    namespace string {
        // Trimming: https://cplusplus.com/forum/beginner/208971/#msg983685
        inline std::string TrimFront(const std::string& src) {
            std::size_t pos = 0;
            while(pos < src.size() && std::isspace(src[pos])) pos++;
            return src.substr(pos);
        }

        inline std::string TrimEnd(const std::string& src) {
            std::string res = src;
            while(!res.empty() && isspace(res.back())) res.pop_back();
            return res;
        }

        inline std::string Trim(const std::string& src) {
            return TrimFront(TrimEnd(src));
        }
    }
}