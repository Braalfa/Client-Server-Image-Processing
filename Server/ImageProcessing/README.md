## Dependencias

imagemagick: https://imagemagick.org/script/install-source.php#linux

Path de los headers: /usr/local/include/ImageMagick-7


Compilacion de ejemplo:

gcc -fdiagnostics-color=always -g main.c imageProcessing.c -o main -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -fopenmp -DMAGICKCORE_HDRI_ENABLE=1 -DMAGICKCORE_QUANTUM_DEPTH=16 -I/usr/local/include/ImageMagick-7 -L/usr/local/lib -lMagickWand-7.Q16HDRI -lMagickCore-7.Q16HDRI -lm -ldl