#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string>  
using namespace std;
int main()
{
FILE *in,*out;
	int  m,x,y,d,s;
	int a[100][100];
	in = fopen("input2_1.txt", "r");
	out = fopen("output2_1.txt", "w");

	int n = fgetc(in) - '0';
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			a[i][j] = 0;
		}
	}
	char c;
	while(!feof(in)){
		c = fgetc(in);
		if(c=='\n'){
			x = fgetc(in)-'0';
			y = fgetc(in)-'0';
		}
		else {
			y = c-'0';
		}
		a[x][y] = 1;
 		
	}
	fprintf(out,"Ma tran ke:\n");
	printf("%d\n",n);
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			fprintf(out,"\t%d ",a[i][j]);
			cout<<a[i][j]<<" ";
			
		}
		fprintf(out,"\n");
		cout<<endl;
	}
	fprintf(out,"Danh sach canh:\n");
	printf("\nCHUYEN TU DANH SACH KE input1_1 SANG DANH SACH CANH output2_1\n");
	for(int i = 1; i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(a[i][j] == 1)
			{
				
				fprintf(out,"\t%d\t%d\n",i,j);
				printf("%d\t%d\n",i,j);
			}
		}
	}
	for(int i = 1; i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			
			s += a[i][j];
			
		}
		fprintf(out,"\nBac cua dinh %d la: %d",i,s);
		cout<<"\nBac cua dinh "<<i<<" la: "<<s<<endl;
		s=0;
		
	}
	
	fclose(in);
	fclose(out);
 return 0;
}

