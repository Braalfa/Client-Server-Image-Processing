CC=gcc
CFLAGS=-fdiagnostics-color=always -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/include/ImageMagick-7 -L/usr/local/lib -lMagickWand-7.Q16HDRI -lMagickCore-7.Q16HDRI -lm -ldl -lulfius -ljansson -lpthread

main: main.c ImageProcessing/imageProcessing.c Logging/logging.c serverController/serverController.c
	$(CC) -o main main.c ImageProcessing/imageProcessing.c Logging/logging.c serverController/serverController.c $(CFLAGS)