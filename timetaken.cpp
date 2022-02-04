#include<time.h>
#include<stdio.h>
void take_enter(){
	printf("press enter to stop counter\n");
	while(1){
		if(getchar())
		break;
	}
}
int main(){
	//calculate the time taken by the take_enter()
	clock_t t;
	t = clock();
	printf("Timer starts\n");
	take_enter();
	printf("Timer ends\n");
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; //calaculate the elapsed time
		printf("The program took %f seconds to execute", time_taken);
	double h,m,s;
	h=(time_taken/3600);
	
	m=(time_taken/60);
	
	 s=(time_taken-(m*60));
	
   printf("\n %1.fH : %1.fM :%2.fS\n",h,m,s);
	
}



