#include <iostream>
#include <CImg/CImg.h>

#include "render.h"

void render(Renderer render_func, int width, int height, int framecount)
{
  CImg<unsigned char> image(width, height, 1, 3);
  for (int frame = 0; frame < framecount; frame++)
  {
    Frame f;
    f.width = width;
    f.height = height;
    f.framecount = framecount;
    f.frame = frame;
    f.image = image;
    render_func(f);

    // Output to ffmpeg to make video, in planar GBR format
    // i.e. run program like this
    // ./main | ffmpeg -y -f rawvideo -pixel_format gbrp -video_size 1024x768 -i - -c:v h264 -pix_fmt yuv420p video.mov
    char *s = reinterpret_cast<char *>(f.image.data() + (f.width * height)); // Get start of G plane
    std::cout.write(s, f.width * f.height);                                  // Output it
    s = reinterpret_cast<char *>(f.image.data() + 2 * (f.width * f.height)); // Get start of B plane
    std::cout.write(s, f.width * f.height);                                  // Output it
    s = reinterpret_cast<char *>(f.image.data());                            // Get start of R plane
    std::cout.write(s, f.width * f.height);                                  // Output it
  }
}