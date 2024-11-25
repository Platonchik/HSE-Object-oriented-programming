#include "include/rgb_matrix.h"
#include "include/bw_matrix.h"
#include "include/color.h"
#include "include/circle.h"
#include "include/triangle.h"
#include "include/rectangle.h"
#include <chrono>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 

using Time = std::chrono::high_resolution_clock;
using ns = std::chrono::nanoseconds;

int main(){
    Time::time_point start = Time::now();

    RGBMatrix rgb(2000, 2000, 0);
    RGBColor rgbColor(102, 205, 255);
    Rectangle sky({ 0, 0 }, 2000, 1500, rgbColor);
    rgbColor.changeColor(0, 153, 0);
    Rectangle grass({ 0, 1500 }, 2000, 2000, rgbColor);
    rgbColor.changeColor(255, 255, 0);
    Circle sun({ 50, 50 }, 300, rgbColor);
    Triangle ray1({ 360, 50 }, { 550, 30 }, { 550, 70 }, rgbColor);
    Triangle ray2({ 270, 270 }, { 420, 360 }, { 390, 400 }, rgbColor);
    Triangle ray3({ 50, 360 }, { 30, 550 }, { 70, 550 }, rgbColor);
    rgbColor.changeColor(102, 51, 0);
    Rectangle wall({ 600, 900 }, 1000, 800, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Rectangle flue({ 1300, 550 }, 100, 200, rgbColor);
    rgbColor.changeColor(51, 0, 0);
    Triangle roof({ 560, 900 }, { 1100, 500 }, { 1640, 900 }, rgbColor);
    rgbColor.changeColor(204, 102, 0);
    Rectangle door({ 1400, 1350 }, 150, 300, rgbColor);
    rgbColor.changeColor(0, 0, 0);
    Circle knob({ 1535, 1500 }, 6, rgbColor);
    rgbColor.changeColor(102, 163, 255);
    Rectangle window1({ 700, 950 }, 300, 350, rgbColor);
    Rectangle window2({ 1200, 950 }, 300, 350, rgbColor);

    rgb.draw(sky);
    rgb.draw(grass);
    rgb.draw(sun);
    rgb.draw(ray1);
    rgb.draw(ray2);
    rgb.draw(ray3);
    rgb.draw(wall);
    rgb.draw(flue);
    rgb.draw(roof);
    rgb.draw(door);
    rgb.draw(knob);
    rgb.draw(window1);
    rgb.draw(window2);
    rgb.display();

    //rgb.save(); // for save image to mushroom.jpg

    Time::time_point end = Time::now();
    double duration = std::chrono::duration_cast<ns>(end - start).count() * 1e-6;
    std::cout << "Execution time: " << duration << "ms" << std::endl;
}