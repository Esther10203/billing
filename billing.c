#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct customer{
        char customerFirstname[200];
        char customerLastname[200];
        char customercategory[200];
        char cashpower[15];
    };

    struct currentMonth{
        char customerNames[1000];
        char cashpowernumber[15];
        char units[100];
        // char *date;
    }; 

    struct allTransactions{
        char customerNames[1000];
        char cashpowernumber[15];
        char units[100];
        // char *date;
    };


int main(){
    int payment;
    char cashpowernumber[15];
    int token;
    // char *category;
    char category[100];
    int prev;
    int units;


    printf("input the money to start the process: ");
    scanf("%d",&payment);
    printf("input the cash power number: ");
    scanf("%s",&cashpowernumber);

    // find the user to whom the cashpower number belongs to

    FILE *customers=fopen("customers.csv","r");
    if(customers==NULL){
        printf("unable to open file");
    }
    FILE *currentMonthData=fopen("currentmonth.csv","r+");
    if(currentMonthData==NULL){
        printf("unable to open current month file");
    }
    int i=0;
    int j=0;
    int k=0;

    // cs, customers
    // csm customer's montly details

    // count the number of customers

    int n=50;
    struct customer cs[n];
    struct currentMonth csm[n];

    // for(i=0;i<n;i++){
        
    //     // tok=fscanf(customers,customersdata->customerFirstname,customersdata->customerLastname,customersdata->customercategory,customersdata->cashpower);
    //     // cs[i].customerFirstName=fgets
        
    //     tok=strtok(fgets(customersdata,sizeof(customersdata),customers),",");
    //     printf("%s", tok);
    //     // tok=
    // }
        char *tok;
        char customersdata[1000];
        int field;
        int z = 0;
    while(fgets(customersdata,sizeof(customersdata),customers) != NULL){
            tok = strtok(customersdata, ",");
            field = 0;
            while(tok != NULL){
                if(field == 0){
                    strcpy(cs[z].customerFirstname,tok);
                    tok=strtok(NULL,",");
                    // printf("%s\n", tok);
                }
                else if(field == 1){
                    strcpy(cs[z].customerLastname,tok);
                    tok=strtok(NULL,",");
                    // printf("%s\n", tok);
                }
                else if(field == 2){
                    strcpy(cs[z].customercategory,tok);
                    tok=strtok(NULL,",");
                    // printf("%s\n", tok);
                }
                else{
                    strcpy(cs[z].cashpower,tok);
                    tok=strtok(NULL,",");
                    // printf("%s\n", tok);
                }
                field++;
            }
            z++;
    }
    // printf("woeoe");
    // for(i=0;i<n;i++){
        // char *tok;
        char customersmonthlydata[1000];
        // cs[i].customerFirstName=fgets
        i=0;
        while(fgets(customersmonthlydata,1000,currentMonthData)!=NULL){
            int field=0;
            tok=strtok(customersmonthlydata,",");
           
            while(tok!=NULL){
                if(field == 0){
                    strcpy(csm[i].customerNames,tok);
                }
                else if(field == 1){
                    strcpy(csm[i].cashpowernumber,tok);
                }
                else{
                    strcpy(csm[i].units,tok);
                }
                tok = strtok(NULL, ",");
                field++;
            }
            printf("%s %s %s \n", csm[i].customerNames, csm[i].cashpowernumber, csm[i].units);
            i++;
        }
        
        
       
    // }
    i=0;
    // while(cashpowernumber!=NULL){
        if(strcmp(cs[i].cashpower,cashpowernumber) == 0){
            strcpy(category,cs[i].customercategory);
            printf("%s",category);
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(strcmp(cs[i].cashpower,csm[j].cashpowernumber)){
                    // prev=strtol(csm[i].units,NULL,10);
                    // printf("%s",strtol(csm[i].units,NULL,10));
                    // printf("%s",csm[i].units);
                }
                }
                
                // j++;
            }
            // i++;
        }
        else{
            printf("invalid meter number");
        }
    // }
    
            // printf("%d",prev);

    // calculate the units


    

        if(strcmp(category,"Residential")){
            if(prev==0){
               if(payment<=1335){
                   units=payment/89;
               }
               else if(1335<payment<=7420){
                   int balance1=payment-1335;
                   units=(1335/89);
                   units+=(balance1/212);
               }
               else if(payment>7420){
                   int balance1=payment-(7420+1335);
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
                    if(1335<payment<=7420){
                        int difference=35-prev;
                        units=difference;
                        int moneyfordifference=difference*212;
                        if(payment>moneyfordifference){
                            int balance=payment-moneyfordifference;
                            units+=(balance/249);
                        }
                    }
                    else if(payment>7420){
                        int difference=prev-50;
                        units=difference;
                        int moneyfordifference=difference;
                    }
                }
            }
        }
        else if(strcmp(category,"Non-residential")){

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
                        int balance=payment-pricefordiff;
                        units+=(balance/255);
                    }
                }
            }
    }

    else if(strcmp(category,"telecom towers")){
        units=payment/201;
        return units;
    }

    else if(strcmp(category,"water treatment plants and water pumping station")){
        units=payment/126;
    }

    else if(strcmp(category,"hotels")){
        units=payment/157;
    }

    else if(strcmp(category,"health facilities")){
        units=payment/186;
    }

    else if(strcmp(category,"broadcasters")){
        units=payment/192;
    }

    else if(strcmp(category,"commercial data centers")){
        units=payment/179;
    }

    else{
        printf("uncategorized client");
    }
    printf("units: %d",units);
    return units;
    }
