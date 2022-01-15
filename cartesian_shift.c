//cartesian_shift.c

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int rank,size;
	MPI_Comm comm;
	int coord[2],period[2],reorder;
	int up,down,right,left;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size != 12)
    {
        printf("Harus running dengan 12 processes.\r\n");
        MPI_Finalize();
		return 0;
    }

	coord[0]=4; coord[1]=3;
	period[0]=1; period[1]=0;
	reorder=1;
	MPI_Cart_create(MPI_COMM_WORLD,2,coord,period,reorder,&comm);

	MPI_Cart_coords(comm, rank, 2, coord);
	printf("Rank %d, Dimensi 4x3 posisi(%d, %d)\r\n", rank, coord[0], coord[1]);
	if(rank==7)
	{
		MPI_Cart_shift(comm,0,1,&up,&down);
		printf("Rank:%d Up:%d Down:%d\r\n",rank,up,down);
		MPI_Cart_shift(comm,1,1,&left,&right);
		printf("Rank:%d Left:%d Right:%d\r\n",rank,left,right);
	}

	MPI_Finalize();
}
