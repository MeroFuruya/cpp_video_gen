#!/bin/bash

mkdir -p out
./bin/main | ffmpeg -y -f rawvideo -pixel_format gbrp -video_size 1024x768 -i - -c:v h264 -pix_fmt yuv420p out/video.mov
