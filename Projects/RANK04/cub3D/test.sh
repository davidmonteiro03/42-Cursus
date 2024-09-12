#!/bin/bash
total=0
oks=0
kos=0
name=cub3D
wrongext="wrong_extension.cub3d"
notfound="maps/notfound.cub"

testvalid () {
	if [ $# != 1 ]; then
		return
	fi
	eval "./$name" "$1" 2>/dev/null > /dev/null
	if [ $? -eq 0 ]; then
		((oks++))
		printf "\033[1;32m✓\033[0m\033[0;32m $1\033[1;32m OK\033[0m\n" 2>/dev/null
	else
		((kos++))
		printf "\033[5;31m✗\033[0m\033[0;31m $1\033[1;31m KO\033[0m\n" 2>/dev/null
	fi
	((total++))
}

testinvalid () {
	if [ $# != 1 ]; then
		return
	fi
	eval "./$name" "$1" 2>/dev/null > /dev/null
	if [ $? -eq 0 ]; then
		((kos++))
		printf "\033[5;31m✗\033[0m\033[0;31m $1\033[1;31m KO\033[0m\n" 2>/dev/null
	else
		((oks++))
		printf "\033[1;32m✓\033[0m\033[0;32m $1\033[1;32m OK\033[0m\n" 2>/dev/null
	fi
	((total++))
}

if [ -f "$name" ]; then
	rm -rf $notfound
	files=$(find maps/valid -type f -name "*.cub" 2>/dev/null | sort)
	while IFS= read -r file; do
		testvalid "$file"
	done <<< "$files"
	files=$(find maps/invalid -type f -name "*.cub" 2>/dev/null | sort)
	while IFS= read -r file; do
		testinvalid "$file"
	done <<< "$files"
	testinvalid "$wrongext"
	testinvalid "$notfound"
	printf "\033[1;34m=====\033[0m\033[0;34m Results\033[0m\033[1;34m =====\033[0m\n"
	printf "\033[1;32mOK   \033[0m:\033[0;32m $oks\033[0m\n"
	printf "\033[1;31mKO   \033[0m:\033[0;31m $kos\033[0m\n"
	printf "\033[1;36mTotal\033[0m:\033[0;36m $total\033[0m\n"
	if [[ $oks != $total || $kos != 0 ]]; then
		printf "\033[1;31m\033[5;31mFailure!\033[0m\033[1;31m $kos\033[0m\033[0;31m test"
		if [ $kos != 1 ]; then
			echo -n "s"
		fi
		printf " failed.\033m\n"
	else
		printf "\033[1;32mSuccess!\033[0;32m All tests passed!\033[0m\n"
	fi
else
	printf "\033[5;31m✗\033[0m\033[1;31m $name:\033[0;31m file not found\033[0m\n" 2>/dev/null;
fi
