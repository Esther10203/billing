#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

typedef struct montlyTransaction{
	char customerNames[1000];
    int cashpowernumber;
    int units;
    char date[10];
}montlyTransaction;

typedef struct allTransactions{
    char customerNames[1000];
    int cashpowernumber;
    int units;
    char date[10];
}allTransactions;
    
int main(){
	
	FILE *file1 = fopen("allTransactions.csv", "w");
	FILE *file2 = fopen("monthlyTransactions.csv", "r");
	
	if(file1 == NULL){
		printf("Unable to open allTransactions file");
		exit(1);
	}
	
	if(file2 == NULL){
		printf("Unable to open monthly transaction file");
		exit(1);
	}
	
	char line[2000];
	
	while(fgets(line, sizeof(line), file1)){
		char *token;
		token = strtok(line, ",");
		
		while(token!=NULL){
			printf("%s", token);
			token = $strtok(NULL, ",");
		}
		printf("\n");
	}
	
	
//	int j;
//	
//	allTransactions *all;
//	montlyTransaction *month;
//	
//	FILE *file1;
//	FILE *file2;
//	
//	file1 = fopen("allTransactions.csv", "a");
//	file2 = fopen("monthTransactions.csv", "r");
//	
//	while(fread(&month, sizeof(montlyTransaction), 1, file2))
//	{
//		for(j=0; j<4; j++){
//			month[j].cashpowernumber = all[j].cashpowernumber;
//			month[j].customerNames = all[j].customerNames;
//			month[j].date = all[j].date;
//			month[j].units = all[j].units;
//		}
//		
//		fwrite(&file1, sizeof(all), 1, file1);
//	}
//	fclose(file2);
//	fclose(file1);
}
