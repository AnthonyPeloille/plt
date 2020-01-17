
#include <SFML/Network.hpp>
#include <json/json.h>
#include "NetworkClient.h"

client::NetworkClient::NetworkClient(std::string &url, int port) {
    this->url = url;
    this->port = port;
}

std::string client::NetworkClient::getGameStatus() {
    sf::Http http;
    http.setHost(this->url, this->port);

    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Put);
    request.setUri("/player");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("From", "me");
    request.setField("Content-Type", "application/x-www-form-urlencoded");
    request.setBody("{\"name\":\"joueur1\"}");

    sf::Http::Response response = http.sendRequest(request);


    sf::Http::Request request2;
    request2.setMethod(sf::Http::Request::Get);
    request2.setUri("/game");
    request2.setHttpVersion(1, 1); // HTTP 1.1
    //request.setField("From", "me");
    //request.setField("Content-Type", "application/x-www-form-urlencoded");
    //request.setBody("json={\"name\":\"joueur1\"}");

    sf::Http::Response response2 = http.sendRequest(request2);

    return response2.getBody();
}

Json::Value client::NetworkClient::putCommand(std::unique_ptr<engine::Command> command) {
    sf::Http http;
    http.setHost(this->url, this->port);

    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Put);
    request.setUri("/commands");
    request.setHttpVersion(1, 1); // HTTP 1.1
    request.setField("From", "me");
    request.setField("Content-Type", "application/x-www-form-urlencoded");
    Json::Value out;
    command->serialize(out);
    Json::FastWriter fastWriter;
    std::string strout = fastWriter.write(out);
    request.setBody("json="+strout);

    sf::Http::Response response = http.sendRequest(request);
    return Json::Value();
}
