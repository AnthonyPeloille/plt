
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
    }else if(parsedUrl[1] == "game"){
        return this->services[1].get();
    }else if(parsedUrl[1] == "commands"){
        return this->services[2].get();
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
        HttpStatus code;
        if(parsedUrl.size()>2){
            code = findService(url)->get(vout,std::stoi(parsedUrl[2]));
        }else{
            code = findService(url)->get(vout,NULL);
        }
        Json::FastWriter fastWriter;
        out = fastWriter.write(vout);
        return code;
   }else if(method == "POST"){
        Json::Value vin;
        Json::Reader reader;
        bool parsingSuccessful = reader.parse( in.c_str(), vin );     //parse process
        if ( !parsingSuccessful )
        {
            return BAD_REQUEST;
        }
        if(parsedUrl.size() > 2){
            return findService(url)->post(vin,std::stoi(parsedUrl[2]));
        }else{
            return BAD_REQUEST;
        }
   }else if(method == "PUT"){
        Json::Value vout;
        Json::Value vin;
        Json::Reader reader;

        bool parsingSuccessful = reader.parse( in.c_str(), vin );     //parse process
        if ( !parsingSuccessful )
        {
           return BAD_REQUEST;
        }
        HttpStatus code = findService(url)->put(vout,vin);
        Json::FastWriter fastWriter;
        out = fastWriter.write(vout);
        return code;
   }else if(method == "DELETE"){
        return findService(url)->remove(std::stoi(parsedUrl[2]));
   }else{
       return BAD_REQUEST;
   }
}