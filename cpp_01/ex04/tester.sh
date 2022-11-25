#!/bin/bash

#Colour Variable Defines
RED="\033[1;31m"
CLEAR="\033[0m"

printf "${RED}----------------------------------${CLEAR}\n"
printf "${RED}|     Running Replace Tester     |${CLEAR}\n"
printf "${RED}----------------------------------${CLEAR}\n\n"

printf "${RED}---------------Testing with Invalid File-------------------${CLEAR}\n\n"
./replace ./test_files/noexist test YES
printf "\n"

printf "${RED}---------------Testing with Insufficient Arguments-------------------${CLEAR}\n\n"
./replace ./test_files/noexist test
printf "\n"

printf "${RED}---------------Testing with Valid File and Empty String 1-------------------${CLEAR}\n\n"
./replace ./test_files/test.txt "" YES
diff ./test_files/test.txt ./test_files/test.txt.replace
rm ./test_files/test.txt.replace

ret=$?

if [[ $ret -eq 0 ]]; then
    printf "${RED}No difference${CLEAR}\n\n"
fi

printf "${RED}---------------Testing with Valid File and Empty String 2-------------------${CLEAR}\n\n"
./replace ./test_files/test.txt test ""
diff ./test_files/test.txt ./test_files/test.txt.replace
rm ./test_files/test.txt.replace
printf "\n"

printf "${RED}---------------Testing with Valid File and Both Strings Empty-------------------${CLEAR}\n\n"
./replace ./test_files/test.txt "" ""
diff ./test_files/test.txt ./test_files/test.txt.replace
rm ./test_files/test.txt.replace

ret=$?

if [[ $ret -eq 0 ]]; then
    printf "${RED}No difference${CLEAR}\n\n"
fi

printf "${RED}---------------Testing with Valid File and Nothing to Replace-------------------${CLEAR}\n\n"
./replace ./test_files/test.txt nope YES
diff ./test_files/test.txt ./test_files/test.txt.replace
rm ./test_files/test.txt.replace

ret=$?

if [[ $ret -eq 0 ]]; then
    printf "${RED}No difference${CLEAR}\n\n"
fi

printf "${RED}---------------Testing with Valid File and Valid Replace-------------------${CLEAR}\n\n"
./replace ./test_files/test.txt test YES
diff ./test_files/test.txt ./test_files/test.txt.replace
rm ./test_files/test.txt.replace