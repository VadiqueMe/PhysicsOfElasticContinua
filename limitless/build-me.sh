#!/bin/sh

sed s/%%lang%%/\\\\entrue/ infinitesimals.tex > infinitesimals_en.tex
sed s/%%lang%%/\\\\rutrue/ infinitesimals.tex > infinitesimals_ru.tex

pdflatex infinitesimals_en.tex && pdflatex infinitesimals_en.tex

pdflatex infinitesimals_ru.tex && pdflatex infinitesimals_ru.tex

rm infinitesimals_en.out infinitesimals_en.log
rm infinitesimals_en.aux
rm infinitesimals_en.tex

rm infinitesimals_ru.out infinitesimals_ru.log
rm infinitesimals_ru.aux
rm infinitesimals_ru.tex
