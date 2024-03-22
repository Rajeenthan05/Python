//Master should Recieve an integer value to all other inter connected processor
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

	if (pid == 0)
	{
		for (int i = 1; i < np; i++)
		{
			int msg;
			MPI_Recv(&msg, 1, MPI_INT, i, 50, MPI_COMM_WORLD, &sta);
			printf("my processor id is %d and iam the sender of pid %d\n", pid, i,msg);
		}
	}

	else
	{
		int s_msg;
		MPI_Send(&pid, 1, MPI_INT, 0, 50, MPI_COMM_WORLD);
		printf("my processor id is %d and iam the reciever of pid %d\n", pid, pid);
	}

	MPI_Finalize();
	return 0;
}