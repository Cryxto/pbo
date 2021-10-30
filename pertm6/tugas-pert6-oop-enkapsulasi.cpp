#include <iostream>
#include <iomanip> 
#include "fungsinya.h"//class dipanggil lewat fungsi
using namespace std;

int main()
{
    int ujiJam[5] = {23, 10, 23, 237, 0};
    int ujiMenit[5] = {59, 70, -9, 100, 0};
    int ujiDetik[5] = {59, 44, 59, 70, 0};
    waktu callWaktu;
    cout<<endl; //agar rapih saja
    for (int i = 0; i < 5; i++)
    {
        cout << "------- Pengecekan " << i+1 <<"  -------"<< endl;
        callWaktu.setWaktu(ujiJam[i], ujiMenit[i], ujiDetik[i]);
        callWaktu.displayJam();
        cout << endl;
    }
    return 0;
}