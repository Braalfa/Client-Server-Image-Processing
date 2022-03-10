# Color client image building automatic batch entrypoint for Linux

echo "====== WELCOME TO COLOR CLIENT ======"
echo "1. Deleting previous image..."
docker image rm color-client
echo "- PREVIOUS IMAGE DELETED -"
echo "====================================="

# Build docker image
echo "2. Building new Docker image from source..."
make clean
make
docker build -t color-client .
echo "- DOCKER IMAGE BUILT -"
echo "====================================="

# Create container and run it temporarily
echo "3. Creating container..."
echo "Starting program:"
docker run -it --rm color-client
echo "-- CONTAINER EXITED --"