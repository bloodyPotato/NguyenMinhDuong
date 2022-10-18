#include<stdio.h>

int main(){
	FILE* in1 = fopen("input1.txt","r");
	if(in1==NULL){
		printf("error");
		return -1;
	}
	int n = fgetc(in1) - (int)'0';
	bool a[n][n];
	char temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp = fgetc(in1);
			if(temp == '1')
				a[i][j] = true;
			else
				a[i][j] = false;
		}
	}
	FILE* in1_1 = fopen("input1_1.txt","w");
	if(in1_1==NULL){
		printf("error");
		return -1;
	}
	fputc(n+'0',in1_1);
	for(int i=0; i<n; i++){
		fprintf(in1_1,"\n%d",i);
		for(int j=0; j<n; j++){
			if(a[i][j])
				fprintf(in1_1,"%d",j);
		}
	}
	FILE* in1_2 = fopen("input1_2.txt","w");
	if(in1_2==NULL){
		printf("error");
		return -1;
	}
	fprintf(in1_2,"%d",n);
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i][j])
				fprintf(in1_2," %d %d",i,j);
		}
	}
	fclose(in1);
	fclose(in1_1);
	fclose(in1_2);
} 
