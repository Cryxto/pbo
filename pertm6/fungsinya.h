#include<iostream>
#include<iomanip>
#include "waktu.h"
using namespace std;
waktu::waktu(int jam, int menit, int detik) //constructor
{
    setWaktu(jam, menit, detik);

}

void waktu::setWaktu(int j, int m, int d) //set waktu
{
    jam = j;
    menit = m;
    detik = d;
}

void waktu::setWaktu2(){
    cout<<"Masukan Jam : "; cin>>waktu::jam;
    cout<<"Masukan Menit : "; cin>>waktu::menit;
    cout<<"Masukan Detik : "; cin>>waktu::detik;
}

void waktu::checkNfix()
{ //melakukan pengecekan waktu
    if (jam < 0 || menit < 0 || detik < 0)
    { //jika waktu ada yang kurang dari 0 maka nanti akan ada pesan error
        chekcer = false;
    }
    /* pengecekan apakah lebih dari 23:59:59 mulai dari detik dulu agar ketika jam 24 maka hari akan bertambah 1 */

    while (detik > 59)
    {
        detik = detik - 60;
        ++menit;
    }

    while (menit > 59)
    {
        menit = menit - 60;
        ++jam;
    }

    while (jam > 23)
    {
        jam = jam - 24;
        ++day;
    }
}
/* melakukan cetak waktu */
void waktu::displayJam()
{
    waktu::checkNfix();
    if (waktu::chekcer == false)
    {
        cout << "Format jam/menit/detik ada yang kurang dari 0" << endl;
    }
    else if (day > 0)
    {
        cout << "Jam lebih dari 23:59:59" << endl;
        cout << "Jadi waktu menunjukan " << day << " hari lewat : " << endl;
        cout << setw(2) << setfill('0') << jam << ":" << setw(2) << setfill('0') << menit << ":" << setw(2) << setfill('0') << detik << endl;
    }
    else 
    {
        cout << setw(2) << setfill('0') << jam << ":" << setw(2) << setfill('0') << menit << ":" << setw(2) << setfill('0') << detik << endl;
    }
    day =0; /* mereset hari agar ketika
                memasukan dan menampilkan data lain tidak terjadi bug
                karena hari tidak diinput */

    chekcer = true;/* mereset chekcer agar ketika
                memasukan dan menampilkan data lain tidak terjadi bug
                karena chekcer tidak diinput */
}


