
#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main()
{
	int n,sum;
	int a[10][10];
	FILE *in, *out1, *out2;
	in = fopen("input2.txt", "r");
	out1 = fopen("input2_1.txt", "w");
	out2 = fopen("input2_2.txt", "w");

	fscanf(in, "%d",&n);
	for(int i = 0; i<n;i++)
	{
		for(int j = 0; j<n;j++)
		{
			fscanf(in,"%d",&a[i][j]);
		}
	}
	for(int i = 0; i<n;i++){
		
		for(int j = 0;j<n;j++){
			
			 sum += a[i][j];
		}
		
	}
	int t[10];
	fprintf(out1,"%d",n);
	cout<<n<<" "<<sum<<endl;
	cout<<"DANH SACH KE"<<endl;
	for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                t[j]=1;
            }
        }
        fprintf(out1,"\n%d ",i+1);
        printf("\t%d\t ",i+1);
        for(int a=0;a<n;a++)
        {
            if(t[a]==1)
            {
                fprintf(out1,"%d",a+1);
                printf("%d ",a+1);
                t[a]=0;
            }
        }
        printf("\n");
    }
    fprintf(out2,"%d ",n);
    fprintf(out2,"%d\n",sum);	

	cout<<n<<" "<<sum<<endl;
	cout<<"DANH SACH CANH: \n";
	for(int i = 0; i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(a[i][j] == 1)
			{
				fprintf(out2,"\t%d\t%d\n",i+1,j+1);
				printf("\t%d\t%d\n",i+1,j+1);
			}
		}
	}	
	fclose(in);
	fclose(out1);
	fclose(out2);
 return 0;
}
