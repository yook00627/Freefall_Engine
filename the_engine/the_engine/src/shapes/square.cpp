#include "shapes.h"
// Creates a square based on height and width parameters

Square::Square() : Rectangle(1.0f, 1.0f, 0.0f, 0.0f) {};

Square::Square(float side, float x, float y) : Rectangle(side, side, x, y) {};