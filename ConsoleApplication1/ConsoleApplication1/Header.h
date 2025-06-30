#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <limits>  
#include <sstream>  
#include <iomanip>

using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // ������������
    Point();                                  // 1. ����������� �� ��������� (����� � ������ ���������)
    Point(double x_coord, double y_coord);    // 2. ����������� � �����������
    Point(const string& point_str);           // 3. ����������� �� ������ "x,y" ��� "(x,y)"

    // �������� (������ �������)
    double getX() const;
    double getY() const;

    void setX(double x_coord);
    void setY(double y_coord);
    void setCoordinates(double x_coord, double y_coord);

    // 1
    // ��������� ���������� �� ����� �� ������ ���������.
    double distanceToOrigin() const;

    // �������������� �������� �����: ���������� �� ������ �����
    double distanceToPoint(const Point& other) const;


    // ���������� ��������� ������ ��� ������ �����
    friend ostream& operator<<(ostream& os, const Point& p);
};
