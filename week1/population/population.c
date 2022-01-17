#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("What is the start size? ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("What is the end size? ");
    }
    while (end_size < start_size);

    // TODO: Calculate number of years until we reach threshold
    float temp_size = start_size;
    int n;
    for (n = 0; temp_size <= end_size; n++)
    {
        temp_size = (1+1.0/3-1.0/4) * temp_size;
        // printf("%f\n", temp_size);
    }

    // TODO: Print number of years
    printf("Years: %i\n", n - 1);
}