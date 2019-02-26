#include<stdio.h>
int V[100][100],D[100],P[100];
void initialize(int n)
{
	FILE *fp=fopen("input.txt","r");
	int i,j;
	fseek(fp,1,SEEK_SET);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			//printf("Enter %c %c : ",i+65,j+65);
			fscanf(fp,"%d",&V[i][j]);
		}
	}
}
void makeDist(int s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==s)
		{
			D[i]=0;
		}
		else if(V[s][i]==0)
		{
			D[i]=1000000000;
		}
		else if(V[s][i]!=0)
		{
			D[i]=V[s][i];
		}
	}
}
int considered(int *C,int l,int v)
{
	int i;
	for(i=0;i<l;i++)
	{
		if(C[i]==v)
			return 1;
	}
	return 0;
}
int C[100];
void shortestPath(int s,int n)
{
	int l=0,i=0,w=0,v,u,min;
	//C[0]=s;
	//min=0;
	while(l!=n)
	{
		for(i=0;i<n;i++)
		{
			if(l==0)
			{
				min=s;
				break;
			}
			if(considered(C,l,i)==0)
			{
				min=i;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			if(D[min]>D[i]&&i!=s&&considered(C,l,i)==0)
				min=i;
		}
		C[l++]=min;
		//printf("C%dC",min);		
		for(u=0;u<n;u++)              
		{
			if(V[min][u]!=0&&D[u]>=V[min][u]+D[min])
			{
				D[u]=V[min][u]+D[min];
				P[u]=min;
			}
			
		}		
	}
	//printf("\n");
	for(i=0;i<l;i++)
		printf("%c ",i+65);
	printf("\n");
}
void print(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",D[i]);
	}
}
void printParent(int n,int s)
{
	int i,j,R[100],c=0;
	for(i=0;i<n;i++)
	{
		j=C[i];
		printf("%c-%c ",j+65,s+65);
		while(j!=s)
		{
			//printf("C\n");
			R[c++]=j+65;
			j=P[j];
		}
		
		for(j=c-1;j>=0;j--)
		{
			printf("%c ",R[j]);
		}
		//printf("\n");
		
		c=0;
		printf("\n");
	}
	/*for(i=0;i<n;i++)
	{
		printf("%c ",P[i]+65);
	}*/
	/*for(j=c-1;j>=0;j--)
	{
		printf("%c ",C[j]+65);
	}*/
}
int main()
{
	int n;char s;
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	initialize(n);
	printf("Enter the source : ");
	scanf("%c",&s);
	makeDist((int)s-65,n);
	shortestPath((int)s-65,n);
	print(n);
	printf("\n");
	printf("Path:\n");
	printParent(n,(int)s-65);
}
/*0 1 0 0 0 0 2 0 0 0 0 3 0 0 0 0*/
//0 5 10 0 0 0 0 0 1 4 0 0 3 0 0 2 2 0 0 0 3 0 0 12 0 0 0 0 0 3 0 0 0 0 0 0
//0 4 0 0 0 0 0 8 0 4 0 8 0 0 0 0 11 0 0 8 0 7 0 4 0 0 2 0 0 7 0 9 74 0 0 0 0 0 0 9 0 10 0 0 0 0 0 4 14 10 0 2 0 0 0 0 0 0 0 2 0 1 6 8 11 0 0 0 0 1 0 7 0 0 2 0 0 0 6 7 0
