#include "imageProcessing.h"

struct SimplePixel {
   int  red;
   int  green;
   int  blue;
} ;  

typedef struct SimplePixel SimplePixel;
float changeValueTo8Bits(int value, int originalDepth);
SimplePixel changePixelDepthTo8Bits(PixelInfo* pixel);
int isSimplePixelBiggerThanThreshold(SimplePixel pixel, int threshold);
MagickWand* getImage(char* path);
void endImageProcessing(MagickWand* image);
long countPixelsBiggerThanThreshold(MagickWand *image, int threshold);

long obtainPixelsBiggerThanThreshold(char* imagePath, int threshold)
{
  MagickWand* image = getImage(imagePath);
  long pixelsBiggerThanThreshold = countPixelsBiggerThanThreshold(image, threshold);
  endImageProcessing(image);
  return pixelsBiggerThanThreshold;
}

MagickWand* getImage(char* path){
  MagickBooleanType status;
  MagickWand *image;

  MagickWandGenesis();
  image=NewMagickWand();
  status=MagickReadImage(image, path);
  if (status == MagickFalse)
    printf("Unexpected error");

  return image;
}

void endImageProcessing(MagickWand* image){
  MagickBooleanType status;
  image=DestroyMagickWand(image);
  if (status == MagickFalse)
    printf("Unexpected error");
  MagickWandTerminus();
}

long countPixelsBiggerThanThreshold(MagickWand *image, int threshold){
  PixelInfo pixel;
  unsigned long width;

  long pixelsBiggerThanThreshold = 0;
  PixelIterator *iterator=NewPixelIterator(image);
  if (iterator == (PixelIterator *) NULL)
    printf("Unexpected error");
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

float changeValueTo8Bits(int value, int originalDepth){
  return value*(pow(2,8)-1)/(pow(2,originalDepth)-1);
}
