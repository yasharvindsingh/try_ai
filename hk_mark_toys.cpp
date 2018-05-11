#include<bits/stdc++.h>

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	qsort(a,n,sizeof(int),compare);
	int sum=0;
	int i=0;
	while(sum <= k)
	{
		sum = sum + a[i];
		printf("%d ",a[i]);
		i++;
	}
	printf("\n");
	printf("%d",i-1);
	return 0;
}