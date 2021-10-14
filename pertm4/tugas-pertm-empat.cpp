#include <iostream>

using namespace std;

class age{
    private:
    int x, y;

    public:
    void assign(int bornYear, int currentYear){
        x=bornYear;
        y=currentYear;
    }
    int usia(){
        return x-y;
    }
    
};

int main(){
    age obj;
    obj.assign(2021, 1990);
    cout<<"Berarti Usia Kalian sekarang adalah "<<obj.usia()<<" Tahun"<<endl;
    return 0;
}

