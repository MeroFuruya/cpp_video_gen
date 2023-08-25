#include <iostream>
#include <CImg/CImg.h>

#include "render.h"

void render(Renderer render_func, int width, int height, int framecount)
{
  CImg<unsigned char> image(width, height, 1, 3);
  for (int frame = 0; frame < framecount; frame++)
  {
    RenderInfo r;
    r.image = image;
    r.frame.width = width;
    r.frame.height = height;
    r.frame.framecount = framecount;
    r.frame.frame = frame;
    render_func(r);

    // Output to ffmpeg to make video, in planar GBR format
    // i.e. run program like this
    // ./main | ffmpeg -y -f rawvideo -pixel_format gbrp -video_size 1024x768 -i - -c:v h264 -pix_fmt yuv420p video.mov
    char *s = reinterpret_cast<char *>(r.image.data() + (r.frame.width * height));       // Get start of G plane
    std::cout.write(s, r.frame.width * r.frame.height);                                  // Output it
    s = reinterpret_cast<char *>(r.image.data() + 2 * (r.frame.width * r.frame.height)); // Get start of B plane
    std::cout.write(s, r.frame.width * r.frame.height);                                  // Output it
    s = reinterpret_cast<char *>(r.image.data());                                        // Get start of R plane
    std::cout.write(s, r.frame.width * r.frame.height);                                  // Output it
  }
}

void RenderInfo::pixel_iterate(PixelIterator pixel_iterator)
{
  for (int x = 0; x < frame.width; x++)
    for (int y = 0; y < frame.height; y++)
    {
      Pixel pixel;
      pixel.r = 0;
      pixel.g = 0;
      pixel.b = 0;

      pixel.x = x;
      pixel.y = y;
      pixel.frame = frame;
      pixel_iterator(pixel);
      image(x, y, 0, 0) = pixel.r;
      image(x, y, 0, 1) = pixel.g;
      image(x, y, 0, 2) = pixel.b;
    }
}