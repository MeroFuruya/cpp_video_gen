#pragma once

#ifndef RENDERERS_H
#define RENDERERS_H

#include "render.h"

namespace renderers
{
  // moving rgb color. every pixel is a different color but no hard edges and the colors are moving
  void rgb_moving_no_hard_edges(Frame &f);
}

#endif