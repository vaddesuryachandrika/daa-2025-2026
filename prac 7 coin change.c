#include<stdio.h>
int main()
{
    int a[10],n,amt,i,j;

    printf("Enter number of coins: ");
    scanf("%d",&n);

    printf("Enter coin values:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter amount: ");
    scanf("%d",&amt);

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }

    printf("Coins used:\n");
    for(i=n-1;i>=0;i--)
        while(amt>=a[i])
        {
            printf("%d ",a[i]);
            amt=amt-a[i];
        }

    return 0;
}