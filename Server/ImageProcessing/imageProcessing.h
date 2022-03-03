#ifndef __IMAGE_PROCESSING_H
#define __IMAGE_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MagickWand/MagickWand.h>


#define STR_LEN 200

long obtainPixelsBiggerThanThreshold(char* imagePath, int threshold);

#endif
