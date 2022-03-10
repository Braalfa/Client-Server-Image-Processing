:: Color client image building automatic batch entrypoint
@ECHO OFF

:: Remove previous image of color-client
ECHO ====== WELCOME TO COLOR CLIENT ======
ECHO 1. Creating container...
docker image rm color-client
ECHO - PREVIOUS IMAGE DELETED -
ECHO =====================================

:: Build docker image
ECHO 2. Building new Docker image from source...
docker build -t color-client .
ECHO - DOCKER IMAGE BUILT -
ECHO =====================================

:: Install dependencies in image
ECHO 3. Creating container...
docker run -it --rm color-client
ECHO -- CONTAINER EXITED --
