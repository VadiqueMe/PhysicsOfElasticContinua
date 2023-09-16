#!/bin/sh

RED='\033[1;31m'
GREEN='\033[1;32m'
NOCOLOR='\033[0m'

okay="${GREEN}ok${NOCOLOR}"
fail="${RED}nope${NOCOLOR}"

./makechapter1.sh && echo "${chapter_one=$okay}"
./makechapter2.sh && echo "${chapter_two=$okay}"
./makechapter3.sh && echo "${chapter_three=$okay}"
./makechapter4.sh && echo "${chapter_four=$okay}"
./makechapter5.sh && echo "${chapter_five=$okay}"
./makechapter6.sh && echo "${chapter_six=$okay}"
./makechapter7.sh && echo "${chapter_seven=$okay}"
./makechapter8.sh && echo "${chapter_eight=$okay}"
./makechapter9.sh && echo "${chapter_nine=$okay}"
./makechapter10.sh && echo "${chapter_ten=$okay}"
./makechapter11.sh && echo "${chapter_eleven=$okay}"
./makechapter12.sh && echo "${chapter_twelve=$okay}"
./makechapter13.sh && echo "${chapter_thirteen=$okay}"
./makechapter14.sh && echo "${chapter_fourteen=$okay}"
./makechapter15.sh && echo "${chapter_fifteen=$okay}"
# the 17th chapter is built together with the 16th
./makechapters16and17.sh && echo "${chapter_sixteen=$okay}" && echo "${chapter_seventeen=$okay}"
./makechapter18.sh && echo "${chapter_eighteen=$okay}"

echo
echo `basename "$0"`
echo "   1st chapter" "${chapter_one=$fail}"
echo "   2nd chapter" "${chapter_two=$fail}"
echo "   3rd chapter" "${chapter_three=$fail}"
echo "   4th chapter" "${chapter_four=$fail}"
echo "   5th chapter" "${chapter_five=$fail}"
echo "   6th chapter" "${chapter_six=$fail}"
echo "   7th chapter" "${chapter_seven=$fail}"
echo "   8th chapter" "${chapter_eight=$fail}"
echo "   9th chapter" "${chapter_nine=$fail}"
echo "  10th chapter" "${chapter_ten=$fail}"
echo "  11th chapter" "${chapter_eleven=$fail}"
echo "  12th chapter" "${chapter_twelve=$fail}"
echo "  13th chapter" "${chapter_thirteen=$fail}"
echo "  14th chapter" "${chapter_fourteen=$fail}"
echo "  15th chapter" "${chapter_fifteen=$fail}"
echo "  16th chapter" "${chapter_sixteen=$fail}"
echo "  17th chapter" "${chapter_seventeen=$fail}"
echo "  18th chapter" "${chapter_eighteen=$fail}"
