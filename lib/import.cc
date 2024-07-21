#include "trundle.hh"
#include "import.hh"

using namespace std;

auto trundle::import::Parse(istream& source) -> vector<ModuleSpecifier>
{
    vector<ModuleSpecifier> imports;
    string line;

    while(!source.eof()) {
        getline(source, line);

        if(line.starts_with("import")) {
            auto specifier = util::string::Trim(line.substr(sizeof("import")));
            imports.push_back(ModuleSpecifier(specifier));
        }
    }

    return imports;
}

trundle::import::ModuleSpecifier::ModuleSpecifier(string& specifier)
{
    if(specifier[0] == '/' || specifier[0] == '.') {
        Remote = false;

        if(specifier.ends_with(".sh")) {
            PathOrURL = specifier;
        } else {
            PathOrURL = filesystem::path(specifier) / "mod.sh";
        }
    } else {
        Remote = true;

        if(specifier.find("://") != string::npos) {
            if(specifier.ends_with(".sh")) {
                PathOrURL = specifier;
            } else {
                PathOrURL = filesystem::path(specifier) / "mod.sh";
            }
        } else if(specifier.find("/") != string::npos) {
            if(specifier.ends_with(".sh")) {
                PathOrURL = specifier;
            } else {
                PathOrURL = filesystem::path(specifier) / "mod.sh";
            }
        }
    }
}

auto trundle::import::ModuleSpecifier::Fetch() -> std::promise<std::string>
{
    return std::promise<std::string>();
}
