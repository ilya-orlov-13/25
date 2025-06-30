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
    // Конструкторы
    Point();                                  // 1. Конструктор по умолчанию (точка в начале координат)
    Point(double x_coord, double y_coord);    // 2. Конструктор с параметрами
    Point(const string& point_str);           // 3. Конструктор из строки "x,y" или "(x,y)"

    // Свойства (методы доступа)
    double getX() const;
    double getY() const;

    void setX(double x_coord);
    void setY(double y_coord);
    void setCoordinates(double x_coord, double y_coord);

    // 1
    // Вычислить расстояние от точки до начала координат.
    double distanceToOrigin() const;

    // Дополнительный полезный метод: расстояние до другой точки
    double distanceToPoint(const Point& other) const;


    // Перегрузка оператора вывода для вывода полей
    friend ostream& operator<<(ostream& os, const Point& p);
};
