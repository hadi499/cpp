#include <iostream>

using namespace std;

int main()
{

    int arrayNilai[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int nilai : arrayNilai)
    {
        cout << " nilainya: " << nilai << endl;
        nilai = 1; // tidak merubah array
    }

    for (int nilai : arrayNilai)
    {
        cout << " address: " << &nilai << endl;
        nilai = 1; // tidak merubah array
    }
}