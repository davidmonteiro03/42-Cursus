#!/bin/bash
clear
str=""
for arg in "$@"; do
	str="$str$arg"
done
if [ -z "$str" ]; then
	str="git updates"
fi
echo "=========== GIT STATUS ==========="
echo
git status
echo
echo "============= GIT ADD ============"
echo
echo "         adding files...          "
git add .
echo
echo "=========== GIT STATUS ==========="
echo
git status
echo
echo "=========== GIT COMMIT ==========="
echo
git commit -m "$str"
echo
echo "============ GIT PUSH ============"
echo
git push
echo

