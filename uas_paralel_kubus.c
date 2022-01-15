#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char message[30];
    int myrank;
    int v,s;
    MPI_Status status;
    s = 10;
    v=s*s*s;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &v );
    printf("Hitung Kubus: %d \r\n", v);
    strcpy(message,"Halo ini dari rank 0");
    printf("Data dikirim dari rank 0: %s \r\n", message);
    MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);

    MPI_Finalize();
    return 0;
}
