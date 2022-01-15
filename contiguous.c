#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
int i,rank;
MPI_Status status;
MPI_Datatype type;
int data[15];
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Type_contiguous(5, MPI_INT, &type);
MPI_Type_commit(&type);
if (rank == 0)
{
printf("Rank %d mengirim data= ",rank);
for(i=0;i<15;i++)
{
data[i] = i;
printf("[%d]:%d ",i,data[i]);
}
printf("\r\n");
MPI_Send(data, 1, type, 1, 99, MPI_COMM_WORLD);
}
else
if (rank == 1)
{
for(i=0;i<15;i++)
data[i] = -1;
MPI_Recv(data, 1, type, 0, 99, MPI_COMM_WORLD, &status);
printf("Rank %d menerima data: ",rank);
for(i=0;i<15;i++)
printf("[%d]:%d ",i,data[i]);
printf("\r\n");
}
MPI_Type_free(&type);
MPI_Finalize();
return 0;
}
