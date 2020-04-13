#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mp[7][6]={{2,1,1,6,6,6},{1,1,1,6,6,6},{5,5,6,3,6,6},{4,4,4,6,4,6},{4,4,4,6,4,6},{5,5,6,6,6,6,},{6,6,6,6,6,6}};

int columna(char c){
	if(c=='0') return 0;
	if(c>='1' && c<='7') return 1;
	if(c=='8' || c=='9') return 2;
	if(c=='x' || c=='X') return 3;
	if((c>='a' && c<='f') || (c>='A' && c<='F') ) return 4;
	return 5;
}

void determinarTipo(int e){
        if(e==1) printf(" es decimal\n");
	    if(e==2 || e==5) printf(" es octal\n");
	    if(e==4) printf(" es hexadecimal\n");
	    if(e==6) printf(" no se reconoce\n");	
}
void reconocerEnteros(){
    char s[]="0x1234,0123,0xacb";
    char numero[10];
    int e=0,i;
	int a,pos=0;

	for(i=0;s[i]!='\0';i++)	{	
		if(s[i]==','){
		determinarTipo(e);
	    e=0;		
		}
	    else{
		numero[pos]=s[i];
		e=mp[e][columna(s[i])];
		printf("%d\n",e);
	}
	}
	if(s[i]=='\0'){
		determinarTipo(e);
	}	
	return;
}

int main(){
	reconocerEnteros();
	return 0;
}
