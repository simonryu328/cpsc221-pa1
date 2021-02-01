#include "block.h"
#include <cmath>
#include <iostream>

int Block::height() const {
  /* your code here */
  return data[0].size();
}

int Block::width() const {
  /* your code here */
  return data.size();
}

/**
 * Renders the given block onto img with its upper
 * left corner at (x, 0). Assumes block fits on the 
 * image.
 */
void Block::render(PNG &im, int x) const {

  // render block to image
   for(unsigned int i = 0; i < width(); i++) {
    for(unsigned int j = 0; j < height(); j++) {
      *im.getPixel(i+x,j) = data[i][j];
    }
  }
 
}

/** 
 * Creates a block that is width X img.height pixels in size
 * by copying the pixels from (x, 0) to (x+width-1, img.height-1)
 * in img. Assumes img is large enough to supply these pixels.
 */
void Block::build(PNG &im, int x, int width) {

  // resize data
  data.resize(width);
  for(int i = 0; i < width; i++) {
    data[i].resize(im.height());
  }

  // Create block from image
   for(unsigned int i = 0; i < width; i++) {
    for(unsigned int j = 0; j < im.height(); j++) {
      data[i][j] = *im.getPixel(i+x,j);
    }
  }
}
