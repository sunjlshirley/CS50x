#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_num_digits(long n);
int get_sum(long n);

int main(void)
{
    long number = get_long("Number: ");
    int num_digits = get_num_digits(number);
    int sum = get_sum(number);

    long POW12 = 1000000000000;
    long POW13 = 10000000000000;
    long POW14 = 100000000000000;
    long POW15 = 1000000000000000;

    char isValid = 0;
    if (sum % 10 != 0) {
        printf("INVALID");
        return 0;
    }

    if (num_digits == 15) {
        long first_two_digits = number / POW13;
        if (first_two_digits == 34 || first_two_digits == 37) {
                printf("AMEX");
                isValid = 1;
        }
    } else if (num_digits == 13) {
        int first_digit = number / POW12;
        if (first_digit == 4) {
            printf("VISA");
            isValid = 1;
        }
    } else if (num_digits == 16) {
        int first_digit = number / POW15;
        int first_two_digits = number / POW14;
        if (first_digit == 4) {
            printf("VISA");
            isValid = 1;
        } else if (first_two_digits >= 51 && first_two_digits <= 55) {
            printf("MASTERCARD");
            isValid = 1;
        }
    }

    if (isValid != 1) {
        printf("INVALID");
    }

    // if ((num_digits == 15) && ((number/POW13 == 34) || (number/POW13 == 37)) && (sum % 10 == 0))
    // {
    //     printf("AMEX");
    // }
    // else if (((num_digits == 13)&&(number/POW12 == 4)) (num_digits == 16)) && (number/ == 4) && (sum % 10 == 0))
    // {
    //     printf("VISA");
    // }
    // else if ((num_digits == 16) && ((number/pow(10,14) == 51) || (number/pow(10,14) == 52) || (number/pow(10,14) == 53) || (number/pow(10,14) == 54) || (number/pow(10,14) == 55)) && (sum % 10 == 0))
    // {
    //     printf("MASTERCARD");
    // }
    // else
    // {
    //     printf("INVALID");
    // }
}

int get_num_digits(long n)
{
    int i = 0;

    while (n > 0) {
        n = n/10;
        i = i + 1;
    }
    return i;
}

int get_sum(long n)
{
    int i;
    int digit;
    int sum = 0;
    for (i = 1; n>0; i++)
    {
        digit = n % 10;
        n = n / 10;

        if (i % 2 != 0)
        {
            sum += digit;
        }
        else
        {
            sum += (digit * 2) % 10 + (digit * 2) / 10;
        }
    }
    return sum;
}
