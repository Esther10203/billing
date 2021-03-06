#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

struct customer{
        char customerFirstname[200];
        char customerLastname[200];
        char customercategory[200];
        int cashpower;
    };

struct currentMonth{
    char customerNames[1000];
    int cashpowernumber;
    int units;
    char date[10];
}; 

struct allTransactions{
    char customerNames[1000];
    int cashpowernumber;
    int units;
    char date[10];
};
    
int main(){
	
 printf("Hello there!\n Welcome to buy Umuriro app\b");
 printf("Chose what you want to do!\n");
 printf("1. Buy umuriro\n");
 printf("2. View Transactions\n");
 
}

void buyCurrent(){
	int payment;
    int cashpowernumber;
    int token;
    char category;
    int prev;
    int units;


    printf("input the money to start the process");
    scanf("%d",&payment);
    printf("input the cash power number");
    scanf("%d",&cashpowernumber);

    if(readcategories==NULL){
        printf("unable to open file");
    }

    // find the user to whom the cashpower number belongs to

    FILE *customers=fopen("customers.csv",'r');

    int i=0;
    int j=0;
    int k=0;

    // cs, customers
    // csm customer's montly details

    // count the number of customers
    int n=50;
    struct customer cs[n];
    struct currentmonth csm[n];

    for(i=0;i<n;i++){
        int *tok;
        char customersdata[7];
        // cs[i].customerFirstName=fgets
        tok=strtok(fgets(customersdata,sizeof(customersdata),customers),',');
        cs[i].customerFirstname=tok;
        tok=strtok(NULL,',');
        cs[i].customerLastname=tok;
        tok=strtok(NULL,',');
        cs[i].customercategory=tok;
        tok=strtok(NULL,',');
        cs[i].cashpower=tok;
        tok=strtok(NULL,',');
    }
    FILE *currentMonthData=fopen("currentmonth.csv",'r+');
    for(i=0;i<n;i++){
        int *tok;
        char customersmonthlydata[];
        // cs[i].customerFirstName=fgets
        tok=strtok(fgets(customersmonthlydata,sizeof(customersmonthlydata),currentMonthData),',');
        strcpy(csm[i].customerNames,tok);
        tok=strtok(NULL,',');
        csm[i].cashpowernumber=tok;
        tok=strtok(NULL,',');
        csm[i].units=tok;
        tok=strtok(NULL,',');
        strcpy(csm[i].cashpower,tok);
        tok=strtok(NULL,',');
    }
    i=0;
    
    while(cs[i].cashpower==cashpowernumber){
        strcpy(category,cs[i].category);
        while(cs[i].cashpower==csm[j].cashpowernumber){
            prev=csm[i].units;
            j++;
        }
        i++;
    }



    // calculate the units


    while(){

        if(category='Residential'){
            if(prev==0){
               if(payment<=1335){
                   units=payment/89;
               }
               else if(1335<payment<=7420){
                   balance1=payment-1335;
                   units=(1335/89);
                   units+=(balance1/212);
               }
               else if(payment>7420){
                   balance1=payment-(7420+1335);
                   units=(1335/89) + (7420/212);
                   units+=(balance1/249);
               }
               else{
                   printf("unable to continue");
               }
            }
            else if(prev!=0&&prev<15){
                int difference=15-prev;
                units=difference;
                int paymentfordifference=difference*89;
                int balance=payment-paymentfordifference;
                units+=(balance/212);

            }
            else if(15<prev<=50){
                int difference=35-prev;
                if(difference>=0){
                    int moneyfordifference=difference*212;
                    if(payment>moneyfordifference){
                        units=difference;
                        int balance=payment-moneyfordifference;
                        units+=(balance/249);
                }
                }
                else{
                    if(1335<money<=7420){
                        int difference=35-prev;
                        units=difference;
                        int moneyfordifference=difference*212;
                        if(payment>moneyfordifference){
                            int balance=payment-moneyfordifference;
                            units+=(balance/249);
                        }
                    }
                    else if(money>7420){
                        int difference=prev-50;
                        units=difference;
                        int moneyfordifference=difference
                    }
                }
            }
        }
        else if(strcmp(category,'Non-residential')){

            if(prev==0){
               if(payment<=22700){
                   units=payment/227;
               }
               else{
                   units=payment/255;
               }
            }
            else{
                int diff=100-prev;
                int pricefordiff=diff*227;
                if(payment<=22700){
                    units=diff;
                    int balance=payment-pricefordiff;
                    units+=(balance/255);
                }
                else{
                    if(payment>22700){
                        units=diff;
                        balance=payment-pricefordiff;
                        units+=(balance/255);
                    }
                }
            }
    }

    else if(strcmp(category,'telecom towers')){
        units=payment/201;
        return units;
    }

    else if(strcmp(category,'water treatment plants and water pumping station')){
        units=payment/126;
    }

    else if(strcmp(category,'hotels')){
        units=payment/157;
    }

    else if(strcmp(category,'health facilities')){
        units=payment/186;
    }

    else if(strcmp(category,'broadcasters')){
        units=payment/192;
    }

    else if(strcmp(category,'commercial data centers')){
        units=payment/179;
    }

    else{
        printf("uncategorized client");
    }

    return units;
}
}
}


void moveToAllTransactions(){
	//	Moving data from monthly transactions to all transactions
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
	
	
}
