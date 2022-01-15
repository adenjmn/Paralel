//cartesian_map.c
#include <mpi.h>
#include <stdio.h>


int main( int argc, char *argv[] )
{
    int dims[2];
    int periods[2];
    int size, rank, newrank;

    MPI_Init( &argc, &argv );
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );

    periods[0] = 1;
    dims[0] = 1;
    MPI_Cart_map(MPI_COMM_WORLD, 1, dims, periods, &newrank );
    if (rank > 0)
	{
        if (newrank != MPI_UNDEFINED)
			printf("newrank %d bukan UNDEFINED\r\n",newrank);
		else
			printf("newrank %d UNDEFINED\r\n",newrank);
    }
    else
	{
        if (rank != newrank)
			printf("Newrank %d tidak terdefinisi. Seharusnya bernilai 0\r\n",newrank);
		else
			printf("Newrank = rank = %d\r\n",rank);
    }

    MPI_Finalize();
    return 0;
}
