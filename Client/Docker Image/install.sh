#!/bin/bash

# Get stuff and install
wget  https://github.com/babelouest/ulfius/releases/download/v2.7.3/ulfius-dev-full_2.7.3_ubuntu_focal_x86_64.tar.gz
tar xf ulfius-dev-full_2.7.3_ubuntu_focal_x86_64.tar.gz
dpkg -i liborcania-dev_2.2.1_ubuntu_focal_x86_64.deb
dpkg -i libyder-dev_1.4.14_ubuntu_focal_x86_64.deb
dpkg -i libulfius-dev_2.7.3_ubuntu_focal_x86_64.deb

# Remove files
rm ulfius-dev-full_2.7.3_ubuntu_focal_x86_64.tar.gz
rm liborcania-dev_2.2.1_ubuntu_focal_x86_64.deb
rm libulfius-dev_2.7.3_ubuntu_focal_x86_64.deb
rm libyder-dev_1.4.14_ubuntu_focal_x86_64.deb