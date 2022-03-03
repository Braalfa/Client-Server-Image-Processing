#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MagickWand/MagickWand.h>

struct SimplePixel {
   int  red;
   int  green;
   int  blue;
} ;  
typedef struct SimplePixel SimplePixel;

float changeValueTo8Bits(int value, int originalDepth){
  return value*(pow(2,8)-1)/(pow(2,originalDepth)-1);
}

SimplePixel changePixelDepthTo8Bits(PixelInfo* pixel){
  SimplePixel newPixel;
  newPixel.red = changeValueTo8Bits(pixel->red, pixel->depth);
  newPixel.green = changeValueTo8Bits(pixel->green, pixel->depth);
  newPixel.blue = changeValueTo8Bits(pixel->blue, pixel->depth);
  return newPixel;
}

int isSimplePixelBiggerThanThreshold(SimplePixel pixel, int threshold){
  int averagePixelValue = (pixel.blue+pixel.green+pixel.red)/3;
  return averagePixelValue>threshold; 
}

MagickWand* getImage(char* path){
  MagickBooleanType status;
  MagickWand *image;

  MagickWandGenesis();
  image=NewMagickWand();
  status=MagickReadImage(image, path);
  if (status == MagickFalse)
    printf("F");

  return image;
}

void endImageProcessing(MagickWand* image){
  MagickBooleanType status;
  image=DestroyMagickWand(image);
  if (status == MagickFalse)
    printf("F");
  MagickWandTerminus();
}

int countPixelsLessThanThreshold(MagickWand *image, int threshold){
  PixelInfo pixel;
  unsigned long width;

  int pixelsBiggerThanThreshold = 0;
  PixelIterator *iterator=NewPixelIterator(image);
  if (iterator == (PixelIterator *) NULL)
    printf("F");
  for (long y=0; y < (long) MagickGetImageHeight(image); y++)
  {
    PixelWand** pixels=PixelGetNextIteratorRow(iterator,&width);
    if (pixels == (PixelWand **) NULL)
      break;
    for (long x=0; x < (long) width; x++)
    {
      PixelGetMagickColor(pixels[x],&pixel);
      SimplePixel pixel8Bits = changePixelDepthTo8Bits(&pixel);
      if(isSimplePixelBiggerThanThreshold(pixel8Bits, threshold)){
        pixelsBiggerThanThreshold++;
      }
    }
  }
  iterator=DestroyPixelIterator(iterator);
  return pixelsBiggerThanThreshold;
}

int main(int argc,char **argv)
{
  MagickWand* image = getImage("img.jpeg");
  printf("Pixeles mayores al threshold: %i \n\n", countPixelsLessThanThreshold(image, 230));
  endImageProcessing(image);
  return(0);
}