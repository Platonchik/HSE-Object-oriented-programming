#ifndef BW_MATRIX_H
#define BW_MATRIX_H

#include "matrix.h"
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

class Circle;
class Triangle;
class Rectangle;

class BWMatrix : public Matrix
{
public:
    BWMatrix();
    BWMatrix(const BWMatrix& mat);
    BWMatrix(size_t rows, size_t cols);
    BWMatrix(size_t rows, size_t cols, int initVal);

    void print() const override;
    void fromOpenCV(const cv::Mat& mat) override;
    cv::Mat toOpenCV() const override;
    bool readImage(const std::string& path) override;

    void draw(Circle& obj);
    void draw(Triangle& obj);
    void draw(Rectangle& obj);

    BWMatrix invert() const;

    BWMatrix add(int val) const;
    BWMatrix multiply(int val) const;
    BWMatrix subtract(int val) const;

    BWMatrix operator+(int val) const;
    BWMatrix operator-(int val) const;
    BWMatrix operator*(int val) const;
    BWMatrix& operator=(const BWMatrix& mat);
    friend std::ostream& operator<<(std::ostream& out, const BWMatrix& mat);
};

#endif // BW_MATRIX_H
