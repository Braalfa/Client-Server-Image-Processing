#include "client.h"

void sendImageData() {

//Se define el int que sera la respuesta del server
    int response;
        
       //Se declara la funcion que pide la conexion
        ulfius_init_request(&connRequest);
        //Se crea la estructura para el post de los datos
        ulfius_set_request_properties(&connRequest,
                                        U_OPT_HTTP_VERB, "POST",
                                        U_OPT_HTTP_URL, dynamicURL,
                                        U_OPT_JSON_BODY, imageDataJson,
                                        U_OPT_NONE);

        //Se inicia la estructura para pedir la repsuesta
        ulfius_init_response(&resRequest);

        //Se analiza la respuesta del servidor
        response = ulfius_send_http_request(&connRequest, &resRequest);
        if (response == U_OK) {
            json_t *jsonResult = ulfius_get_json_body_response(&resRequest, NULL);
            //Se verifica que el servidor haya respondido
            if(jsonResult != NULL){
                json_t *jsonPixelValue = json_object_get(jsonResult, "pixelsApproved");
                int pixelValue = json_integer_value(jsonPixelValue);
                printf("La respuesta del servidor es %d\n", pixelValue);
                json_decref(jsonPixelValue);
                json_decref(jsonResult);
            }
            //No se puede conectar al servidor
            else{
                printf("Hubo un error al recibir la respuesta del servidor\n");
            }
        }
        else {
            printf("Hubo un fallo a la hora de conectarse al server\n");
            exit(EXIT_FAILURE);
        }
        //Se liberan las estructuras creadas anteriormente
        ulfius_clean_response(&resRequest);
        ulfius_clean_request(&connRequest);

}




