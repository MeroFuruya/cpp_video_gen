#include "render.h"
#include "colors.h"

#include "renderers.h"

// rgb moving no hard edges

void rgb_moving_no_hard_edges_pixelIterator(Pixel &pixel)
{
  pixel.r = (unsigned char)(128.0 + 128.0 * sin((float)pixel.frame.frame / 10.0 + (float)pixel.x / 10.0));
  pixel.g = (unsigned char)(128.0 + 128.0 * sin((float)pixel.frame.frame / 10.0 + (float)pixel.y / 10.0));
  pixel.b = (unsigned char)(128.0 + 128.0 * sin((float)pixel.frame.frame / 10.0 + (float)pixel.x / 10.0 + (float)pixel.y / 10.0));
}

void renderers::rgb_moving_no_hard_edges(RenderInfo &r)
{
  r.pixel_iterate(rgb_moving_no_hard_edges_pixelIterator);
}

// idk yet

void idk_yet_pixelIterator(Pixel &pixel)
{
  pixel.r = (unsigned char)255 * sin((float)pixel.frame.frame / 10.0 + (float)pixel.x / 10.0) + (unsigned char)255 * sin((float)pixel.frame.frame / 10.0 + (float)pixel.y / 10.0);
}

void renderers::idk_yet(RenderInfo &r)
{
  r.pixel_iterate(idk_yet_pixelIterator);
}
