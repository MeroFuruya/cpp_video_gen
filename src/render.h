#pragma once

#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <CImg/CImg.h>

using namespace std;
using namespace cimg_library;

struct Frame
{
  CImg<unsigned char> image;
  int width;
  int height;
  int framecount;
  int frame;
};

typedef void (*Renderer)(Frame &frame);

void render(Renderer render_func, int width, int height, int framecount);

#endif