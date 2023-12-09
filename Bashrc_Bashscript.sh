#!/bin/bash

# Check if .bashrc file exists (-f) flag used to search for file in home directory
if [ -f "$HOME/.bashrc" ]; then
    # Append new environment variables to .bashrc and (>>) used to concate the new variables 
    echo "export HELLO=$HOSTNAME" >> "$HOME/.bashrc"
    echo "LOCAL=$(whoami)" >> "$HOME/.bashrc"
    
    # source used to run the bashrc file
    source "$HOME/.bashrc"
    
    # Open another terminal 
    gnome-terminal    
else
    echo ".bashrc file not found in home directory"
fi

