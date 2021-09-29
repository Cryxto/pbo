#include <iostream>
using namespace std;

double luaspersegipanjang(double panjang, double lebar){
    return panjang*lebar ;
}

void definer (int angka){
    if (angka%2==0){
        cout<<"Genap";
    }
    else {
        cout<<"Ganjil";
    }
}
int main (){
double p,l;
int a;
cout<<"----Menghitung Luas Persegi Panjang----"<<endl;
cout<<"Panjang : ";cin>>p;
cout<<"Lebar : ";cin>>l;
cout<<"Luas persegi panjang : "<<luaspersegipanjang(p,l)<<endl<<endl;
cout<<"----Cek Angka Genap Ganjil----"<<endl;
cout<<"Angka untuk cek : "; cin>>a; 
cout<<"Angka ganjil/genap : ";definer(a);


return 0;
}