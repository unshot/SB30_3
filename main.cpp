#include <iostream>
#include <map>
#include <vector>
#include <cpr/cpr.h>

void GETRequest(const std::map<std::string, std::string> &args){

    std::string serviceName = "http://httpbin.org/get?";
    for(auto it = args.begin(); it != args.end(); ++it){
        serviceName += it->first + "=" + it->second + "&";
    }

    serviceName = serviceName.substr(0, serviceName.length()-1);
    auto responce = cpr::Get(cpr::Url(serviceName)).text;
    std::cout << responce << "\n";
}

void POSTRequest(const std::map<std::string,std::string> &args){

    std::vector<cpr::Pair> pairs;
    int i = 0;
    for(auto it = args.begin(); it != args.end(); ++it, ++i){
        cpr::Pair pair(it->first, it->second);
        pairs.push_back(pair);
    }

    auto responce = cpr::Post(cpr::Url("http://httpbin.org/post"), cpr::Payload(pairs.begin(), pairs.end())).text;
    std::cout << responce << "\n";
}

int main(){
    std::cout << "#########--Queries with arguments--########\n\n";

    std::map<std::string, std::string> args;
    std::string arg;
    std::getline (std::cin, arg);

    while (arg != "get" && arg != "post"){
        std::string value;
        std::getline (std::cin, value);
        args.insert (std::pair <std::string, std::string> (arg, value));
        std::getline (std::cin, arg);
    }

    if (arg == "get"){
        GETRequest(args);
    }else if (arg == "post"){
        POSTRequest(args);
    }
    return 0;
}
