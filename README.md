# A Docker-based fork of the QMK Firmware

This is a fork of [ZSA's QMK fork](https://github.com/zsa/qmk_firmware), which
additionally contains my own personal QMK keymaps. You can find the official QMK
documentation at [docs.qmk.fm](https://docs.qmk.fm). This repository is setup
such that compiling is done with Docker, rather than local installation of QMK,
for portability and ease-of-use.

## Compiling

First make sure that the keymap you want to compile is available under
`keyboards/<KEYBOARD>/keymaps/<KEYMAP>`. You can then build the Docker image
using the provided `Dockerfile` with _e.g._ `docker build --rm -t qmk .`; make
sure that you're inside the root directory of this repository. You can then
compile your keymap using _e.g._ `docker run --rm -v $PWD:/work qmk qmk compile
-kb <KEYBOARD> -km <KEYMAP>`. The ready-to-flash keymap will then be put in the
repository root as `<KEYBOARD>_<KEYMAP>.bin`.

If you are experimenting and editing your keymap regularly you can simplify this
process by using the `compile.sh` script, which automates the above process;
edit this file to point to your keymap before you use it, though.

While building the Docker image the first time may take some time, subsequent
runs will go much quicker, as only the final QMK setup step needs to be re-run.
