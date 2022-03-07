#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client/client.h"
#include <pthread.h>


//Funciones utilizadas por el main
void makePathToImage(char *imagePath);
void readPathToImage();
void makeIpPort(char *port, char *ip);

int main(int argumentAmount, char* argumentValue[]) {
    int pixelNumber = -1;
    char ip[25] = "";
    char imagePath[200] = "";
    char port[25] = "";
    stop = 0;
    pthread_mutex_init(&bloqueo, NULL);
    

     for (int i = 0; i < argumentAmount; i++) {
        if(strcmp(argumentValue[i], "-ip") == 0){
            strcpy(ip, argumentValue[i + 1]);
        }
        if(strcmp(argumentValue[i], "-pn") == 0){
            pixelNumber = atoi(argumentValue[i + 1]);
        }
        if(strcmp(argumentValue[i], "-port") == 0){
            strcpy(port, argumentValue[i + 1]);
        }
        if(strcmp(argumentValue[i], "-imp") == 0){
            strcpy(imagePath, argumentValue[i + 1]);
        }


    }
    //Verificar si los argumentos se pasaron coreectamente
    if (pixelNumber == -1 || strcmp(ip, "") == 0|| strcmp(imagePath, "") == 0 || strcmp(port, "") == 0) {
        printf("Fue imposible conectarse al servidor. Argumentos faltantes o erroneos\n");
        return 1;
    }
    
    makePathToImage(imagePath);
    system(imageLinkToServer);
    makeIpPort(port, ip);

    //Creacion del Json para enviar la imagen
    imageDataJson = json_object();
    json_object_set_new(imageDataJson, "image", json_string(encondedContent));
    json_object_set_new(imageDataJson, "pixelValue", json_integer(pixelNumber));

    //Creacion de los hilos para el cliente
    pthread_t supervisor;
    pthread_create(&supervisor,NULL, sendImageData, NULL);

    //Ciclo de envio de datos con los threads
    char userInput[10];
    printf("En caso de querer terminar el programa digitar end\n");
    while(1){
        scanf("%s", userInput);
        if(strcmp(userInput, "end") == 0){
            pthread_mutex_lock(&bloqueo);
            stop = 1;
            pthread_mutex_unlock(&bloqueo);
            pthread_join(supervisor, NULL);
            break;
        }

    }



    //Liberacion de memoria dinamica
    free(imageLinkToServer);
    free(dynamicURL);
    free(encondedContent);
    json_decref(imageDataJson);
    pthread_mutex_destroy(&bloqueo);



    return 0;
    
    

}

//Codigo que genera el comando de terminal necesario para determinar la ruta dinamica de la imagen
void makePathToImage(char *imagePath){
    char *firstPart = "base64 ";
    char *secondPartImage = " > encondedImage.txt";

    imageLinkToServer = malloc(strlen(firstPart) + strlen(imagePath) + strlen(secondPartImage) + 1);


    strcpy(imageLinkToServer, firstPart);
    strcat(imageLinkToServer, imagePath);
    strcat(imageLinkToServer, secondPartImage);
}

//Codigo que toma el arhivo, lee su contenido y lo serializa desde base64 a String
void readPathToImage(){
    FILE *base64Image = fopen("encondedImage.txt", "r");
    char line[121];
    char **readData = NULL;
    int lineLenght;
    int lineAmount = 0;
    unsigned long amountOfChars = 0;

    while (fgets(line, 120, base64Image)) {
        readData = realloc(readData, (lineAmount + 1) * sizeof(char*));
        line[strcspn(line, "\n")] = 0;
        lineLenght = strlen(line);
        readData[lineAmount] = calloc(sizeof(char), lineLenght + 1);
        strcpy(readData[lineAmount], line);
        lineAmount++;
        amountOfChars += lineLenght;
    }

    fclose(base64Image);

    encondedContent = malloc(amountOfChars + 1);
    strcpy(encondedContent, readData[0]);
    free(readData[0]);

    for (int i = 1; i < lineAmount; i++) {
        strcat(encondedContent, readData[i]);
        free(readData[i]);
    }

    free(readData);
    remove("encondedImage.txt");
}

//Codigo que arma el IP y el puerto de manera dinamica segun el input del usuario
void makeIpPort(char *port, char *ip){
    char *firstPart = "http://";
    char *secondPartImage = "/api/imagePixels";
    char *dots = ":";

    dynamicURL = malloc(strlen(firstPart) + strlen(ip)+ strlen(dots)+ strlen(port) + strlen(secondPartImage) + 1);


    strcpy(dynamicURL, firstPart);
    strcat(dynamicURL, ip);
    strcat(dynamicURL, port);
    strcat(dynamicURL, secondPartImage);

}    