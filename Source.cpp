#include <iostream> 
#include <math.h>
#include <string>
#include <Windows.h>

using namespace std;


template <typename T>
void Print(T arr, int t);

template <typename T>
T* set_and(T* arr1, T* arr2, int size_1, int size_2, int& size_3);

template <typename T>
T* set_and_if(T* arr1, T* arr2, int size_1, int size_2, int& size_4);

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size_1(6);
    int* arr1 = new int[size_1] { 2, 25, 48, 7, 15, 26 };
    cout << "Перший масив:" << endl;
    Print(arr1, size_1);

    const int size_2(10);
    int* arr2 = new int[size_2] {1, 3, 25, 8, 14, 48, 17, 7, 84, 26 };
    cout << "Другий масив:" << endl;
    Print(arr2, size_2);

    int size_3(0);
    int* arr3 = set_and(arr1, arr2, size_1, size_2, size_3);
    cout << "Перетин першого та другого масивів:" << endl;
    Print(arr3, size_3);

    int size_4(0);
    int* arr4 = set_and_if(arr1, arr2, size_1, size_2, size_4);
    cout << "Перетин першого та другого масивів (за умови що клкменти парні):" << endl;
    Print(arr4, size_4);

    return 0;
}

template <typename T>
void Print(T arr, const int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

template <typename T>
T* set_and(T* arr1, T* arr2, int size_1, int size_2, int& size_3)
{
    int* arr3 = new int[size_1 + size_2]{};

    for (int i = 0; i < size_1; i++)
        for (int k = 0; k < size_2; k++)
            if (arr1[i] == arr2[k])
                arr3[size_3++] = arr1[i];

    return arr3;
}
template <typename T>
T* set_and_if(T* arr1, T* arr2, int size_1, int size_2, int& size_4)
{
    int* arr4 = new int[size_1 + size_2]{};

    for (int i = 0; i < size_1; i++)
        for (int k = 0; k < size_2; k++)
            if (arr1[i] == arr2[k] && arr1[i]%2==0 && arr2[k]%2==0)
                arr4[size_4++] = arr1[i];

    return arr4;
}