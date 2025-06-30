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
    //  онструкторы
    Point();                                  // 1.  онструктор по умолчанию (точка в начале координат)
    Point(double x_coord, double y_coord);    // 2.  онструктор с параметрами
    Point(const string& point_str);           // 3.  онструктор из строки "x,y" или "(x,y)"

    // —войства (методы доступа)
    double getX() const;
    double getY() const;

    void setX(double x_coord);
    void setY(double y_coord);
    void setCoordinates(double x_coord, double y_coord);

    // 1
    // ¬ычислить рассто€ние от точки до начала координат.
    double distanceToOrigin() const;

    // ƒополнительный полезный метод: рассто€ние до другой точки
    double distanceToPoint(const Point& other) const;


    // ѕерегрузка оператора вывода дл€ вывода полей
    friend ostream& operator<<(ostream& os, const Point& p);
};
