:: Color client automatic batch entrypoint
@ECHO OFF

:: Remove previous image of color-client
ECHO ====== WELCOME TO COLOR CLIENT ======
ECHO 1. Deleting previous image...
docker image rm color-client
ECHO - PREVIOUS IMAGE DELETED -
ECHO =====================================

:: Build docker image
ECHO 2. Building new Docker image from source...
docker build -t color-client .
ECHO - DOCKER IMAGE BUILT -
ECHO =====================================

:: Run container using new image
ECHO 3. Running container from new image...
docker run -it --rm color-client