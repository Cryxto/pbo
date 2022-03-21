package com.company;

import java.util.Scanner;

public class PlantMain {
    public static void main(String[] args) {
        Plant p = new Plant();
        Scanner sc = new Scanner(System.in);
        int inp = 0;
        do {
            System.out.println("Masukkan: 0 untuk memberi air, 1 untuk memberi pupuk, 999 untuk keluar");
            inp = sc.nextInt();
            switch(inp){
                case 0: p.beriAir();
                    break;
                case 1: p.beriPupuk();
                    break;
            }
            p.displayPlant();
        } while (inp!=999);
    }
}

