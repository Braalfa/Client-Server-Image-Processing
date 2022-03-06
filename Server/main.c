#include "ImageProcessing/imageProcessing.h"
#include "Logging/logging.h"
#include "serverController/serverController.h"
int main(int argc,char **argv)
{
  initializeLogFile();
  printf("Pixeles mayores al threshold: %ld \n\n", obtainPixelsBiggerThanThreshold("Images/img.jpeg", 230));
  createServer();
  return(0);
}
