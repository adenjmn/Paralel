#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int numnodes,rank;
int main(int argc, char* argv[])
{
    int *myray,*disp,*counts,*allray;
    int size,data,i;
    size=0;
    MPI_Init( &argc, &argv );
    MPI_Comm_rank( MPI_COMM_WORLD, &rank );
    MPI_Comm_size( MPI_COMM_WORLD, &numnodes );
    data=rank+1;
    myray=(int*)malloc(data*sizeof(int));
    for(i=0;i<data;i++)
    myray[i]=rank+1;
    counts=(int*)malloc(numnodes*sizeof(int));
    disp=(int*)malloc(numnodes*sizeof(int));
    disp[0]=0;
    printf("Rank= %d, data= %d \r\n",rank,data);
    MPI_Gather((void*)myray,1,MPI_INT,
    counts, 1,MPI_INT,
    0,MPI_COMM_WORLD);
    if(rank == 0)
    {
        for( i=1;i<numnodes;i++)
        disp[i]=counts[i-1]+disp[i-1];
        for(i=0;i< numnodes;i++)
        size=size+counts[i];
    }
    allray=(int*)malloc(size*sizeof(int));
    MPI_Gatherv(myray, data, MPI_INT,
    allray,counts,disp,MPI_INT,
    0, MPI_COMM_WORLD);
    if(rank == 0)
    {
        printf(">> ");
        for(i=0;i<size;i++)
        printf("%d ",allray[i]);
        printf("\r\n");
    }
    MPI_Finalize();
    return 0;
}
