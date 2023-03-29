/* 1D program to calculate the visited cells */
/*          at every time_step               */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define seed 4375  // numper for seed
#define M 500  // size of grid 1D
#define Nmc 10000
#define steps 100  // time step
#define N 10

#define p1 0.5


int main (){
	 
	 int i,j,imc;
	 int sumx;
	 double k;
	 double*S=malloc(N*sizeof(double)); //allocate memory 
     double*muS=malloc(N*sizeof(double)); // allocate memory
     
     int*grid=malloc(M*sizeof(double));  //allocate memory
     
     srand(seed);
    FILE *randomWalk1dS;
    
    randomWalk1dS=fopen("randomWalk1dS.txt","w");
    
    // array muS for means S  and array s to hold on values with at least one visit
    for(i=0;i<N;i++){
		muS[i]=0; S[i]=0;
	}	
    
    for(imc=0;imc<Nmc;imc++){
		
		// consider that all cells are free
		
		for (i=0; i<M; i++){
			grid[i]=0.0;
		}
		
		
		grid[sumx]=1;              // choose a  cell for start on grid
		
		// start with the first cell occupied
		
		S[0]=1.;                    
			
		for(i=0;i<N;i++){
			     
					S[i+1]=0.0;
			for(j=0;j<steps;j++){
				
				 k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	
				if(k<=p1) 		
				  sumx+=1;	
				else 
				  sumx-=1;
				
				// grid conditions
				
				if (sumx<0)  sumx+=M;
				if (sumx>=M) sumx-=M;
				
				
				if (grid[sumx]==0)
				     S[i]+=1;
				  
				grid[sumx]=1; //  a new cells visited
			}
			
			muS[i]+=(double)S[i]/Nmc;	
			
		}
		
	}
	
	for(i=1;i<=N;i++){
		muS[i]=muS[i-1]+muS[i];	// find sum at evrey step 100,200,300....
	}
	
	for(i=0;i<N;i++){
		
		printf("%d\t%f\n",steps*(i+1),muS[i]);
		fprintf(randomWalk1dS,"%d\t%f\n",steps*(i+1),muS[i]); // write data
	}
	//free memory
	free(grid);
	free(muS);
	free(S);
	fclose(randomWalk1dS);
	return 0;
}
  
  
    
    
    
    

