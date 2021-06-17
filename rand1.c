#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

unsigned long long rand_atleast12digit(void) 
    {
        srand(time(0));
        unsigned long long r = rand();
        #if RAND_MAX >= 999999999999
        #elif RAND_MAX >= 999999
            r *= RAND_MAX + 1ull;
            r += rand();
        #else
            r *= RAND_MAX + 1ull;
            r += rand();
            r *= RAND_MAX + 1ull;
            r += rand();
        #endif
        return r % 1000000000000;
    }

int concat(int x, int y){
    char str1[20];
    char str2[20];

    sprintf(str1,"%d",x);
    sprintf(str2,"%d",y);

    strcat(str1,str2);

    return atoi(str1);
}
int countin(int num){
    int count = 0;
    do
    {
        count++;

        num /= 10;
    } while(num != 0);

    return count;
}

int printRandoms(int lower, int upper, int count)
{
    srand(time(0));
    int i;
    for (i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        return num;
    }
}

int main()
{
   int rand = rand_atleast12digit();
   if (rand < 1)
   {
       rand *= -1;
       int append = printRandoms(2, 8, 1);
       rand = concat(rand, append);
   }
   
   int rand1 = rand_atleast12digit();
   if (rand1 < 1)
   {
       rand1 *= -1;
       int append = printRandoms(2, 8, 1);
       rand1 = concat(rand1, append);
       printf("%d", rand1);

   }
   
   int answer = concat(rand, rand1);

//    if(answer < 0){
//         answer *= -1;
//    }


   int count = countin(answer);
//    printf("%d", );
       printf("%d", rand1);


   return 0;
}