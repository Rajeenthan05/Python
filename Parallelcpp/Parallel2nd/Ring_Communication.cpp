
//From a ring communication from mater to mater using all the inter connected processor

#include <mpi.h>
#include <stdio.h>

int main()
{

	    int np;
	    int pid;
	    MPI_Init(NULL, NULL);
	    MPI_Comm_size(MPI_COMM_WORLD, &np);
	    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

	MPI_Status sta;

int ring;
if (pid != 0)
{
	
		MPI_Send(&ring, 1, MPI_INT, pid - 1, 0,MPI_COMM_WORLD);
		printf("Process %d received token %d from process %d\n",
			pid, ring, pid - 1);
}
else
{

	   ring = -1;
}
MPI_Send(&ring, 1, MPI_INT, (pid + 1) %np,0, MPI_COMM_WORLD);

if (pid == 0) 
{
	   MPI_Recv(&ring, 1, MPI_INT, np - 1, 0, MPI_COMM_WORLD, &sta);
	   printf("Process %d received token %d from process %d\n",
	   pid, ring, np - 1);
}