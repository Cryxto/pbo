package com.company;

public class Plant{
    int statusTumbuh;//0-4
    int jumlahAir;
    int jumlahPupuk; public Plant() {
        statusTumbuh = 0;
        jumlahAir = 0;
        jumlahPupuk = 0;
    }
    public void beriAir() {
        jumlahAir++;
        cekKondisiTumbuh();
    }
    public void beriPupuk() {
        jumlahPupuk++;
        cekKondisiTumbuh();
    }
    public void cekKondisiTumbuh() {
//cek kecukupan air dan pupuk
        if(jumlahAir >=3 && jumlahPupuk >=1) {
            tumbuh();
        }
    }
    public void tumbuh() {
        if(statusTumbuh <4) {
            jumlahAir = jumlahAir - 3;
            jumlahPupuk = jumlahPupuk - 1;
            statusTumbuh++;
        }
    }
    public void displayPlant() {
        System.out.println(getStatusTumbuhText());
        System.out.println("Jumlah Air:" + jumlahAir);
        System.out.println("Jumlah Pupuk:" + jumlahPupuk);
    }
    public String getStatusTumbuhText() {
        switch(statusTumbuh) {
            case 0: return "Benih";
            case 1: return "Tunas";
            case 2: return "Tanaman Kecil";
            case 3: return "Tanaman Dewasa";
        }
        return "Berbunga";
    }
    public int getStatusTumbuh() {
        return statusTumbuh;
    }
    public String getImagePath() {
        String tImagePath = "img/seed.png";
        switch(statusTumbuh) {
            case 0: tImagePath = "img/seed.png"; break;
            case 1: tImagePath = "img/sprout.png"; break;
            case 2: tImagePath = "img/small.png"; break;
            case 3: tImagePath = "img/big.png"; break;
            case 4: tImagePath = "img/blossom.png"; break;
        }
        return tImagePath;
    }
}


/*public class Main {

    public static void main(String[] args) {
	// write your code here
    }
}*/

