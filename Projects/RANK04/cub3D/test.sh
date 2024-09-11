#!/bin/bash
name=cub3D
if [ -f $name ]; then
	wrong_extension=$(find * -type f -not -name "*.cub" | sort | grep '\.' | head -n 1)
	not_found="not_found.cub"
	files=$(find * -type f | sort)" $wrong_extension $not_found"
	for file in $files; do
		if [[ -f $file ]]; then
			output=$(./$name $file | grep -v "Error")
			if [ -z "$output" ]; then
				printf "\033[0;32m✓ $file\033[0m\n";
			else
				printf "\033[5;31m✗\033[0m\033[1;31m $file\033[0;31m ($output)\033[0m\n";
			fi
			extension=$(echo -n $file | tail -c 4)
			if [ "$extension" == ".cub" ]; then
				cat $file -E
			fi
		else
			printf "\033[5;31m✗\033[0m\033[1;31m $file:\033[0;31m not found\033[0m\n";
		fi
	done
else
	printf "\033[5;31m✗\033[0m\033[1;31m $name:\033[0;31m not found\033[0m\n";
fi
