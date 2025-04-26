#include<stdio.h>
#include<conio.h>
void toh(int n, char A, char B, char C) //A=Source, B=Auxiliary, C=Destination
{
    if(n==1)
    {
        printf("\nMove disk 1 from %c to %c",A,C);
        return;
    }
    toh(n-1,A,C,B);
    printf("\nMove disk %d from %c to %c",n,A,C);
    toh(n-1,B,A,C);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
    getch();
    return 0;
}