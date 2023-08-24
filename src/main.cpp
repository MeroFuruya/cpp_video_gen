#include <iostream>
#include <CImg.h>
#include <ffmpeg.h>

using namespace std;
using namespace cimg_library;

int main()
{
  const unsigned int width = 1024;
  const unsigned int height = 768;

  // Basic frame we will draw in
  CImg<unsigned char> image(width, height, 1, 3);

  unsigned char magenta[] = {255, 0, 255};

  // We are going to output 300 frames of 1024x768 RGB raw video
  // ... making a 10s long video at 30fps
  int radius = 100;
  int cx = 100;
  int cy = 100;
  for (int frame = 0; frame < 300; frame++)
  {
    // Start with black - it shows fewer stains ;-)
    image.fill(0);
    image.draw_circle(cx, cy, radius, magenta);

    // Move and re-colour circle
    cx += 2;
    cy++;
    if (magenta[1] != 255)
    {
      magenta[1]++;
    }

    // Output to ffmpeg to make video, in planar GBR format
    // i.e. run program like this
    // ./main | ffmpeg -y -f rawvideo -pixel_format gbrp -video_size 1024x768 -i - -c:v h264 -pix_fmt yuv420p video.mov
    char *s = reinterpret_cast<char *>(image.data() + (width * height)); // Get start of G plane
    std::cout.write(s, width * height);                                  // Output it
    s = reinterpret_cast<char *>(image.data() + 2 * (width * height));   // Get start of B plane
    std::cout.write(s, width * height);                                  // Output it
    s = reinterpret_cast<char *>(image.data());                          // Get start of R plane
    std::cout.write(s, width * height);                                  // Output it
  }
}
