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
        cout << "����:\n1. �������� ������� � �����;\n2. �������� ������� �� ����� (�� ����������);\n"
            "3. �������� ������� �� ����� (��� ���������);\n0. ����������� �����.\n������ �����: ";
        cin >> flag;
        clearCin();
        cout << '\n';
        switch (flag)
        {
        case 0:
            break;
        case 1:
            queue << input("������ �������: ");
            break;
        case 2:
            cout << "�������: " << queue.remove() << "\n\n";
            break;
        case 3:
            cout << "�������: " << queue.queueTop() << "\n\n";
            break;
        default:
            cout << "���������� ��������, ��������� ��.\n\n";
            break;
        }
    } while (flag != 0);
}

void task1()
{
    AQueue<int, int> queue(input("������ ����� �����: "));
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
    SetConsoleTitle(L"����������� ������ �6.4");
    int flag = 0;
    do
    {
        cout << "����:\n1. ����� �� ��������� ������;\n2. ����� �� ��������� ���������;\n"
            "0. �����.\n������ �����: ";
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
            cout << "���������� ��������, ��������� ��.\n\n";
            break;
        }
    } while (flag != 0);
}