#pragma once
#include <vector>

class BWColor
{
public:
	BWColor();
	BWColor(int color);
	std::vector<int> getColor();
	void changeColor(int color);

private:
	std::vector<int> m_color;
};


class RGBColor
{
public:
	RGBColor();
	RGBColor(int r, int g, int b);
	std::vector<int> getColor();
	void changeColor(int r, int g, int b);

private:
	std::vector<int>m_color;
};