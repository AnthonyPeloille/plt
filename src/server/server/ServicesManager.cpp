
#include "ServicesManager.h"
#include "PlayerService.h"

void server::ServicesManager::registerService(std::unique_ptr <AbstractService> service) {
    this->services.push_back(std::move(service));
}

server::AbstractService *server::ServicesManager::findService(const std::string &url) const {
    std::istringstream ss(url);
    std::string token;

    std::vector<std::string> parsedUrl;
    while(std::getline(ss, token, '/')) {
        parsedUrl.push_back(token);
    }

    if(parsedUrl[1] == "player"){
        return this->services[0].get();
    }else{
        return nullptr;
    }
}

server::HttpStatus server::ServicesManager::queryService(std::string &out, const std::string &in, const std::string &url, const std::string &method) {
    std::istringstream ss(url);
    std::string token;

    std::vector<std::string> parsedUrl;
    while(std::getline(ss, token, '/')) {
        parsedUrl.push_back(token);
    }

    if(method == "GET"){
        Json::Value vout;
        HttpStatus code = findService(url)->get(vout,std::stoi(parsedUrl[2]));
        Json::FastWriter fastWriter;
        out = fastWriter.write(vout);
        return code;
   }else if(method == "PUSH"){

   }else if(method == "PUT"){

   }else if(method == "REMOVE"){

   }else{
       return BAD_REQUEST;
   }
}