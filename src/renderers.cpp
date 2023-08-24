#include "render.h"
#include "colors.h"

#include "renderers.h"

void renderers::rgb_moving_no_hard_edges(Frame &f)
{
  for (int i = 0; i < f.width; i++)
  {
    for (int j = 0; j < f.height; j++)
    {
      f.image(i, j, 0, 0) = (unsigned char)(128.0 + 128.0 * sin((float)f.frame / 10.0 + (float)i / 10.0));
      f.image(i, j, 0, 1) = (unsigned char)(128.0 + 128.0 * sin((float)f.frame / 10.0 + (float)j / 10.0));
      f.image(i, j, 0, 2) = (unsigned char)(128.0 + 128.0 * sin((float)f.frame / 10.0 + (float)i / 10.0 + (float)j / 10.0));
    }
  }
}
