#include<stdio.h>
#include<reg51.h>

sbit s1=P1^0;
sbit s2=P1^1;
sbit s3=P1^2;
sbit s4=P1^3;

sbit l1=P2^0;
sbit l2=P2^1;
sbit l3=P2^2;
sbit l4=P2^3;


int main(){
  P1=0x00;
	P2=0x00;
	while(1){
	if(s1==1){
		l1=1;
	}
	else{
		l1=0;
	}
	if(s2==1){
		l2=1;
	}else{
		l2=0;
	}
	if(s3==1){
		l3=1;
	}
	else{
		l3=0;
	}
	if(s4==1){
		l4=1;
	}
	else{
		l4=0;
	}
}
	
}