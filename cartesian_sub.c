//cartesian_sub.c

#include <mpi.h>
#include <stdio.h>

int main( int argc, char *argv[] )
{
    int size, dims[2], periods[2], remain[2];
    int result;
    MPI_Comm comm, newcomm;

    MPI_Init( &argc, &argv );

    periods[0] = 0;
    MPI_Comm_size( MPI_COMM_WORLD, &size );
    dims[0] = size;
    MPI_Cart_create( MPI_COMM_WORLD, 1, dims, periods, 0, &comm );

    remain[0] = 0;
    MPI_Cart_sub( comm, remain, &newcomm );

    MPI_Comm_compare(MPI_COMM_SELF, newcomm, &result );
    if (result != MPI_CONGRUENT)
		printf("newcomm bukan MPI_COMM_SELF\r\n");
	else
		printf("newcomm adalah MPI_COMM_SELF\r\n");

    MPI_Comm_free( &newcomm );
    MPI_Comm_free( &comm );

    MPI_Finalize();
    return 0;
}
