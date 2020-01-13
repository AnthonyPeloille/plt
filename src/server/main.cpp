#include <iostream>
#include <microhttpd.h>
#include <cstring>
#include "server/ServicesManager.h"
#include "server/PlayerService.h"

#define PORT 8888
#define GET 0
#define POST 1

using namespace std;
using namespace server;

ServicesManager* manager = new ServicesManager();

struct connection_info_struct
{
    int connectiontype;
    char *answerstring;
    struct MHD_PostProcessor *postprocessor;
};

static int
iterate_post (void *coninfo_cls, enum MHD_ValueKind kind, const char *key,
              const char *filename, const char *content_type,
              const char *transfer_encoding, const char *data,
              uint64_t off, size_t size)
{
    struct connection_info_struct *con_info = static_cast<connection_info_struct *>(coninfo_cls);

    if (0 == strcmp (key, "name"))
    {
        if ((size > 0) && (size <= 1024))
        {
            char *answerstring;
            answerstring = static_cast<char *>(malloc(1024));
            if (!answerstring) return MHD_NO;

            snprintf (answerstring, 1024, "test", data);
            con_info->answerstring = answerstring;
        }
        else con_info->answerstring = NULL;

        return MHD_NO;
    }

    return MHD_YES;
}

static void
request_completed (void *cls, struct MHD_Connection *connection,
                   void **con_cls, enum MHD_RequestTerminationCode toe)
{
    struct connection_info_struct *con_info = static_cast<connection_info_struct *>(*con_cls);
    (void)cls;         /* Unused. Silent compiler warning. */
    (void)connection;  /* Unused. Silent compiler warning. */
    (void)toe;         /* Unused. Silent compiler warning. */

    if (NULL == con_info)
        return;

    if (con_info->connectiontype == POST)
    {
        MHD_destroy_post_processor (con_info->postprocessor);
        if (con_info->answerstring)
            free (con_info->answerstring);
    }

    free (con_info);
    *con_cls = NULL;
}


int answer_to_connection (void *cls, struct MHD_Connection *connection,
                          const char *url,
                          const char *method, const char *version,
                          const char *upload_data,
                          size_t *upload_data_size, void **con_cls)
{
    if(NULL == *con_cls) {
        struct connection_info_struct *con_info;

        con_info = static_cast<connection_info_struct *>(malloc(sizeof(struct connection_info_struct)));
        if (NULL == con_info) return MHD_NO;
        con_info->answerstring = NULL;
        if ((0 == strcmp (method, "POST")) or (0 == strcmp (method, "PUT")))
        {
            con_info->postprocessor
                    = MHD_create_post_processor (connection, 1024,
                                                 iterate_post, (void*) con_info);

            if (NULL == con_info->postprocessor)
            {
                free (con_info);
                return MHD_NO;
            }
            con_info->connectiontype = POST;
        }
        else con_info->connectiontype = GET;
        *con_cls = (void*) con_info;
        return MHD_YES;
    }
    if ((0 == strcmp (method, "GET")) or (0 == strcmp (method, "DELETE"))) {
        struct MHD_Response *response;
        int ret;
        std::string out, in;
        HttpStatus code = manager->queryService(out, in, url, method);
        //cout << out.c_str() << endl;
        //cout << "length : " << out.length() << endl;
        response = MHD_create_response_from_buffer(out.length(),
                                                   (void *) out.c_str(), MHD_RESPMEM_MUST_COPY);
        ret = MHD_queue_response(connection, code, response);
        MHD_destroy_response(response);

        return ret;
    }
    if ((0 == strcmp (method, "POST")) or (0 == strcmp (method, "PUT")))
    {
        struct connection_info_struct *con_info = static_cast<struct connection_info_struct *>(*con_cls);
        static HttpStatus code;
        static struct MHD_Response *response;

        if (*upload_data_size != 0)
        {
            MHD_post_process (con_info->postprocessor, upload_data,
                              *upload_data_size);
            *upload_data_size = 0;
            std::string out, in;
            code = manager->queryService(out, upload_data, url, method);
            response = MHD_create_response_from_buffer(out.length(),
                                                       (void *) out.c_str(), MHD_RESPMEM_MUST_COPY);
            //cout << upload_data << endl;
            //cout << "length : " << out.length() << endl;
            return MHD_YES;
        }
        else{
            int ret;
            ret = MHD_queue_response(connection, code, response);
            MHD_destroy_response(response);
            return ret;
        }

    }
}

int main(int argc,char* argv[])
{

    Game game = Game();

    manager->registerService(unique_ptr<PlayerService>(new PlayerService(game)));

    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon (MHD_USE_INTERNAL_POLLING_THREAD, PORT, NULL, NULL,
                               &answer_to_connection, NULL,
                               MHD_OPTION_NOTIFY_COMPLETED, &request_completed, NULL,
                               MHD_OPTION_END);
    if (NULL == daemon) return 1;

    getchar ();

    MHD_stop_daemon (daemon);
    return 0;
}
