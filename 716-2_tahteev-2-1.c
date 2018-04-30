#include <stdio.h>
int main(){
	int n,y=1,a,b,k=1;
	scanf("%d",&n);
	scanf("%d",&a);
	while(y<=n-1){
		scanf("%d",&b);
	if(a<=b)
		k++;
	a=b;
	y++;
	};
	if(k==n) 
		printf("\n%d\n",1);
	else printf("\n%d\n",0);
	return 0;
	}
