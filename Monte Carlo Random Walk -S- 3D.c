/* 3D program to calculate the visited cells */
/*          at every time_step               */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define seed 4375  // numper for seed
#define Nmc 10000
#define steps 100
#define N 10
#define M 500

#define p1 1.0/6.0
#define p2 2.0/6.0
#define p3 3.0/6.0
#define p4 4.0/6.0
#define p5 5.0/6.0

int main (){
	 
	 int i,j,z,imc;
	 int sumx,sumy,sumz;
	 double k;
	 double *S=malloc(N*sizeof(double));
     double *muS=malloc(N*sizeof(double));
     
     int ***grid;
     
     
     
	grid=(int***)malloc(M*sizeof(int**));

    for(i=0;i<M;i++)
    {
        grid[i]=(int**)malloc(M*sizeof(int*));
          
		for(j=0;j<M;j++){
		  
            grid[i][j]=(int*)malloc(M*sizeof(int));
    	}
    }

   
     srand(seed);
    FILE *randomWalk3dS;
    
    randomWalk3dS=fopen("randomWalk3dS.txt","w");
    
    
     // array muS for means S  and array s to hold on values with at least one visit
    for(i=0;i<N;i++){
		muS[i]=0; S[i]=0;
	}	
    
    
    
    
    for(imc=0;imc<Nmc;imc++){
		
		// consider that all cells are free
		
		for (i=0; i<M; i++){
			for (j=0; j<M; j++){
			   for (z=0; z<M; z++){
			   
			grid[i][j][z]=0;
		}
	}
}
		sumx=M/2; 
		sumy=M/2;
		sumz=M/2;
		grid[sumx][sumy][sumz]=1;              // choose a  cell for start on grid
		
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
				   
				 else if(k<=p4)
				    sumy-=1;  
				    
				 else if(k<=p5)
				    sumz+=1;      
			    else
				     sumz-=1;
				
			
				
			// grid conditions
				
				if (sumx<0)  sumx+=M;
				if (sumx>=M) sumx-=M;
				if (sumy<0)  sumy+=M;
				if (sumy>=M) sumy-=M;
				if (sumz<0)  sumz+=M;
				if (sumz>=M) sumz-=M;
				
				
				if (grid[sumx][sumy][sumz]==0)
				     S[i]+=1;
				  
				grid[sumx][sumy][sumz]=1; //  a new cells visited
			}
			
			muS[i]+=(double)S[i]/Nmc;	
		}
		printf("%d ",imc);
}
	
	for(i=1;i<N;i++){
		muS[i]=muS[i-1]+muS[i];	// find sum at evrey step 100,200,300....
	}
	
	for(i=0;i<N;i++){
		
		printf("\n%d\t%f\n",steps*(i+1),muS[i]);
		fprintf(randomWalk3dS,"%d\t%f\n",steps*(i+1),muS[i]);
	}
	
	//free memory
	free(grid);
	free(muS);
	free(S);
	fclose(randomWalk3dS);
	return 0;
}
  
  
    
    
    
    

