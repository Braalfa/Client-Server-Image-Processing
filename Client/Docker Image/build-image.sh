# Color client image building automatic batch entrypoint for Linux

echo "====== WELCOME TO COLOR CLIENT ======"
echo "1. Deleting previous image..."
docker image rm color-client-image
echo "- PREVIOUS IMAGE DELETED -"
echo "====================================="

# Build docker image
echo 2. "Building new Docker image from source..."
chmod +x install.sh
docker build -t color-client-image .
echo "- DOCKER IMAGE BUILT -"
echo "====================================="
