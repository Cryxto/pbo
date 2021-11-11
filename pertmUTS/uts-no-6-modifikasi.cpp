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
    void tambah()
    {
        cout << "Hasil Penjumlahan : " << a + b << endl;
    }
    void kurang()
    {
        cout << "Hasil Pengurangan : " << a - b << endl;
    }
    void kali()
    {
        cout << "Hasil Perkalian : " << a * b << endl;
    }
    void bagi()
    {
        cout << "Hasil Pembagian : " << a / b << endl;
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
             << "1. Tambah\n"
             << "2. Kurang\n"
             << "3. Kali\n"
             << "4. Bagi\n";
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
            hitung.tambah();
            break;
        case 2:
            hitung.setAngka();
            hitung.kurang();
            break;
        case 3:
            hitung.setAngka();
            hitung.kali();
            break;
        case 4:
            hitung.setAngka();
            hitung.bagi();
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