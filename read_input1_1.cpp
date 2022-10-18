#include<stdio.h>

int main(){
	FILE* in1_1 = fopen("input1_1.txt","r");
	int n = fgetc(in1_1) - '0';
	bool a[n][n];
	for(int k=0; k<n; k++){
		for(int l=0; l<n; l++)
			a[k][l] = false;
	}
	char temp;
	int i, j;
	while(!feof(in1_1)){
		temp = fgetc(in1_1);
		if(temp == '\n'){
			i = fgetc(in1_1)-'0';
			j = fgetc(in1_1)-'0';
		}
		else{
			j = temp - '0';
		}
		a[i][j]=true;
		a[j][i]=true;
	}
	FILE* out1_1 = fopen("output1_1.txt","w");
	fprintf(out1_1, "Ma tran ke bieu dien do thi:\n\n  a b c d e f");
	for(i=0; i<n; i++){
		fprintf(out1_1,"\n\n%c",i+'a');
		for(int j=0; j<n; j++)
			if(a[i][j] == false)
				fprintf(out1_1," 0");
			else
				fprintf(out1_1," 1");
	}
	fprintf(out1_1,"\n\nDanh sach canh:\n{");
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i][j] == true){
				fprintf(out1_1,"{%c,%c}",i+'a',j+'a');
			}
		}
	}
	fprintf(out1_1,"}\n\nBac cua tung dinh:");
	for(int i=0; i<n; i++){
		fprintf(out1_1,"\n%c: ",i+'a');
		int rank = 0;
		for(int j=0; j<n; j++){
			if(a[i][j])
				rank++;
		}
		fprintf(out1_1,"%d",rank);
	}
	
	
	fclose(in1_1);
	fclose(out1_1);
}



