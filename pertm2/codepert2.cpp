#include <iostream>
#include <cmath>

using namespace std;
//output yang diminta : Berarti usia kalian sekarang adalah 21 tahun

/* Kemungkinan seseorang sedang menerka umur dari beberapa mahasiswa disalah satu universitas,
kebetulan beberapa mahasiswa tersebut adalah semester 5 dan beberapa mahasiswa tersebut sama-sama masuk
setelah lulus dari SMA . Penerka tersebut baru lulus dari SMA */

/* Kita asumsikan orang yang lulus SMA biasanya 18 tahun, lalu kira-kira 2 semester kuliah
menghabiskan waktu 1 tahun */

/* output program akan menebak usia dari beberapa mahasiswa semester 5 tersebut */

/* fungsi untuk menghitung umur mahasiswa semester 5 */

double penghitungTahun (double semester, double uPenerka){
    return (semester/2) + uPenerka;
}

int main (){
    double semester = 5;  //semester mahasiswa saat ini
    double uPenerka = 18 ; //umur dari penerka
    cout<<"Berarti usia kalian sekarang adalah "<< round(penghitungTahun(semester, uPenerka))<<" tahun"; //round untuk membulatkan keatas
    cin.get();
    return 0;
}