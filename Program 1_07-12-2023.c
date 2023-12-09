#include<stdio.h>
void main()
{
    int option, ids[100], acnos[100], pins[100], bals[100];
    int c_ids=0, c_acnos=0, c_pins=0, c_bals=0,t=0;
    while (t==0)
    {
        printf("\nEnter 1 to create an account\n");
        printf("Enter 2 to withdraw an amount\n");
        printf("Enter 3 to deposit an amount\n");
        printf("Enter 4 for balance inquiry\n");
        printf("Enter 0 to exit\n");
        printf("\nEnter an option:\n");
        scanf("%d",&option);
        switch (option)
        {
            case 0: printf("\nExiting...\n");t=1;break;
            case 1: create(ids,bals,pins,acnos,c_ids,c_bals,c_pins,c_acnos);c_ids+=1;c_bals+=1;c_pins+=1;c_acnos+=1;break;
            case 2: withdraw(acnos,pins,bals,c_acnos);break;
            case 3: deposit(acnos,bals,c_acnos);break;
            case 4: inquiry(acnos,bals,c_acnos);break;
        }
    }
}
void create(int Id[],int Amt[],int Pin[],int Acno[],int c1,int c2,int c3,int c4)
{
    int id_no,amt1,pin1;
    printf("Enter the id number of the applicant:\n");
    scanf("%d",&id_no);
    Id[c1]=id_no;
    Acno[c4]=id_no+2023;
    printf("Enter the initial amount to deposit:\n");
    scanf("%d",&amt1);
    Amt[c2]=amt1;
    printf("Enter a pin number:\n");
    scanf("%d",&pin1);
    Pin[c3]=pin1;
    printf("\nAccount details recorded successfully\n");
    printf("Your Account number is %d\n\n",Acno[c4]);
}
void withdraw(int Acno[],int Pin1[],int Amt[],int c1)
{
    int amount,pin,acc_no,i,flag=0;
    printf("Enter the account number:\n");
    scanf("%d",&acc_no);
    printf("Enter the amount to withdraw:\n");
    scanf("%d",&amount);
    printf("Enter your pin number:\n");
    scanf("%d",&pin);
    for(i=0;i<=c1;i++)
    {
        if (Acno[i]==acc_no && Pin1[i==pin])
        {
            Amt[i]=Amt[i]-amount;
            printf("Please collect your cash\n");
            flag=1;
            break;
        }
        else
            continue;
    }
    if (flag==0)
        printf("Account does not exist or wrong details entered\n");
}
void deposit(int Acno[],int Amt[],int c1)
{
    int amount,acc_no,i,flag=0;
    printf("Enter the account number:\n");
    scanf("%d",&acc_no);
    printf("Enter the amount to deposit:\n");
    scanf("%d",&amount);
    for(i=0;i<=c1;i++)
    {
        if (Acno[i]==acc_no)
        {
            Amt[i]=Amt[i]+amount;
            printf("Deposited successfully\n");
            flag=1;
            break;
        }
        else
            continue;
    }
    if (flag==0)
        printf("Account does not exist or wrong details entered\n");
}
void inquiry(int Acno[],int Amt[],int c1)
{
    int acc_no,balance,i,flag=0;
    printf("Enter the account number:\n");
    scanf("%d",&acc_no);
    for(i=0;i<=c1;i++)
    {
        if (Acno[i]==acc_no)
        {
            balance=Amt[i];
            printf("The balance is %d\n",balance);
            flag=1;
            break;
        }
        else
            continue;
    }
    if (flag==0)
        printf("Account does not exist or wrong details entered\n");
}
