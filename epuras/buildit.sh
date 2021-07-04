#!/bin/sh

for texsource in *.tex; do
  echo
  echo pdflatex "$texsource"
  echo

  pdflatex "$texsource"
done
