#include "render.h"
#include "colors.h"
#include "renderers.h"

const int framecount = 300;
const unsigned int width = 1024;
const unsigned int height = 768;

int main()
{
  render(renderers::idk_yet, width, height, framecount);
  return 0;
}
