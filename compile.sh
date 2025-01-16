#!/bin/bash

# Edit these values (as applicable)
KEYBOARD="zsa/voyager"
KEYMAP="fasterius"
IMAGE="erikfas/qmk-firmware-zsa"

# Build Docker image
docker build \
    --rm \
    -t "${IMAGE}" \
    .

# Compile keymap if build was successful
if [ $? == "0" ]; then

    docker run \
        --rm \
        -v "${PWD}:/work" \
        "${IMAGE}" \
        qmk compile -kb ${KEYBOARD} -km ${KEYMAP}

fi
