#include <iostream>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>
#include "server/ServicesManager.h"
#include "server/PlayerService.h"

#define PORT 8888

using namespace std;
using namespace server;

ServicesManager* manager = new ServicesManager();

int answer_to_connection (void *cls, struct MHD_Connection *connection,
                          const char *url,
                          const char *method, const char *version,
                          const char *upload_data,
                          size_t *upload_data_size, void **con_cls)
{
    struct MHD_Response *response;
    int ret;
    printf ("New %s request for %s using version %s\n", method, url, version);
    std::string out, in;
    HttpStatus code = manager->queryService(out, in, url, method);
    cout << out.c_str() << endl;
    cout << "length : " << out.length() << endl;
    response = MHD_create_response_from_buffer (out.length(),
                                                (void*) out.c_str(), MHD_RESPMEM_MUST_COPY);
    ret = MHD_queue_response (connection, code, response);
    MHD_destroy_response (response);

    return ret;
}

int main(int argc,char* argv[])
{

    Game game = Game();
    std::vector<Player> players;
    Player player;
    player.name = "player 1";
    Player player2;
    player2.name = "player 2";
    players.push_back(player);
    players.push_back(player2);
    game.setPlayers(players);

    manager->registerService(unique_ptr<PlayerService>(new PlayerService(game)));

    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon (MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL,
                               &answer_to_connection, NULL, MHD_OPTION_END);
    if (NULL == daemon) return 1;

    getchar ();

    MHD_stop_daemon (daemon);
    return 0;
}
