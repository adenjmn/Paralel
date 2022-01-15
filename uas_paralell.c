#include <mpi.h>
#include <stdio.h>
int skubus = 15, pbalok=6, lbalok=4,tbalok=3;
int p_a_limas=3, l_a_limas=4,a_a_prisma=4, t_a_prisma=3;
int t_prisma=5, t_limas=5;
float phi = 3.14,r=10;
float vkubus,vbalok,vlimas,vbola,l_alas=(1/2*a_a_prisma*t_a_prisma);

void volume_kubus(){
    vkubus = skubus*skubus*skubus;
    printf("Panjang rusuk kubus =%d \n volume kubus = %f \n",skubus,vkubus);
}
void volume_balok(){
    vbalok = lbalok*pbalok*tbalok;
    printf("panjang balok = %d \n tinggi balok %d \n volume balok = %f \n",pbalok,lbalok,tbalok,vbalok);
}
void volume_limas(){
    int luas_alimas = p_a_limas*l_a_limas;
    vlimas = (luas_alimas*t_limas)/3;
    printf("Panjang alas limas = %d \n lebar alas limas = %d \n tinggi limas = %d \n volume limas segi empat = %f \n",
           p_a_limas,l_a_limas,t_limas,vlimas);
    }
int main(int argc, char *argv[]){
    double startime, endtime;
    int errs =0,err;
    int i,j;
    int rank;
    char *ap;

    MPI_Init(&argc, argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    startime = MPI_Wtime();
    if(rank==0){
        volume_kubus();
        endtime = MPI_Wtime();
        printf("rank %d: total waktu %f detik \r\n",rank,endtime-startime);
    }
    else if(rank==1){
        volume_balok();
        endtime = MPI_Wtime();
        printf("rank %d: total waktu %f detik \r\n",rank,endtime-startime);
    }
    else if(rank==2){
        volume_limas();
        endtime = MPI_Wtime();
        printf("rank %d: total waktu %f detik \r\n",rank,endtime-startime);
    }
}
