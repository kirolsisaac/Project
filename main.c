#include <stdio.h>
#include <time.h>
int main() {
    printf("                                                        KIRO MARKET                ");
    printf("\n                          __________________________________________________________________________");
    printf("\n We wanna inform you some offers before taking your order : ");
    printf("\n 1- If you ordered more than 5 items, you will get a 20 percentage Discount on the total fee.");
    printf("\n 2- A minimum of 2 items is required for one order.");
    printf("\n 3- Regular shipping for items under $10 incurs a $2 charge and for items $10 or more incurs a $3 charge.");
    printf("\n 4- Overnight delivery adds an additional $5 to the shipping cost.");
    printf("\n--------------------------------------------------------------------------------------------------------------------");
    printf("\n Enter Number of Items you want to order :");
    int n ; scanf("%d",&n);
    if(n<=1)
    {
        printf(" A minimum of 2 items is required for one order.\n");
        printf(" Renter your Number of Items :  ");
        scanf("%d",&n);
    }
    char names [n][101];
    int shiping ;
    int price[n] ;float total =0.0;
    for (int i = 1; i <=n; i++) {
        printf(  "Enter %d item name : ",i);
        scanf("%s",names[i]);
        printf(" Enter %d item price : ",i);
        scanf("%d", &price[i]);
        printf(" Need Overnight shipping ( 1 for Yes & 0 for NO ) :  ");
        fflush(stdin);
        fflush(stdout);
        scanf(" %d", &shiping);
        if (price[i] >= 10)
            price[i] += 3;
        else price[i] += 2;
        if (shiping == 1)
            price[i] += 5;

        total += price[i];
    }
    if(n>5) total-=(total*(20/100));
    printf("\n--------------------------------------------------------------------------------------------------------------------");
    printf("                              RECEIPT                    ");
    time_t now;
    struct tm *tm_info;
    char buffer[80];
    time(&now);
    tm_info = localtime(&now);
    strftime(buffer, 80, "\n     %Y-%m-%d          KIRO MARKET               %H:%M:%S", tm_info);
    printf("%s", buffer);
    printf("\n----------------------------------------------------------------------");
    printf("\n Product             Price");
    printf("\n----------------------------------------------------------------------");

    for(int i=1;i<=n;i++){
        printf("\n %d- %s            %d $ ",i,names[i],price[i]);
    }
    printf("\n----------------------------------------------------------------------");
    printf("\n TOTAL : %.02f$",total);
    return 0;
}
