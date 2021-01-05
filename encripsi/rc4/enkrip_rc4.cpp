
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    FILE *Fin, *Fout;
    char p, c, u;
    string K;
    int S[256];
    int i, j, t;

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

    for (i = 0; i < 256; i++)
    {
        S[i] = i;
    }

    j = 0;
    for (i = 0; i < 256; i++)
    {
        j = (j + S[i] + K[i % K.length()]) % 256;
        swap(S[i], S[j]); // pertukaran nilai S[i] dan S[j]
    }

    i = 0;
    j = 0;
    while (!feof(Fin))
    {
        p = getc(Fin);
        i = (i + j) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        t = (S[i] + S[j]) % 256;
        u = S[t];  // keystream
        c = u ^ p; //XOR
        putc(c, Fout);
    }
    fclose(Fin);
    fclose(Fout);
}
// kriptografi hal 238