#!/bin/bash

# Check if an argument is provided
if [ -z "$1" ]; then
  echo "Error: Invalid argument. Please provide a number between 1 and 20."
  exit 1
fi

# Check if the argument is a valid number between 1 and 20
if ! [[ "$1" =~ ^[1-9]$|^1[0-9]$|^20$ ]]; then
  echo "Error: Invalid argument. Please provide a number between 1 and 20."
  exit 1
fi

# Define the source directory based on the provided argument
source_directory="saves"
case $1 in
    1) source_directory+="/1_rival1";;
    2) source_directory+="/2_roxanne";;
    3) source_directory+="/3_slateport";;
    4) source_directory+="/4_rival2";;
    5) source_directory+="/5_wattson";;
    6) source_directory+="/6_maxie1";;
    7) source_directory+="/7_flannery";;
    8) source_directory+="/8_brawly";;
    9) source_directory+="/9_norman";;
    10) source_directory+="/10_rival3";;
    11) source_directory+="/11_winona";;
    12) source_directory+="/12_maxie2";;
    13) source_directory+="/13_tateandliza";;
    14) source_directory+="/14_archie";;
    15) source_directory+="/15_juan";;
    16) source_directory+="/16_sidney";;
    17) source_directory+="/17_phoebe";;
    18) source_directory+="/18_glacia";;
    19) source_directory+="/19_drake";;
    20) source_directory+="/20_wallace";;
esac

# Check if the source directory exists
if [ ! -d "$source_directory" ]; then
  echo "Error: The specified save folder does not exist."
  exit 1
fi

# Delete existing files pokeemerald.sav and pokeemerald_modern.sav
rm -f pokeemerald.sav pokeemerald_modern.sav

# Copy new saves from the source directory
cp "$source_directory/pokeemerald.sav" "$source_directory/pokeemerald_modern.sav" .

echo "Save files copied successfully."

