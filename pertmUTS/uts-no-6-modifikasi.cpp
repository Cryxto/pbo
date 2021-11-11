#include <iostream>
using namespace std;
class perhitungan
{
private:
    double a;
    double b;

public:
    void setAngka()
    {
        cout << "Masukan angka 1 : ";
        cin >> a;
        cout << "Masukan angka 2 : ";
        cin >> b;
    }
    void penambahan()
    {
        cout << "Hasil Penjumlahan : " << a + b << endl;
    }
    void pengurangan()
    {
        cout << "Hasil Pengurangan : " << a - b << endl;
    }
    void perkalian()
    {
        cout << "Hasil Perperkalianan : " << a * b << endl;
    }
    void pembagian()
    {
        cout << "Hasil Pempembagianan : " << a / b << endl;
    }
};
int main()
{
    perhitungan hitung;
    int menu;
    char confirm = 'y';
    bool switcher = false;
    bool switcher2 = true;
    while (switcher == false)
    {
        cout << endl;
        cout << "MENU PROGRAM MATEMATIKA SEDERHANA \n"
             << "0. Keluar\n"
             << "1. penambahan\n"
             << "2. pengurangan\n"
             << "3. perkalian\n"
             << "4. pembagian\n";
        cout << "PILIH : ";
        cin >> menu;
        while (menu > 4 || menu < 0)
        {
            cout << "Menu tidak tersedia! Pilih yang tersedia!" << endl;
            cout << "PILIH : ";
            cin >> menu;
        }
        switch (menu)
        {
        case 0:
            switcher = true;
            break;
        case 1:
            hitung.setAngka();
            hitung.penambahan();
            break;
        case 2:
            hitung.setAngka();
            hitung.pengurangan();
            break;
        case 3:
            hitung.setAngka();
            hitung.perkalian();
            break;
        case 4:
            hitung.setAngka();
            hitung.pembagian();
            break;
        default:
            cout << "Menu tidak ada! Silahkan pilih menu yang ada!" << endl;
            break;
        }
        if (switcher == false)
        {
            cin.ignore();
            cout << "Ingin memilih menu lain (y/t)?  ";
            cin >> confirm;
            if (confirm == 't' || confirm == 'T')
            {
                switcher = true;
            }
        }
    }
    cout << "Thanks" << endl;
    return 0;
}