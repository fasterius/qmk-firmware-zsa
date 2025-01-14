FROM debian:latest

# Install system dependencies
RUN apt update && \
    apt install -y \
        dfu-util \
        gcc-arm-none-eabi \
        git \
        python3 \
        python3-pip

# Install QMK and its dependencies
RUN python3 -m pip install qmk appdirs --break-system-packages

# Setup using local QMK directory
ADD . /work
RUN qmk setup -y -H /work

WORKDIR /work
