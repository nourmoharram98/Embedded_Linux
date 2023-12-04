#!/bin/bash

path="/home/nourmoharram/exam_directory"
directory_name="exam_directory"
files="file1.txt file2.txt file3.txt"

if [ -d $path ]; then
	echo "directory already exists"

	if [ -z "$(ls -A $path)" ]; then
		echo "Directory is empty"
		echo "Creating the three files ..."
		cd $directory_name
		touch $files
		echo "files are created"
	else
		echo "Directory is not empty"
		cd $directory_name
		ls -hls 
		
	fi
else
	echo "directory not exist "
	echo "creating exam directory ..."
	mkdir $directory_name
	echo "exam direcotry created"
	echo "Creating the three files ..."
	cd $directory_name
	touch $files
	echo "files are created"
fi

