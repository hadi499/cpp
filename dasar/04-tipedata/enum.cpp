#include <iostream>

using namespace std;

enum nama_hari
{
    minggu,
    senin,
    selasa,
    rabu,
    kamis,
    jumat,
    sabtu
};

int main()
{
    nama_hari var1;

    var1 = senin;
    cout << var1 << endl;

    var1 = rabu;
    cout << var1 << endl;

    var1 = sabtu;
    cout << var1 << endl;

    return 0;
}
