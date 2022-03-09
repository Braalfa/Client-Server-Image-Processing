#ifndef __CLIENT_H
#define __CLIENT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <jansson.h>
#include <ulfius.h>

struct _u_request connRequest;
struct _u_response resRequest;


json_t *imageDataJson;


char *imageLinkToServer;
char *encondedContent;
char *dynamicURL;


void sendImageData();





#endif