# Color client automatic batch entrypoint for Linux

echo "====== WELCOME TO COLOR CLIENT ======"
echo "1. Deleting previous image..."
sudo docker image rm color-client
echo "- PREVIOUS IMAGE DELETED -"
echo "====================================="

# Build docker image
echo "2. Building new Docker image from source..."
sudo chmod 777 -R bin
sudo docker build -t color-client .
echo "- DOCKER IMAGE BUILT -"
echo "====================================="

# Run container using new image
echo "3. Running container from new image..."
sudo docker run -it --rm color-client
