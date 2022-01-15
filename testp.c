#include<stdio.h>
#include<stdlib.h>
const float pi = 3.14;
void balok();
void kubus();
void limas();
void prisma();
void bola();
void tabung();
void kerucut();
main() {
    int pil;
    menu:
        printf("======================================n");
        printf("Program Menghitung Volume Bangun Ruangn");
        printf("======================================n");
        printf("1. Balokn2. Kubusn3. Limas SegiTigan4. Prisma Segitigan5. Bolan6. Tabungn7. Kerucunn0. Keluarn");
        printf("Masukkan Pilihan Anda(0-7):");
        scanf("%d", &pil);
        switch(pil) {
            case 1 : balok();
            goto menu;break;
            case 2 : kubus();
            goto menu;break;
            case 3 : limas();
            goto menu;break;
            case 4 : prisma();
            goto menu;break;
            case 5 : bola();
            goto menu;break;
            case 6 : tabung();
            goto menu;break;
            case 7 : kerucut();
            goto menu;break;
            case 0 : printf("Terima Kasih");
            }
            }
            void balok() {
                int p,l,t,v; printf("Menghitung Volume Balokn");
                printf("Masukkan:n");
                printf("tPanjang:");
                scanf("%d", &p); printf("tLebar:");
                scanf("%d", &l); printf("tTinggi:");
                scanf("%d", &t); v = p * l * t; printf("Volume = %dn", v);
            }
            void kubus() {
                int R,v;
                printf("Menghitung Volume Kubusn");
                printf("Masukkan:n");
                printf("tRusuk:");
                scanf("%d", &R); v = R * R * R;
                printf("Volume = %dn", v);
            }
            void limas() {
                float a,t,T,v; printf("Menghitung Volume Limas Segitigan"); printf("Masukkan:n"); printf("tAlas Segitiga:");scanf("%f", &a);
printf("tTinggi Segitiga:");scanf("%f", &t); printf("tTinggi Limas:");scanf("%f", &T); v = ((0.5*a*t)*T)/3.0; printf("Volume = %.2fn", v); } void prisma() { float a,t,T,v; printf("Menghitung Volume Prisma Segitigan"); printf("Masukkan:n"); printf("tAlas Segitiga:");scanf("%f", &a); printf("tTinggi Segitiga:");scanf("%f", &t); printf("tTinggi Prisma:");scanf("%f", &T); v = (0.5*a*t)*T; printf("Volume = %.2fn", v); } void bola() { float r,v; printf("Menghitung Volume Bolan"); printf("Masukkan:n"); printf("tJari-jari:");scanf("%f", &r); v = 4*pi*(r*r*r)/3; printf("Volume = %.2fn", v); } void tabung() { float r,v,t; printf("Menghitung Volume Tabungn");
printf("Masukkan:n"); printf("tJari-jari Alas:");scanf("%f", &r); printf("tTinggi Tabung:");scanf("%f", &t); v = pi*(r*r)*t; printf("Volume = %.2fn", v); } void kerucut() { float r,v,t; printf("Menghitung Volume Kerucutn"); printf("Masukkan:n"); printf("tJari-jari Alas:");scanf("%f", &r); printf("tTinggi Kerucut:");scanf("%f", &t); v =(pi*(r*r)*t)/3.0; printf("Volume = %.2fn", v); }
