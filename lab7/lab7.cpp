// lab7.cpp: определяет точку входа для приложения.
//

#include "lab7.h"


#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>

#include <ctime>
#include <algorithm>

using namespace std;

vector<int> arr{ 1, 2, 3 };


// Реализация функций
void printMenu() {
    cout << "      МЕНЮ      " << endl;
    cout << "0. Выход" << endl;
    cout << "1. Просмотр массива." << endl;
    cout << "2. Добавить элемент в начало." << endl;
    cout << "3. Добавить элемент в конец." << endl;
    cout << "4. Очистка всего массива." << endl;
    cout << "5. Поиск элемента в массиве." << endl;
    cout << "6. Задание варианта." << endl;
    cout << "" << endl;
    cout << "Выберите пункт: ";
}

void printArray() {
    cout << "\nПросмотр массива." << endl;

    cout << "[";
    for (int n : arr)
        std::cout << n << "\t";
    cout << "]\n";
}


void function2() {
    cout << "\nДобавить элемент в начало." << endl;
    cout << "\n введите элемент для добавления " << endl;
    int VAD;
    cin >> VAD;
    arr.insert(arr.begin(), VAD);
}

void function3() {
    cout << "\nДобавить элемент в конец." << endl;
    cout << "\n введите элемент для добавления " << endl;
    int VAD;
    cin >> VAD;
    arr.push_back(VAD);
}

void function4() {
    cout << "\nОчистка всего массива." << endl;
    arr.clear();
}

void function5() {
    cout << "\nПоиск элемента в массиве." << endl;  
    cout << "\nВведите элемент" << endl;

    int element;
    cin >> element;
    
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == element) {
            cout<< "индекс" << i; // возвращаем индекс найденного элемента
            cout << "\n" << endl;

        }
    }
     
    
}

void function6() {
    cout << "\nВызвана функция 2" << endl;
    if (arr.size() % 2 == 0) {
        arr.erase(arr.begin());
    }
    else {
        while (arr.size() > 4) {
            arr.erase(arr.begin());
        }
    }
}

int main() {
    int choice;
    setlocale(LC_ALL, "");
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Выход из программы." << endl;
            break;
        case 1:
            printArray();
            break;
        case 2:
            function2();
            break;
        case 3:
            function3();
            break;
        case 4:
            function4();
            break;
        case 5:
            function5();
            break;
        case 6:
            function6();
            break;

        default:
            cout << "Неверный выбор" << endl;
        }

      

    } while (choice != 0);

    return 0;
}
