#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    FILE *Fin, *Fout;
    char p, c;
    string K;
    int i;

    Fin = fopen(argv[1], "rb");
    if (Fin == NULL)
    {
        cout << "Berkas" << argv[1] << "tidak ada" << endl;
        exit(0);
    }

    Fout = fopen(argv[2], "wb");
    cout << "Kata kunci : ";
    cin >> K;
    cout << "Enkripsi " << argv[2] << "...";
    i = 0;
    while (!feof(Fin))
    {
        p = getc(Fin);
        c = p ^ K[i];
        putc(c, Fout);
        i = (i + 1) % K.length();
    }
    fclose(Fin);
    fclose(Fout);
}

//kriptografi hal 187
