#pragma once
#include "circle.h"
#include "triangle.h"

class Draw {
public:
	Draw(Circle& obj, BWMatrix& mat) { obj.draw(mat); }
};