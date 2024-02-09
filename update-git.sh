#!/bin/bash
str="'$*'"
echo "$str"
clear
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
git commit -m "git updates"
echo
echo "============ GIT PUSH ============"
echo
git push
echo
