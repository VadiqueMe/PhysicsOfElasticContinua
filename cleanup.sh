#!/bin/sh

rm -vf *.log
rm -vf *.synctex*

find . -iname "*.log" -type f -print0 | xargs -0 rm -v 2>/dev/null
find . -iname "*.synctex*" -type f -print0 | xargs -0 rm -v 2>/dev/null

rm -f LICENSE.aux

rm -v -f mybook.*.pdf
rm -v -f mybook.*.out
rm -v -f mybook.*.toc
rm -v -f mybook.*.aux
