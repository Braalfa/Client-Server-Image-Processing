FROM ubuntu:18.04

COPY install.sh /install.sh
COPY ./images/ /images

RUN apt update && apt install -y wget ca-certificates libpsl5 libssl1.1 openssl publicsuffix libmicrohttpd-dev libjansson-dev libcurl4-gnutls-dev libgnutls28-dev libgcrypt20-dev libsystemd-dev && ./install.sh