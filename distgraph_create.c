//distgraph_create.c

// KODE PROGRAM ini menggunakan MPICH2

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size,rank;
    int topo_type;
    MPI_Comm comm1, comm2;
	int  x, y;
	int sources[1], degrees[1];
	int destinations[8], weights[8];

	int P = 2,Q = 2; // size = P*Q


    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

	y=rank%P; x=rank%P;
	destinations[0] = P*y+(x+1)%P; weights[0] = 2;
	destinations[1] = P*y+(P+x-1)%P; weights[1] = 2;

	destinations[2] = P*((y+1)%Q)+x; weights[2] = 2;
	destinations[3] = P*((Q+y-1)%Q)+x; weights[3] = 2;

	destinations[4] = P*((y+1)%Q)+(x+1)%P; weights[4] = 1;
	destinations[5] = P*((Q+y-1)%Q)+(x+1)%P; weights[5] = 1;
	destinations[6] = P*((y+1)%Q)+(P+x-1)%P; weights[6] = 1;
	destinations[7] = P*((Q+y-1)%Q)+(P+x-1)%P; weights[7] = 1;
	sources[0] = rank;
	degrees[0] = 8;

	MPI_Dist_graph_create(MPI_COMM_WORLD, 1, sources, degrees, destinations,
			weights, MPI_INFO_NULL, 1, &comm1);
	MPI_Comm_dup(comm1, &comm2 );
	MPI_Topo_test(comm2, &topo_type);

	if (topo_type != MPI_GRAPH)
		printf("Tipe topology bukan MPI_GRAPH\r\n");
	else
		printf("Tipe topology MPI_GRAPH\r\n");

    MPI_Finalize();

    return 0;
}
