#include <iostream>
#include <string>
#include <locale>
#include <Windows.h>


using namespace std;

// Функція для порівняння рядків
int custom_compare(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// Функція для перетворення рядкових літер на заголовні
string to_uppercase(const string& str) {
    locale loc("uk_UA.UTF-8");
    string result;
    for (char ch : str) {
        result += toupper(ch, loc);
    }
    return result;
}

// Функція для перевірки валідності рядка 
bool is_valid(const string& str) {
    return !str.empty();
}

void task1() {
    string str1, str2;
    cout << "Введіть перший рядок: ";
    getline(cin, str1);
    cout << "Введіть другий рядок: ";
    getline(cin, str2);

    // Використання методу класу string
    int result_std = str1.compare(str2);
    cout << "Результат стандартного порівняння: " << result_std << endl;

    // Використання користувацької функції
    int result_custom = custom_compare(str1.c_str(), str2.c_str());
    cout << "Результат користувацького порівняння: " << result_custom << endl;
}

void task2() {
    string input;
    cout << "Введіть рядок: ";
    getline(cin, input);

    if (is_valid(input)) {
        string transformed = to_uppercase(input);
        cout << "Перетворений рядок: " << transformed << endl;
    }
    else {
        cout << "Неприпустимий рядок" << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Порівняти два рядки" << endl;
        cout << "2. Перетворити рядок у заголовні літери" << endl;
        cout << "3. Вихід" << endl;
        cout << "Введіть свій вибір: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left in the buffer


        switch (choice) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            cout << "Вихід..." << endl;
            return 0;
        default:
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
    }

    return 0;
}
