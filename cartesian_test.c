//cartesian_test.c

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i,topo_type;
    int dims[2], periods[2], size,rank;
    int coord[2],outdims[2], outperiods[2], outcoords[2];
    int *outindex, *outedges;
    MPI_Comm comm1, comm2;

    MPI_Init( &argc, &argv );
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size( MPI_COMM_WORLD, &size );

    dims[0] = dims[1] = 0;
    MPI_Dims_create(size, 2, dims);

    periods[0] = periods[1] = 0;
    MPI_Cart_create(MPI_COMM_WORLD, 2, dims, periods, 0, &comm1);
    MPI_Comm_dup( comm1, &comm2 );

	MPI_Cart_coords(comm2, rank, 2, coord);
	printf("Rank %d posisi(%d, %d)\r\n", rank, coord[0], coord[1]);

    MPI_Topo_test( comm2, &topo_type );
	if (topo_type == MPI_CART)
    {
		outindex = (int*)malloc(size*sizeof(int));
		outedges = (int*)malloc(size*2*sizeof(int));

        MPI_Cart_get( comm2, 2, outdims, outperiods, outcoords);
        for (i=0; i<2; i++)
		{
            if (outdims[i] != dims[i])
				printf("Rank %d -->%d = outdims[%d] != dims[%d] = %d\n",rank, outdims[i], i, i, dims[i] );
			else
				printf("Rank %d -->%d = outdims[%d] == dims[%d] = %d\n", rank,outdims[i], i, i, dims[i] );

            if (outperiods[i] != periods[i])
				printf("Rank %d -->%d = outperiods[%d] != periods[%d] = %d\n", rank,outperiods[i], i, i, periods[i]);
			else
				printf("Rank %d -->%d = outperiods[%d] == periods[%d] = %d\n", rank,outperiods[i], i, i, periods[i]);
        }
    }

    MPI_Finalize();

    return 0;
}
