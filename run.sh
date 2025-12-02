#!/bin/bash

SCRIPT_DIR="$(dirname "$0")"

"$SCRIPT_DIR/arduino-ide_2.3.4_Linux_64bit.AppImage" &
code $SCRIPT_DIR &