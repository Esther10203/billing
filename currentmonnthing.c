#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Client{
        int clientId;
        int cashpowernumber;
        int units;
        float payment;
        char *date;
    }client;

void deletefile(){

//gets_s(filename, 80);

 

// check any error...
char filename[]= "currentMonth.csv";
if(remove(filename) == 0)

printf("File %s has been deleted.\n", filename);

else

fprintf(stderr, "Error deleting file %s.\n", filename);

}
void create(char *filename){
	client *c;
	printf("\n Creating %s.csv file\n", filename);
	FILE *fp;
	int i, j;
	c = (client*)calloc(1,sizeof(client));
	filename= strcat(filename,".csv");
	fp=fopen(filename, "w+");
	fprintf(fp,"Client's Id', CashPower, Units, Date and time");
	printf("Client's Id: ");
	scanf("%d", &(*c).clientId);
	fflush(stdin);
	printf("\nCashpower Number: ");
	scanf("%d", &(*c).cashpowernumber);
	
	printf("\nUnits: ");
	scanf("%d", &(*c).units);
	
	time_t tm;
	time(&tm);
	(*c).date= ctime(&tm);
		fprintf(fp, "%d, %d, %d, %s", (*c).clientId, (*c).cashpowernumber, (*c).units, (*c).date);
	fclose(fp);
	printf("\n %s file created", filename);
}
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
        printf("Row: %s", row[0]);	
    }
	}
	fclose(fp);
}
void append(char *filename){
	client *c;
	FILE *fp;
	c = (client*)calloc(1,sizeof(client));
	printf("\n Opening %s.csv file\n", filename);
	filename= strcat(filename,".csv");
	fp = fopen(filename, "a");
	if(fp==NULL){
    	printf("Can't open this file ");
	}else{
			printf("Client's Id: ");
		scanf("%d", &(*c).clientId);
//		fflush(stdin);
		printf("\nCashpower Number: ");
		scanf("%d", &(*c).cashpowernumber);
//		
		printf("\nUnits: ");
		scanf("%d", &(*c).units);
//		
		time_t tm;
		time(&tm);
		(*c).date= ctime(&tm);
		fprintf(fp, "%d, %d, %d, %s", (*c).clientId, (*c).cashpowernumber, (*c).units, (*c).date);
//		fwrite(&c,sizeof(client),1,fp);
		printf("\nNew record added!");
//		printf("Opened");
    }
	fclose(fp);
}
void search(char *filename){
	client c;
	FILE *fp;
	int clientId, found=0;
	printf("\n Opening %s.csv file\n", filename);
	filename= strcat(filename,".csv");
	fp = fopen(filename, "r");
	printf("Enter Client to search:");
	scanf("%d", &clientId);
	while(fread(&c, sizeof(client), 1, fp))
	{
		if(c.clientId==clientId){
			found=1;
			printf("\n%d %d", c.clientId, c.cashpowernumber);
//			for(j=0; j<3; j++){
			printf("%d", c.units);
//			}
		}	
//		printf("%5d%7.2f", s1.total, s1.per);
	}
	if(!found){
		printf("\nRecord Not Found!\n");
	}
	fclose(fp);
}
int main(){
//	char *date;`
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
  
// declare an array to store file name...

 
if(tm.tm_mday== 1){
	deletefile();
}
	char str[100];
	printf("\n Enter the filename: ");
	gets(str);
	
int ch;
	
	do{
		printf("\n1.CREATE");
		printf("\n2.DISPLAY");
		printf("\n3.APPEND");
		printf("\n4.SEARCH");
		printf("\n6.UPDATE");
		printf("\n0.EXIT");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
		case 1:
			create(str);
		break;
		case 2:
			display(str);
		break;
		case 3:
			append(str);
		break;
		case 4:
			search(str);
		break;
//		case 6:
//			update();
//		break;
	}
	}while(ch!=0);
	
	

	
	return 0;
}
