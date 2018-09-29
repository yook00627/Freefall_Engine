#include "shapes.h"
// Creates a square based on height and width parameters

Square::Square() : Rectangle(1, 1, 0, 0) {};

Square::Square(float side, float x, float y) : Rectangle(side, side, x, y) {};