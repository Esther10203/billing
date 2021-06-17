#include<stdio.h>
#include<dos.h>
#include<conio.h>
int main()
{
   struct date dt;
 
   printf("Enter new date in the format(day month year)");
   scanf("%d%d%d",&dt.da_day,&dt.da_mon,&dt.da_year);
 
   setdate(&dt);
 
   printf("Now, current system date is %d-%d-%d\n"
   ,dt.da_day,dt.da_mon,dt.da_year);
 
   return 0;
}
