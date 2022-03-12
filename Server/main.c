#include "ImageProcessing/imageProcessing.h"
#include "Logging/logging.h"
#include "serverController/serverController.h"
int main(int argc,char **argv)
{
  logString("Iniciando main");
  createServer();
  return(0);
}
 
