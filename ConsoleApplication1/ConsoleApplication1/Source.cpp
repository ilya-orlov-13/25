#include "header.h"

// 1. Конструктор по умолчанию
Point::Point() : x(0.0), y(0.0) {}

// 2. Конструктор с параметрами
Point::Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

// 3. Конструктор из строки "x,y" или "(x,y)"
Point::Point(const string& point_str) {
    stringstream ss(point_str);
    double temp_x, temp_y;
    char comma, open_paren, close_paren;

    // Попытка распарсить разные форматы: (x,y) или x,y
    ss >> open_paren;
    if (ss.fail() || open_paren != '(') {
        // Если не начинается с '(', сбрасываем и пробуем формат "x,y"
        ss.clear(); // Сброс флагов ошибок
        ss.str(point_str); // Загружаем строку заново
        if (!(ss >> temp_x >> comma >> temp_y) || comma != ',') {
            throw invalid_argument("Invalid point string format. Expected 'x,y' or '(x,y)'. Input: " + point_str);
        }
    }
    else { // Формат (x,y)
        if (!(ss >> temp_x >> comma >> temp_y >> close_paren) || comma != ',' || close_paren != ')') {
            throw invalid_argument("Invalid point string format for '(x,y)'. Input: " + point_str);
        }
    }

    // Проверяем, что после парсинга в строке не осталось лишних символов
    string remaining;
    if (ss >> remaining && !remaining.empty()) {
        throw invalid_argument("Extra characters in point string after parsing. Input: " + point_str);
    }

    x = temp_x;
    y = temp_y;
}


// Свойства (методы доступа)
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

void Point::setX(double x_coord) {
    x = x_coord;
}

void Point::setY(double y_coord) {
    y = y_coord;
}

void Point::setCoordinates(double x_coord, double y_coord) {
    x = x_coord;
    y = y_coord;
}

// Заданный метод
double Point::distanceToOrigin() const {
    // Расстояние = sqrt(x^2 + y^2)
    return sqrt(pow(x, 2) + pow(y, 2));
}

// Дополнительный метод
double Point::distanceToPoint(const Point& other) const {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}


// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const Point& p) {
    // Выводим с некоторой точностью для double
    os << fixed << setprecision(2) << "(" << p.x << ", " << p.y << ")";
    return os;
}
