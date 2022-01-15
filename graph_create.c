//graph_create.c

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, k;
    int size,rank;
    int topo_type;
    int *index, *edges;
    MPI_Comm comm1, comm2;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

	index = (int*)malloc(rank*sizeof(int));
	edges = (int*)malloc(rank*2*sizeof(int));

	index[0] = 2;
	for (i=1; i<size; i++)
		index[i] = 2 + index[i-1];

	k=0;
	for (i=0; i<size; i++)
	{
		edges[k++] = (i-1+size) % size;
		edges[k++] = (i+1) % size;
	}

	MPI_Graph_create(MPI_COMM_WORLD, size, index, edges, 0, &comm1);
	MPI_Comm_dup(comm1, &comm2 );
	MPI_Topo_test(comm2, &topo_type);

	if (topo_type != MPI_GRAPH)
		printf("Tipe topology bukan MPI_GRAPH\r\n");
	else
		printf("Tipe topology MPI_GRAPH\r\n");


    MPI_Finalize();

    return 0;
}
