#include "render.h"
#include "colors.h"
#include "renderers.h"

const int framecount = 1000;
const unsigned int width = 1024;
const unsigned int height = 768;

int main()
{
  render(renderers::rgb_moving_no_hard_edges, width, height, framecount);
  return 0;
}
