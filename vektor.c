#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
int i,rank;
MPI_Status status;
MPI_Datatype type1,type2;
int data[24];
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Type_contiguous(1, MPI_INT, &type1);
MPI_Type_commit(&type1);
MPI_Type_vector(5, 3, 5, type1, &type2);
MPI_Type_commit(&type2);
if (rank == 0)
{
printf("Rank %d mengirim data= ",rank);
for(i=0;i<24;i++)
{
data[i] = i;
printf("[%d]:%d ",i,data[i]);
}
printf("\r\n");
MPI_Send(data, 1, type2, 1, 99, MPI_COMM_WORLD);
}
else
if (rank == 1)
{
for(i=0;i<24;i++)
data[i] = -1;
MPI_Recv(data, 1, type2, 0, 99, MPI_COMM_WORLD, &status);
printf("Rank %d menerima data= ",rank);
for(i=0;i<24;i++)
printf("[%d]:%d ",i,data[i]);
printf("\r\n");
}
MPI_Type_free(&type2);
MPI_Type_free(&type1);
MPI_Finalize();
return 0;
}
