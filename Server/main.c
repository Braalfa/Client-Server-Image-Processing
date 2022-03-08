#include "ImageProcessing/imageProcessing.h"
#include "Logging/logging.h"
#include "serverController/serverController.h"
int main(int argc,char **argv)
{
  initializeLogFile();
  logString("Iniciando main");
  createServer();
  return(0);
}
 