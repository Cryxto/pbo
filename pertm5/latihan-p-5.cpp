#include <iostream>
using namespace std;

class segitiga{
    private :
    int alas,tinggi;
    public :
    void setAlas(int a){
        alas = a;
    }
    void setTinggi(int t){
        tinggi = t;
    }
    int hitungLuas(){
        return  alas*tinggi*0.5;
    }
};

int main(){
    segitiga menghitung;
    menghitung.setAlas(10);
    menghitung.setTinggi(8);
    cout<<menghitung.hitungLuas();
}
