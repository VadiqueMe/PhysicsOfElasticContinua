#!/bin/sh

rm -vf *.log
rm -vf *.synctex*

find . -iname "*.log" -type f -print0 | xargs -0 rm -v
find . -iname "*.synctex*" -type f -print0 | xargs -0 rm -v

rm -f LICENSE.aux

rm -v -f mybook.*.pdf
rm -v -f mybook.*.out
rm -v -f mybook.*.toc
rm -v -f mybook.*.aux
