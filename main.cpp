#include "aQueue.h"
#include "pQueue.h"
#include "other.h"

#include <iostream>
#include <Windows.h>

using namespace std;

int input(const char* text)
{
    int result;
    cout << text;
    cin >> result;
    cout << '\n';
    clearCin();
    return result;
}

template<typename Queue>
void helpQueue(Queue& queue)
{
    int flag;
    do
    {
        cout << "Меню:\n1. Вставити елемент в чергу;\n2. Отримати елемент із черги (із видаленням);\n"
            "3. Отримати елемент із черги (без видалення);\n0. Повернутись назад.\nВведіть опцію: ";
        cin >> flag;
        clearCin();
        cout << '\n';
        switch (flag)
        {
        case 0:
            break;
        case 1:
            queue << input("Введіть елемент: ");
            break;
        case 2:
            cout << "Елемент: " << queue.remove() << "\n\n";
            break;
        case 3:
            cout << "Елемент: " << queue.queueTop() << "\n\n";
            break;
        default:
            cout << "Некоректне введення, спробуйте ще.\n\n";
            break;
        }
    } while (flag != 0);
}

void task1()
{
    AQueue<int, int> queue(input("Введіть розмір черги: "));
    helpQueue<AQueue<int, int>>(queue);
}

void task2()
{
    PQueue<int> queue;
    helpQueue<PQueue<int>>(queue);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SetConsoleTitle(L"Лабораторна робота №6.4");
    int flag = 0;
    do
    {
        cout << "Меню:\n1. Черга за допомогою масивів;\n2. Черга за допомогою покажчиків;\n"
            "0. Вихід.\nВведіть опцію: ";
        cin >> flag;
        clearCin();
        cout << '\n';
        switch (flag)
        {
        case 0:
            break;
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        default:
            cout << "Некоректне введення, спробуйте ще.\n\n";
            break;
        }
    } while (flag != 0);
}