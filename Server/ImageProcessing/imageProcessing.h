#ifndef __IMAGE_PROCESSING_H
#define __IMAGE_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <MagickWand/MagickWand.h>
#include "../Logging/logging.h"

long obtainPixelsBiggerThanThreshold(char* imagePath, int threshold);

#endif
