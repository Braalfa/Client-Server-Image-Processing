#include "imageProcessing.h"

int main(int argc,char **argv)
{
  printf("Pixeles mayores al threshold: %ld \n\n", obtainPixelsBiggerThanThreshold("img.jpeg", 230));
  return(0);
}
