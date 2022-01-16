#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int isvalid(string key);

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (isvalid(argv[1]) == 0) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else {
        string text = get_string("plaintext: ");
        string key = argv[1];

        for(int i = 0; key[i]; i++) key[i] = tolower(key[i]);

        // string key = tolower(argv[1]);
        int leng = strlen(text);
        // char cipher[leng];
        string cipher = text;
        // cipher[leng-1] = '\0';

        for (int i = 0; i < leng; i++) {
            char text_i = text[i];
            if (isalpha(text_i)) {
                if (islower(text_i)) {
                cipher[i] = key[text_i - 'a'];
                }
                else {
                cipher[i] = toupper(key[text_i - 'A']);
                }
            }
            else {
                cipher[i] = text_i;
            }
        }
        printf("ciphertext: %s\n", cipher);
    }
}

int isvalid(string key)
{
    // less than 26 chars
    if (strlen(key) != 26) {
        return 0;
    }
    else {
        int freq[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        for (int i = 0; key[i] != '\0'; i++) {
            if (isalpha(key[i])) {
                freq[tolower(key[i])-'a'] += 1;
                // letter appears more than once
                if (freq[tolower(key[i])-'a'] > 1) {
                    return 0;
                }
                else {
                   continue;
                }
            }
            else {
                // non-alphabetic char
                return 0;
            }
        }
    }
    return 1;
}