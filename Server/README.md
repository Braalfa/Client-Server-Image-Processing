## Dependencias

imagemagick: https://imagemagick.org/script/install-source.php#linux

## Pasos para ejecutar main.c

### Por consola
cc -g main.c ImageProcessing/imageProcessing.c Logging/logging.c -o main -fdiagnostics-color=always -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/include/ImageMagick-7 -L/usr/local/lib -lMagickWand-7.Q16HDRI -lMagickCore-7.Q16HDRI -lm -ldl

./main

## En vscode

1. Abrir main.c
2. Run -> Run Withouth Debugging