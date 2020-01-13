
#include <SFML/Network.hpp>
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
    request.setBody("json={\"name\":\"joueur1\"}");

    sf::Http::Response response = http.sendRequest(request);

    return nullptr;
}
