#include <stdio.h>
void kubus(){
    int s =15;
    int v;
    printf("Hitung Volume Kubus\n");
    printf(" >>Panjang rusuk %d (cm) \n",s);
    v = s*s*s;
    printf("->Volume kubus adalah %d (cm) \n", v);
}
void balok()
{
    int p,l,t,volume;
    printf("Menghitung Nilai Volume Pada Balok \n");
    printf(" >> Masukkan Nilai Panjang Balok = %d \n",p=5);
    printf(" >> Nilai Lebar Balok = %d \n",l=10);
    printf(" >> Nilai Tinggi Balok = %d \n",t=2);
    volume = p*l*t;
    printf("-> Jadi, Nilai Volume Balok = %d \n",volume);
}
void prisma(){
    float sisi=6,tinggi=12,hasil_L,hasil_V;
    float S_miring,S_Tiga;

    printf("Luas dan Volume Limas Segi Empat Beraturan\n\n");
    printf(" >> Tinggi = $d \n",tinggi);
    printf(" >> Panjang sisi = %d \n",sisi);


    S_miring=sqrt((sisi*0.5)*(sisi*0.5)+(tinggi*tinggi));
    S_Tiga=0.5*sisi*S_miring;

    hasil_L=(sisi*sisi)+(4*S_Tiga);
    hasil_V=(0.33333)*(sisi*sisi)*tinggi;

    printf(" >>Luas Limas   = %.2f \n",hasil_L);
    printf("-> Volume Limas = %.2f \n",hasil_V);
}
void bola(){
    int r=9;
    float phi = 3.14, volume;

    //Input Variabel
    printf("Program Menghitung Volume Bola\n");
    printf(" >> Jari-jari : %d \n",r);
    //Menghitung Volume Bola
    volume = (4.0 / 3) * phi * r * r * r;
    printf("->Volume = %.2f\n", volume);
}
int main(){
    kubus();
    balok();
    prisma();
    bola();

    return 0;

}
