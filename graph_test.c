//graph_test.c

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i, k;
    int size,rank;
    int topo_type;
    int *index, *edges,*outindex,*outedges;
    MPI_Comm comm1, comm2;


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

	index = (int*)malloc(rank * sizeof(int) );
	edges = (int*)malloc(rank * 2 * sizeof(int) );


	index[0] = 2;
	for (i=1; i<size; i++)
		index[i] = 2 + index[i-1];

	k=0;
	for (i=0; i<size; i++)
	{
		edges[k++] = (i-1+size) % size;
		edges[k++] = (i+1) % size;
	}

	MPI_Graph_create(MPI_COMM_WORLD, size, index, edges, 0, &comm1 );
	MPI_Comm_dup(comm1, &comm2 );
	MPI_Topo_test(comm2, &topo_type);

	if(topo_type==MPI_GRAPH)
	{
		int nnodes, nedges;
		MPI_Graphdims_get( comm2, &nnodes, &nedges );
		printf("Rank %d -->Nnodes:size = %d:%d\r\n",rank,nnodes, size);
		printf("Rank %d -->nedges:2*size = %d:%d\r\n",rank,nedges, 2*size);

		outindex = (int*)malloc(size*sizeof(int));
		outedges = (int*)malloc(size*2*sizeof(int));
		MPI_Graph_get(comm2, size, 2*size, outindex, outedges);
		for (i=0; i<size; i++)
		{
			if (index[i] != outindex[i])
				printf("Rank %d -->%d = index[%d] != outindex[%d] = %d\r\n",
				rank,index[i], i, i, outindex[i]);
			else
				printf("Rank %d -->%d = index[%d] == outindex[%d] = %d\r\n",
				rank,index[i], i, i, outindex[i]);
		}
		for (i=0; i<2*size; i++)
		{
			if (edges[i] != outedges[i])
				printf("Rank %d -->%d = edges[%d] != outedges[%d] = %d\r\n",
				rank,edges[i], i, i, outedges[i]);
			else
				printf("Rank %d -->%d = edges[%d] != outedges[%d] = %d\r\n",
				rank,edges[i], i, i, outedges[i]);
		}
	}


    MPI_Finalize();

    return 0;
}
