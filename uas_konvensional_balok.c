#include <stdio.h>

int main()
{
int p,l,t,volume;

printf("Menghitung Nilai Volume Pada Balok \n");
printf("===============================\n\n");

printf("n Masukkan Nilai Panjang Balok = ");
scanf("%d",&p);

printf("n Masukkan Nilai Lebar Balok = ");
scanf("%d",&l);

printf("n Masukkan Nilai Tinggi Balok = ");
scanf("%d",&t);

volume = p*l*t;
printf("n Jadi, Nilai Volume Balok = %d",volume);
}
