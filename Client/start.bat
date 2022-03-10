:: Color client image building automatic batch entrypoint
@ECHO OFF

:: Remove previous image of color-client
ECHO ====== WELCOME TO COLOR CLIENT ======
ECHO 1. Removing previous image...
docker image rm color-client
ECHO - PREVIOUS IMAGE DELETED -
ECHO =====================================

:: Build docker image
ECHO 2. Building new Docker image from source...
docker build -t color-client .
ECHO - DOCKER IMAGE BUILT -
ECHO =====================================

:: Create container and run it temporarily
ECHO 3. Creating container...
ECHO Starting program:
docker run -it --rm color-client
ECHO -- CONTAINER EXITED --
