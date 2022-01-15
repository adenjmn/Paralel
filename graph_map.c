//graph_map.c
#include <mpi.h>
#include <stdio.h>

int main( int argc, char *argv[] )
{
    int newrank, rank;
    int index[2], edges[2];

    MPI_Init( &argc, &argv );

    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_set_errhandler(MPI_COMM_WORLD, MPI_ERRORS_RETURN);

    index[0] = 0;
    edges[0] = 0;
    MPI_Graph_map(MPI_COMM_WORLD, 1, index, edges, &newrank );

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
