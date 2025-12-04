// lab7.cpp: определяет точку входа для приложения.
//

#include "lab7.h"


#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include<random>
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
    cout << "\nвведите элемент" << endl;

    vector<int> ind;

    int element;
    cin >> element;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            ind.push_back(i);
        }
    }
    cout << "[";
    for (int n : ind)
        std::cout << n << "\t";
    cout << "]\n";
    
}

void showArr(std::array<int, 10> arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size;++i) {
        cout << arr[i] << ' ';
    }
    cout << "]" << endl;
}

void function6() {
    cout << "\nЗадание варианта, мой 2 " << endl;
   
    printArray();
    if (arr.size() % 2 == 0 && arr.size()>1) {
        arr.erase(arr.begin());
        printArray();
    }
    else if(arr.size()>4) {
        while (arr.size() > 4) {
            arr.erase(arr.begin());
        }
        printArray();
    } 
    else { 
        cout << "недостаточно элементов" << endl;
    }
    
}

 //пункт 2 
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}
std::array<int, 10> rVal(std::array<int, 10> arr, bool rev = false) {
    cout << "По значению" << endl;
    int nSize = 10;
    for (int i = 0; i < nSize; ++i) {
        for (int j = i; j < nSize; ++j) {
            if (rev) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
            else {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }

        }
    }

    return arr;
}
void rRef(std::array<int, 10>& arr, bool rev = false) {
    cout << "По ссылке" << endl;
    int nSize = 10;
    for (int i = 0; i < nSize; ++i) {
        for (int j = i; j < nSize; ++j) {
            if (rev) {
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
            else {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }

        }
    }

}
void rPointer(std::array<int, 10>* arr, bool rev = false) {
    cout << "По указателю" << endl;

    int nSize = 10;
    
    for (int i = 0; i < nSize; ++i) {
        for (int j = i; j < nSize; ++j) {
            if (rev) {
                if ((*arr)[i] < (*arr)[j]) {
                    swap((*arr)[i], (*arr)[j]);
                }
            }
            else {
                if ((*arr)[i] > (*arr)[j]) {
                    swap((*arr)[i], (*arr)[j]);
                }
            }

        }
    }
}
void p2() {
    const unsigned short size = 10;
    std::array<int, size> arr1;

    for (int i = 0; i < size;++i) {
        arr1[i] = (rand() % 21) - 10;
    }
    showArr(arr1, size);

    // false\true сортировка по возрастанию\убыванию

    arr1 = rVal(arr1, true); // по значению
    showArr(arr1, size);

    rRef(arr1, true); // по ссылке
    showArr(arr1, size);

    rPointer(&arr1, true); // по указателю
    showArr(arr1, size);


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

    p2();
    return 0;
}