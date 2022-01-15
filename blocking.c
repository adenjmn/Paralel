#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char message[30];
	int myrank;
	MPI_Status status;
	MPI_Init( &argc, &argv );
	MPI_Comm_rank( MPI_COMM_WORLD, &myrank );
	printf("Proses rank: %d \r\n", myrank);

	if (myrank == 0)
	{
		strcpy(message,"Halo ini dari rank 0");
		printf("Data dikirim dari rank 0: %s \r\n", message);
		MPI_Send(message, strlen(message)+1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);
	}
	else if (myrank == 1)
	{
		MPI_Recv(message, 30, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &status);
		printf("Data yang diterima di rank 1: %s \r\n", message);
	}
	MPI_Finalize();
	return 0;
}
