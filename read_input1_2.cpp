#include <stdio.h>
using namespace std;
int main()
{
	FILE *in, *out;
	in = fopen("input1_2.txt", "r");
	out = fopen("output1_2.txt", "w");
	int size = fgetc(in) - '0';
	bool a[size][size];
	int i, j;
	for(i=0; i<size; i++){
		for(j=0; j<size; j++)
			a[i][j] = false;
	}
	while(!feof(in)){
		fscanf(in,"%d",&i);
		fscanf(in,"%d",&j);
		a[i][j] = true;
		a[j][i] = true;
	}
	
	fprintf(out, "Ma tran ke bieu dien do thi:\n\n  a b c d e f");
	for(i=0; i<size; i++){
		fprintf(out,"\n\n%c",i+'a');
		for(int j=0; j<size; j++)
			if(a[i][j] == false)
				fprintf(out," 0");
			else
				fprintf(out," 1");
	}
	fprintf(out,"\n\nDanh sach ke:");
	for(int i=0; i<size; i++){
		fprintf(out,"\n%d ",i+1);
		for(int j=0; j<size; j++){
			if(a[i][j] == true){
				fprintf(out,"%d",j+1);
			}
		}
	}
	fprintf(out,"\n\nBac cua tung dinh:");
	for(int i=0; i<size; i++){
		fprintf(out,"\n%c: ",i+'a');
		int rank = 0;
		for(int j=0; j<size; j++){
			if(a[i][j])
				rank++;
		}
		fprintf(out,"%d",rank);
	}
	
	fclose(in);
	fclose(out);
}




