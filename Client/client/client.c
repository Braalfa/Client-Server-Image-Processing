#include "client.h"

void *sendImageData() {

    int response;

    while(1){

        pthread_mutex_lock(&bloqueo);
        if(stop == 1){
            pthread_mutex_unlock(&bloqueo);
            break;
        }
        pthread_mutex_unlock(&bloqueo);
        ulfius_init_request(&connRequest);
            
        ulfius_set_request_properties(&connRequest,
                                        U_OPT_HTTP_VERB, "POST",
                                        U_OPT_HTTP_URL, dynamicURL,
                                        U_OPT_JSON_BODY, imageDataJson,
                                        U_OPT_NONE);

        ulfius_init_response(&resRequest);

        response = ulfius_send_http_request(&connRequest, &resRequest);
        if (response == U_OK) {
            printf("Image sent server\n");
        }
        else {
            printf("Failed to send image to server\n");
            exit(EXIT_FAILURE);
        }

        ulfius_clean_response(&resRequest);
        ulfius_clean_request(&connRequest);
    }
    pthread_exit(NULL);

}




