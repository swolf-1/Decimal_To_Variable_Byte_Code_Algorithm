#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long DecimalToBinary(int decimalnum);
void One_ByteNumber_Cal(int Decimal_Number);
void Two_ByteNumber_Cal(int Decimal_Number);
void Three_ByteNumber_Cal(int decimalnum);
void Four_ByteNumber_Cal(int decimalnum);

int main()
{
    int number;
    long BinaryNumber,Byte_1,Byte_2,Byte_3,Byte_4;

    printf("Give a number: ");

    do
    {
    scanf("%d",&number);
    if(number <= 0)
        printf("Number must be >0.Try again...\n");
    }while(number <= 0);

    printf("The VB code of the number %d is:",number);

    if(number < pow(2,7))
        One_ByteNumber_Cal(number);
    else if(number < pow(2,14))
        Two_ByteNumber_Cal(number);
    else if(number < pow(2,21))
        Three_Byte_Cal(number);
    else
        Four_ByteNumber_Cal(number);

    return 0;
}

 long DecimalToBinary(int decimalnum)
{
    long binarynum = 0;
    int rem,temp = 1;

    while(decimalnum != 0)
    {
        rem = decimalnum % 2;
        decimalnum /= 2;
        binarynum += rem*temp;
        temp *= 10;
    }
    return binarynum;
}

void One_ByteNumber_Cal(int Decimal_Number)
{
    long Binary_Number,Byte_1;

    Binary_Number = DecimalToBinary(Decimal_Number);

    Byte_1 = Binary_Number % 10000000 + 10000000;
    printf("\n%ld",Byte_1);

}

void Two_ByteNumber_Cal(int Decimal_Number)
{
    long Binary_Number,Byte_1,Byte_2;

    Binary_Number = DecimalToBinary(Decimal_Number);

    Byte_1 = Binary_Number % 10000000 + 10000000;
    Byte_2 = Binary_Number / 10000000;

    printf("\n%.8ld",Byte_2);
    printf("\n%ld",Byte_1);
}

void Three_Byte_Cal(int decimalnum)
{
    long Byte_1=0,Byte_2=0,Byte_3=0;
    int rem,temp = 1,counter=0;

    while(decimalnum != 0)
    {
        rem = decimalnum % 2;
        decimalnum /= 2;
        counter++;

        if(counter < 8)
            Byte_1 += rem*temp;
        else if(counter < 15)
            Byte_2 +=rem*temp;
        else
            Byte_3 +=rem*temp;

        temp *= 10;

        if(counter == 7 || counter == 14)
            temp=1;

    }

    Byte_1 += 10000000;

    printf("\n%.8ld",Byte_3);
    printf("\n%.8ld",Byte_2);
    printf("\n%ld",Byte_1);
}

void Four_ByteNumber_Cal(int decimalnum)
{
    long Byte_1 = 0,Byte_2 = 0,Byte_3 = 0,Byte_4 = 0;
    int rem,temp = 1, counter = 0;

    while(decimalnum != 0)
    {
        rem = decimalnum % 2;
        decimalnum /= 2;
        counter++;

        if(counter < 8)
            Byte_1 += rem*temp;
        else if(counter < 15)
            Byte_2 +=rem*temp;
        else if(counter < 22)
            Byte_3 +=rem*temp;
        else
            Byte_4 +=rem*temp;

        temp *= 10;

        if(counter == 7 || counter == 14 || counter == 21)
            temp=1;

    }

    Byte_1 += 10000000;

    printf("\n%.8ld",Byte_4);
    printf("\n%.8ld",Byte_3);
    printf("\n%.8ld",Byte_2);
    printf("\n%ld",Byte_1);
}
