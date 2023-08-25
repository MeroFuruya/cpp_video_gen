#pragma once

#ifndef RENDER_H
#define RENDER_H

#include <iostream>
#include <CImg/CImg.h>

using namespace std;
using namespace cimg_library;

struct Frame
{
  int width;
  int height;
  int framecount;
  int frame;
};

struct Pixel
{
  int x;
  int y;
  Frame frame;
  unsigned char r;
  unsigned char g;
  unsigned char b;
};

typedef void(PixelIterator)(Pixel &pixel);

struct RenderInfo
{
  CImg<unsigned char> image;
  Frame frame;
  void pixel_iterate(PixelIterator pixel_iterator);
};

typedef void (*Renderer)(RenderInfo &r);

void render(Renderer render_func, int width, int height, int framecount);

#endif