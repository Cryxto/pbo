#include <iostream>
#include <iomanip>
using namespace std;
class waktu{
    private:
        int jam, menit, detik, day=0;
        bool chekcer;
    public:
    waktu(int jam=0, int menit=0, int detik=0);
    void setWaktu(int j, int m, int d);
    void checkNfix();
    void displayJam();
};

