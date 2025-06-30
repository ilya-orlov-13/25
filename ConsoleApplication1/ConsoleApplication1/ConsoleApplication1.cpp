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
                cout << "�������� ��� ����������� ���������. ����������, ���������� �����." << endl;
            }
        }
        else {
            cout << "������������ ����. ����������, ���������� �����." << endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ������������� ��� string
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
    cout << "������������ ������ Point" << endl;

    // 1. ������������ �������������
    cout << "\n1. ������������ �������������:" << endl;
    try {
        Point p1; // ����������� �� ���������
        cout << "p1 (�� ���������): " << p1 << endl;

        Point p2(3.0, 4.0); // ����������� � �����������
        cout << "p2 (3.0, 4.0): " << p2 << endl;

        Point p3_str1("(1.5,2.75)"); // ����������� �� ������ "(x,y)"
        cout << "p3_str1 ('(1.5,2.75)'): " << p3_str1 << endl;

        Point p3_str2(" -2.0 , 5.1 "); // ����������� �� ������ "x,y" (� ���������, ������� stringstream ����������)
        cout << "p3_str2 (' -2.0 , 5.1 '): " << p3_str2 << endl;

        Point p3_str3("7.0,8.123");
        cout << "p3_str3 ('7.0,8.123'): " << p3_str3 << endl;


        cout << "������� ������� Point p_invalid_str1('(1.x,2.0)'): ";
        Point p_invalid_str1("(1.x,2.0)");
    }
    catch (const exception& e) {
        cout << "����������: " << e.what() << endl;
    }
    try {
        cout << "������� ������� Point p_invalid_str2('(1.0,2.0)extra'): ";
        Point p_invalid_str2("(1.0,2.0)extra");
    }
    catch (const exception& e) {
        cout << "����������: " << e.what() << endl;
    }
    try {
        cout << "������� ������� Point p_invalid_str3('1.0;2.0'): ";
        Point p_invalid_str3("1.0;2.0");
    }
    catch (const exception& e) {
        cout << "����������: " << e.what() << endl;
    }


    // 2. ������������ �������� � ��������
    cout << "\n2. ������������ �������� � ��������:" << endl;
    Point p_set_get;
    cout << "p_set_get (���������): " << p_set_get << endl;
    p_set_get.setX(1.23);
    p_set_get.setY(-4.56);
    cout << "p_set_get (����� setX(1.23), setY(-4.56)): " << p_set_get << endl;
    cout << "  getX(): " << p_set_get.getX() << endl;
    cout << "  getY(): " << p_set_get.getY() << endl;
    p_set_get.setCoordinates(10.0, 20.0);
    cout << "p_set_get (����� setCoordinates(10.0, 20.0)): " << p_set_get << endl;


    // 3. ������������ ������ distanceToOrigin
    cout << "\n3. ������������ ������ distanceToOrigin:" << endl;
    Point p_dist1(3.0, 4.0);
    cout << "���������� �� " << p_dist1 << " �� ������ ���������: " << p_dist1.distanceToOrigin() << " (�������: 5.00)" << endl;

    Point p_dist2(0.0, 0.0);
    cout << "���������� �� " << p_dist2 << " �� ������ ���������: " << p_dist2.distanceToOrigin() << " (�������: 0.00)" << endl;

    Point p_dist3(-5.0, 12.0);
    cout << "���������� �� " << p_dist3 << " �� ������ ���������: " << p_dist3.distanceToOrigin() << " (�������: 13.00)" << endl;

    // 4. ������������ ������ distanceToPoint (��������������)
    cout << "\n4. ������������ ������ distanceToPoint:" << endl;
    Point p_a(1.0, 1.0);
    Point p_b(4.0, 5.0); // dx=3, dy=4, dist=5
    cout << "���������� �� " << p_a << " �� " << p_b << ": " << p_a.distanceToPoint(p_b) << " (�������: 5.00)" << endl;
    cout << "���������� �� " << p_b << " �� " << p_a << ": " << p_b.distanceToPoint(p_a) << " (�������: 5.00)" << endl;
    cout << "���������� �� " << p_a << " �� " << p_a << ": " << p_a.distanceToPoint(p_a) << " (�������: 0.00)" << endl;


    // 5. ������������ � ���������������� ������
    cout << "\n5. ������������ � ���������������� ������:" << endl;
    double x_user, y_user;
    string str_user;

    cout << "�������� ������� Point ����� ���������������� ���� (�����):" << endl;
    // ��� double �� ��������� ������� min/max � get_validated_input, ���� ��� �� �����

    x_user = get_validated_input<double>("������� ���������� X");
    y_user = get_validated_input<double>("������� ���������� Y");

    Point user_point_nums(x_user, y_user);
    cout << "��������� ����� (�����): " << user_point_nums << endl;
    cout << "���������� �� ��� �� ������ ���������: " << user_point_nums.distanceToOrigin() << endl;

    cout << "\n�������� ������� Point ����� ���������������� ���� (������):" << endl;
    Point user_point_str;
    bool str_parsed = false;
    while (!str_parsed) {
        str_user = get_validated_input<string>("������� ���������� ����� � ������� 'x,y' ��� '(x,y)'");
        try {
            user_point_str = Point(str_user);
            cout << "��������� ����� (������): " << user_point_str << endl;
            cout << "���������� �� ��� �� ������ ���������: " << user_point_str.distanceToOrigin() << endl;
            str_parsed = true;
        }
        catch (const exception& e) {
            cout << "������ �������� ������: " << e.what() << " ���������� �����." << endl;
        }
    }

}

int main() {
    setlocale(LC_ALL, "ru");
    cout << fixed << setprecision(2);
    test_point_class();
}