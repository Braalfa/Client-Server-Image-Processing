#include "client.h"

void sendImageData() {

    int response;
        
       
        ulfius_init_request(&connRequest);
            
        ulfius_set_request_properties(&connRequest,
                                        U_OPT_HTTP_VERB, "POST",
                                        U_OPT_HTTP_URL, dynamicURL,
                                        U_OPT_JSON_BODY, imageDataJson,
                                        U_OPT_NONE);

        ulfius_init_response(&resRequest);

        response = ulfius_send_http_request(&connRequest, &resRequest);
        if (response == U_OK) {
            json_t *jsonResult = ulfius_get_json_body_response(&resRequest, NULL);
            if(jsonResult != NULL){
                json_t *jsonPixelValue = json_object_get(jsonResult, "pixelsApproved");
                int pixelValue = json_integer_value(jsonPixelValue);
                printf("La respuesta del servidor es %d\n", pixelValue);
                json_decref(jsonPixelValue);
                json_decref(jsonResult);
            }
            else{
                printf("Hubo un error al recibir la respuesta del servidor\n");
            }
        }
        else {
            printf("Failed to send image to server\n");
            exit(EXIT_FAILURE);
        }

        ulfius_clean_response(&resRequest);
        ulfius_clean_request(&connRequest);

}




