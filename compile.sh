#!/bin/bash

KEYBOARD="zsa/voyager"
KEYMAP="fasterius"

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
        qmk compile -kb $KEYBOARD -km $KEYMAP

fi
