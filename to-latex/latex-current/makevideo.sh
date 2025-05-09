#!/bin/sh

[ -d anim ] || mkdir anim
cd anim

convert -density 200 ../animated2.pdf[0-89] p.png
convert -density 200 ../animated2.pdf[90-179] p.png
convert -density 200 ../animated2.pdf[180-269] p.png
convert -density 200 ../animated2.pdf[270-359] p.png
convert -density 200 ../animated2.pdf[360-449] p.png
convert -density 200 ../animated2.pdf[450-540] p.png

ffmpeg -r 25 -i p-%01d.png -c:v libx264 -r 25 -vf scale=-2:900,setsar=1:1 video.mp4

mv video.mp4 ../
cd ..

##rm -r anim

[ -f music.wav ] && ffmpeg -i video.mp4 -i music.wav -map 0:v -map 1:a -codec:v copy -codec:a aac -b:a 192k -shortest videowithmusic.mp4

ffmpeg -y -i video.mp4 -map 0:v:0 -b:v 0 -pass 1 -an -f webm /dev/null
ffmpeg -i video.mp4 -map 0:v:0 -b:v 0 -pass 2 video.webm
[ -f music.wav ] && ffmpeg -i video.webm -i music.wav -map 0:v -map 1:a -c:v copy -c:a libopus -b:a 192k -shortest videowithmusic.webm
rm -v ffmpeg2pass*.log
