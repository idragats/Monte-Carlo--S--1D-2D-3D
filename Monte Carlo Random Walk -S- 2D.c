/* 2D program to calculate the visited cells */
/*          at every time_step               */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define seed 4375  // numper for seed
#define Nmc 10000
#define steps 100 // time step
#define N 10
#define M 500 // size of grid 1D

#define p1 0.25
#define p2 0.50
#define p3 0.75

int main (){
	 
	 int i,j,imc;
	 int sumx,sumy;
	 double k;
	 double *S=malloc(N*sizeof(double));
     double *muS=malloc(N*sizeof(double));
     int (*grid)[M] = malloc(sizeof(int[M][M]));
     
     srand(seed);
    FILE *randomWalk2dS;
    
    randomWalk2dS=fopen("randomWalk2dS.txt","w");
    

     // array muS for means S  and array s to hold on values with at least one visit
    for(i=0;i<N;i++){
		muS[i]=0; S[i]=0;
	}	
    
    
    
    
    for(imc=0;imc<Nmc;imc++){
		
		// consider that all cells are free 
		
		for (i=0; i<M; i++){
			for (j=0; j<M; j++){
			
			grid[i][j]=0.0;
		}
	}
		sumx=rand()/RAND_MAX *M ; 
		sumy=rand()/RAND_MAX *M ;
		grid[sumx][sumy]=1;              /// choose a  cell for start on grid
		
		// start with the first cell occupied
		
		S[0]=1.;                    
			
		for(i=0;i<N;i++){
			     
					S[i+1]=0.0;
			for(j=0;j<steps;j++){
				
				 k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	
				if(k<=p1) 		
				  sumx+=1;	
				  
				else if(k<=p2) 	
				  sumx-=1;
				  
				else if(k<=p3)  
				   sumy+=1;
				   
				 else
				    sumy-=1;  
				
			
				
			// grid conditions
				
				if (sumx<0)  sumx+=M;
				if (sumx>=M) sumx-=M;
				if (sumy<0)  sumy+=M;
				if (sumy>=M) sumy-=M;
				
				if (grid[sumx][sumy]==0)
				     S[i]+=1;
				  
				grid[sumx][sumy]=1; //  a new cells visited
			}
			
			muS[i]+=(double)S[i]/Nmc;	
		}
}
	
	for(i=1;i<N;i++){
		muS[i]=muS[i-1]+muS[i];	// find sum at evrey step 100,200,300....
	}
	
	for(i=0;i<N;i++){
		
		printf("%d\t%f\n",steps*(i+1),muS[i]);
		fprintf(randomWalk2dS,"%d\t%f\n",steps*(i+1),muS[i]);
	}
	//free memory
	free(grid);
	free(muS);
	free(S);
	fclose(randomWalk2dS);
	return 0;
}
  
  
    
    
    
    

