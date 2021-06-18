#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display(char *filename){
	char row[50];
	FILE *fp;
//	int j;
	printf("\n Opening %s.csv file\n", filename);
	filename= strcat(filename,".csv");
	fp = fopen(filename, "r");
	 if(fp==NULL){
    	printf("Can't open this file ");
	}else{
		while(fgets(row, 50, fp)){
        printf("Row: %s", row);
    }
	}
	fclose(fp);
}
int main(){
    char *date;
	char str[100];
	printf("\n Enter the filename: ");
	gets(str);

    display(str);
}
