#include<stdio.h>
#include<reg51.h>

sbit m1=P2^0;
sbit m2=P2^1;
void delay(int t){
	int i,j;
	for(i=0;i<1000;i++){
		for(j=0;j<t;j++){
		}
	}
}
int main(){
	do{
		m1=1;
		m2=0;
		delay(200000);
		m1=0;
		m2=0;
		delay(200000);
		m1=0;
		m2=1;
		delay(200000);
		m1=0;
		m2=0;
		delay(200000);
	}while(1);
}
