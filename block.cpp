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

void Block::render(PNG &im, int x) const {
  /* your code here */
}

void Block::build(PNG &im, int x, int width) {
  /* your code here */
}
