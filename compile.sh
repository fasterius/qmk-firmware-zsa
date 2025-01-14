#!/bin/bash

# Build Docker image
docker build \
    --rm \
    -t erikfas/qmk-firmware-zsa \
    .

# Compile keymap
if [ $? == "0" ]; then

    docker run \
        --rm \
        -v "${PWD}:/work" \
        erikfas/qmk-firmware-zsa \
        qmk compile -kb voyager -km fasterius

fi
