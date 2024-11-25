#include<stdio.h>
#include<reg51.h>

void delay(int t){
	int i,j;
	for(i=0;i<2000;i++){
		for(j=0;j<t;j++){
		}
	}
}

int main(){
	do{
		P2=0x09;
		delay(100);
		P2=0x0C;
		delay(100);
		P2=0x06;
		delay(100);
		P2=0x03;
		delay(100);
	}while(1);
}