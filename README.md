# cpp_video_gen

## Requirements

- [CImg](http://cimg.eu/) (C++ library for image processing)
- ffmpeg (for video encoding) - no headers, only the binary is needed and the app output must be piped to it
- g++ (or any other C++ compiler)

## Usage

```
./bin/main | ffmpeg -y -f rawvideo -pixel_format gbrp -video_size 1024x768 -i - -c:v h264 -pix_fmt yuv420p out/video.mov
```

## build

```
make
```

