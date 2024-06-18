#include<stdio.h>
#include<setjmp.h>

jmp_buf env;

void test(){
	int normal=20;
	register int r =30;
	volatile int v = 49;
	int res= setjmp(env);
	if(res==0){
		printf("intial values : \n r:%d , v :%d,normal: %d",r,v,normal);
	printf("\n");
		r=11;
		normal=28;
		  printf("Modified values : \n r:%d , v :%d,normal: %d",r,v,normal);
printf("\n");
		  longjmp(env,1);
	}
	else{
		  printf("Restoring the previous values: \n r:%d , v :%d,normal: %d",r,v,normal);
		printf("\n");	}}

int main(){
	test();
	return 0;
}

