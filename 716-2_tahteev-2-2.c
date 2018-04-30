#include <stdio.h>
#include<math.h>

int main(){
	int n,x,i,s=0;
	i=1;
	scanf("%d",&n);
	while (i<=n)
		{
		scanf("%d",&x);
		s=s+(pow(-1,i+1)*pow(x,3));
		i++;
		};
	printf("%d\n",s);
	return 0;
}
