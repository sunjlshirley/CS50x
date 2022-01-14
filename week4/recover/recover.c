#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

const int block_size = 512;
typedef uint8_t BYTE;

bool jpeg_start(BYTE image[block_size]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("could not open file.\n");
        return 2;
    }

    BYTE block[block_size];
    int i = -1;
    FILE* fp = NULL;

    while (fread(block, sizeof(BYTE), block_size, file))
    {
        if (jpeg_start(block))
        {
            
            i += 1;
            if (i != 0)
            {
                fclose(fp);
            }

            char filename[8];
            sprintf(filename, "%03d.jpg", i);
            fp = fopen(filename, "w");
        }
        if (fp != NULL) 
        {
            fwrite(block, sizeof(BYTE), block_size, fp);
        }
    }

    fclose(file);
    fclose(fp);
}

bool jpeg_start(BYTE image[block_size])
{
    if (image[0] == 0xff && image[1] == 0xd8 && image[2] == 0xff && (image[3] >= 0xe0 && image[3] <= 0xef))
    {
        return true;
    }
    return false;
}