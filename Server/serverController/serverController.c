//
// Created by brayan on 5/3/22.
//
#include "serverController.h"



int processImage (const struct _u_request * request, struct _u_response * response, void * user_data);
int countimagesindirectoy();


//función para crear el servidor RESTAPI por medio de la biblioteca ulfius: https://github.com/babelouest/ulfius
int createServer(){
    struct _u_instance instance;

    // Inicializa la instancia del servidor en el puerto indicado
    if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK) {
        fprintf(stderr, "Error ulfius_init_instance, abort\n");
        return(1);
    }

    // Se define los endpoints que se van a utilizar
    ulfius_add_endpoint_by_val(&instance, "POST", "/api/imagePixels", NULL, 0, &processImage, NULL);
    // se inicia el framework
    if (ulfius_start_framework(&instance) == U_OK) {
        printf("Servidor iniciado en el puerto %d\n", instance.port);
        while (1){}
    } else {
        fprintf(stderr, "Error iniciando el servidor\n");
    }
    printf("Se cierra el servidor\n");

    ulfius_stop_framework(&instance);
    ulfius_clean_instance(&instance);

    return 0;
}

//función que recibe la imagen del cliente y la procesa
int processImage (const struct _u_request * request, struct _u_response * response, void * user_data){
    // obtiene los datos del body del request y los guarda en variables
    json_t *jsonData = ulfius_get_json_body_request(request, NULL);
    json_t * json_body = NULL;
    if (jsonData != NULL) {
        json_t *jsonPixelValue = json_object_get(jsonData, "pixelValue");
        int pixelValue = json_integer_value(jsonPixelValue);

        json_t *jsonImageData = json_object_get(jsonData, "image");
        const char *imageData = json_string_value(jsonImageData);

        //obtiene el valor de las cantidad de imagenes existentes
        int imageIndex=countimagesindirectoy();

        //crea el comando para decodificar las imagenes y guardarlas en el directorio
        char *commandline="base64 --decode /home/brayan/Cursos/Operativos/Tarea1/Server/coded.txt > /home/brayan/Cursos/Operativos/Tarea1/Server/Images/image";

        // verifica cual es el formato de la imagen enviada
        char *extension= malloc(5);
        if (imageData[0] == 'R') strcpy(extension,".gif");
        else if (imageData[0] == '/') strcpy(extension, ".jpg");
        else strcpy(extension,".png");

        char imageIndexString[33];
        sprintf(imageIndexString, "%d", imageIndex);

        FILE *file = fopen("/home/brayan/Cursos/Operativos/Tarea1/Server/coded.txt", "w");
        fputs(imageData, file);
        fclose(file);

        char *commandToDecodeImage= malloc(strlen(commandline)+strlen(extension)+ strlen(imageIndexString)+1);

        strcpy(commandToDecodeImage,commandline);
        strcat(commandToDecodeImage,imageIndexString);
        strcat(commandToDecodeImage,extension);

        //ejecuta el comando creado para guardar la imagen
        system(commandToDecodeImage);

        //se crea la ruta para para la función que verifica los pixeles
        char *directory="/home/brayan/Cursos/Operativos/Tarea1/Server/Images/image";
        char *route= malloc(strlen(directory)+strlen(extension)+ strlen(imageIndexString)+1);
        strcpy(route,directory);
        strcat(route,extension);
        strcat(route,imageIndexString);

        int pixelsApproved=0;
        //llama a la función que cuenta la cantidad de pixeles mayores al valor definido
        //pixelsApproved=verifyPixels(route,pixelValue);

        //se crea el cuerpo del response
        json_body = json_object();
        json_object_set_new(json_body, "pixelsApproved", json_integer(pixelsApproved));
        //se libera el espacio
        json_decref(jsonData);
        json_decref(jsonPixelValue);
        json_decref(jsonImageData);

        printf("Se recibió una imagen");
    } else {
        printf("Error al recibir la imagen, no se encontraron datos");
    }

    //se envia la respuesta al cliente
    ulfius_set_json_body_response(response, 200, json_body);
    json_decref(json_body);

    return U_CALLBACK_CONTINUE;
}

//función para contar la cantidad de archivos(imagenes) que se encuentran en el directorio
//lógica obtenida de https://stackoverflow.com/questions/1121383/counting-the-number-of-files-in-a-directory-using-c
int countimagesindirectoy(){
    int file_count = 0;
    DIR * dirp;
    struct dirent * entry;
    dirp = opendir("/home/brayan/Cursos/Operativos/Tarea1/Server/Images");
    while ((entry = readdir(dirp)) != NULL) {
        if (entry->d_type == DT_REG) {
            file_count++;
        }
    }
    closedir(dirp);
    return file_count;
}
