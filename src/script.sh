#!/bin/bash

# Find all .ber files in the ../maps directory and its subdirectories
map_files=$(find ../maps -type f -name "*.ber")

# Loop through each map file and execute the command
for map in $map_files; {
    echo "Running ./a.out with map: $map"
    ./a.out "$map"
    echo "-----------------------------------"
}
