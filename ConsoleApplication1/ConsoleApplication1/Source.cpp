#include "header.h"

// 1. ����������� �� ���������
Point::Point() : x(0.0), y(0.0) {}

// 2. ����������� � �����������
Point::Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

// 3. ����������� �� ������ "x,y" ��� "(x,y)"
Point::Point(const string& point_str) {
    stringstream ss(point_str);
    double temp_x, temp_y;
    char comma, open_paren, close_paren;

    // ������� ���������� ������ �������: (x,y) ��� x,y
    ss >> open_paren;
    if (ss.fail() || open_paren != '(') {
        // ���� �� ���������� � '(', ���������� � ������� ������ "x,y"
        ss.clear(); // ����� ������ ������
        ss.str(point_str); // ��������� ������ ������
        if (!(ss >> temp_x >> comma >> temp_y) || comma != ',') {
            throw invalid_argument("Invalid point string format. Expected 'x,y' or '(x,y)'. Input: " + point_str);
        }
    }
    else { // ������ (x,y)
        if (!(ss >> temp_x >> comma >> temp_y >> close_paren) || comma != ',' || close_paren != ')') {
            throw invalid_argument("Invalid point string format for '(x,y)'. Input: " + point_str);
        }
    }

    // ���������, ��� ����� �������� � ������ �� �������� ������ ��������
    string remaining;
    if (ss >> remaining && !remaining.empty()) {
        throw invalid_argument("Extra characters in point string after parsing. Input: " + point_str);
    }

    x = temp_x;
    y = temp_y;
}


// �������� (������ �������)
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

// �������� �����
double Point::distanceToOrigin() const {
    // ���������� = sqrt(x^2 + y^2)
    return sqrt(pow(x, 2) + pow(y, 2));
}

// �������������� �����
double Point::distanceToPoint(const Point& other) const {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}


// ���������� ��������� ������
ostream& operator<<(ostream& os, const Point& p) {
    // ������� � ��������� ��������� ��� double
    os << fixed << setprecision(2) << "(" << p.x << ", " << p.y << ")";
    return os;
}