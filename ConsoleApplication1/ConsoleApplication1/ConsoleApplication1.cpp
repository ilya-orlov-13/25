#include "header.h"

#ifndef INPUT_HANDLER_H_MOCK
#define INPUT_HANDLER_H_MOCK
template <typename T>
T get_validated_input(const string& prompt, T min_val = numeric_limits<T>::lowest(), T max_val = numeric_limits<T>::max()) {
    T value;
    while (true) {
        cout << prompt;
        cout << ": ";

        cin >> value;
        if (cin.good()) {
            if (value >= min_val && value <= max_val) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
            else {
                cout << "Значение вне допустимого диапазона. Пожалуйста, попробуйте снова." << endl;
            }
        }
        else {
            cout << "Некорректный ввод. Пожалуйста, попробуйте снова." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Специализация для string
template <>
string get_validated_input<string>(const string& prompt, string min_val, string max_val) {
    string value;
    cout << prompt << ": ";
    cin >> value;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}
#endif
//

void test_point_class() {
    cout << "Тестирование класса Point" << endl;

    // 1. Тестирование конструкторов
    cout << "\n1. Тестирование конструкторов:" << endl;
    try {
        Point p1; // Конструктор по умолчанию
        cout << "p1 (по умолчанию): " << p1 << endl;

        Point p2(3.0, 4.0); // Конструктор с параметрами
        cout << "p2 (3.0, 4.0): " << p2 << endl;

        Point p3_str1("(1.5,2.75)"); // Конструктор из строки "(x,y)"
        cout << "p3_str1 ('(1.5,2.75)'): " << p3_str1 << endl;

        Point p3_str2(" -2.0 , 5.1 "); // Конструктор из строки "x,y" (с пробелами, которые stringstream обработает)
        cout << "p3_str2 (' -2.0 , 5.1 '): " << p3_str2 << endl;

        Point p3_str3("7.0,8.123");
        cout << "p3_str3 ('7.0,8.123'): " << p3_str3 << endl;


        cout << "Попытка создать Point p_invalid_str1('(1.x,2.0)'): ";
        Point p_invalid_str1("(1.x,2.0)");
    }
    catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    try {
        cout << "Попытка создать Point p_invalid_str2('(1.0,2.0)extra'): ";
        Point p_invalid_str2("(1.0,2.0)extra");
    }
    catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }
    try {
        cout << "Попытка создать Point p_invalid_str3('1.0;2.0'): ";
        Point p_invalid_str3("1.0;2.0");
    }
    catch (const exception& e) {
        cout << "Исключение: " << e.what() << endl;
    }


    // 2. Тестирование сеттеров и геттеров
    cout << "\n2. Тестирование сеттеров и геттеров:" << endl;
    Point p_set_get;
    cout << "p_set_get (начальное): " << p_set_get << endl;
    p_set_get.setX(1.23);
    p_set_get.setY(-4.56);
    cout << "p_set_get (после setX(1.23), setY(-4.56)): " << p_set_get << endl;
    cout << "  getX(): " << p_set_get.getX() << endl;
    cout << "  getY(): " << p_set_get.getY() << endl;
    p_set_get.setCoordinates(10.0, 20.0);
    cout << "p_set_get (после setCoordinates(10.0, 20.0)): " << p_set_get << endl;


    // 3. Тестирование метода distanceToOrigin
    cout << "\n3. Тестирование метода distanceToOrigin:" << endl;
    Point p_dist1(3.0, 4.0);
    cout << "Расстояние от " << p_dist1 << " до начала координат: " << p_dist1.distanceToOrigin() << " (Ожидаем: 5.00)" << endl;

    Point p_dist2(0.0, 0.0);
    cout << "Расстояние от " << p_dist2 << " до начала координат: " << p_dist2.distanceToOrigin() << " (Ожидаем: 0.00)" << endl;

    Point p_dist3(-5.0, 12.0);
    cout << "Расстояние от " << p_dist3 << " до начала координат: " << p_dist3.distanceToOrigin() << " (Ожидаем: 13.00)" << endl;

    // 4. Тестирование метода distanceToPoint (дополнительный)
    cout << "\n4. Тестирование метода distanceToPoint:" << endl;
    Point p_a(1.0, 1.0);
    Point p_b(4.0, 5.0); // dx=3, dy=4, dist=5
    cout << "Расстояние от " << p_a << " до " << p_b << ": " << p_a.distanceToPoint(p_b) << " (Ожидаем: 5.00)" << endl;
    cout << "Расстояние от " << p_b << " до " << p_a << ": " << p_b.distanceToPoint(p_a) << " (Ожидаем: 5.00)" << endl;
    cout << "Расстояние от " << p_a << " до " << p_a << ": " << p_a.distanceToPoint(p_a) << " (Ожидаем: 0.00)" << endl;


    // 5. Тестирование с пользовательским вводом
    cout << "\n5. Тестирование с пользовательским вводом:" << endl;
    double x_user, y_user;
    string str_user;

    cout << "Создание объекта Point через пользовательский ввод (числа):" << endl;
    // Для double не указываем строгие min/max в get_validated_input, если они не нужны

    x_user = get_validated_input<double>("Введите координату X");
    y_user = get_validated_input<double>("Введите координату Y");

    Point user_point_nums(x_user, y_user);
    cout << "Созданная точка (числа): " << user_point_nums << endl;
    cout << "Расстояние от нее до начала координат: " << user_point_nums.distanceToOrigin() << endl;

    cout << "\nСоздание объекта Point через пользовательский ввод (строка):" << endl;
    Point user_point_str;
    bool str_parsed = false;
    while (!str_parsed) {
        str_user = get_validated_input<string>("Введите координаты точки в формате 'x,y' или '(x,y)'");
        try {
            user_point_str = Point(str_user);
            cout << "Созданная точка (строка): " << user_point_str << endl;
            cout << "Расстояние от нее до начала координат: " << user_point_str.distanceToOrigin() << endl;
            str_parsed = true;
        }
        catch (const exception& e) {
            cout << "Ошибка парсинга строки: " << e.what() << " Попробуйте снова." << endl;
        }
    }

}

int main() {
    setlocale(LC_ALL, "ru");
    cout << fixed << setprecision(2);
    test_point_class();
}
