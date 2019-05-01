#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: crack <hash>\n");
        return 1;
    }

    // 26 lowercase + 26 uppercase + \0 counts as 1 character = 53
    const int letters_count = 53;

    string letters = "\0abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string hash = argv[1];

    char salt[3];
    memcpy(salt, hash, 2);
    salt[2] = '\0';

    char key_letters[6] = "\0\0\0\0\0\0";


    for (int fifth = 0; fifth < letters_count; fifth++)
    {
        for (int fourth = 0; fourth < letters_count; fourth++)
        {
            for (int third = 0; third < letters_count; third++)
            {
                for (int second = 0; second < letters_count; second++)
                {

                    for (int first = 1; first < letters_count; first++)
                    {
                        key_letters[0] = letters[first];  // 1)
                        key_letters[1] = letters[second]; // 2)
                        key_letters[2] = letters[third];  // 3)
                        key_letters[3] = letters[fourth]; // 4)
                        key_letters[4] = letters[fifth];  // 5)


                        if (strcmp(crypt(key_letters, salt), hash) == 0)
                        {
                            printf("%s\n", key_letters);
                            return 0;
                        }
                    }
               }
            }
        }
    }

    printf("Password couldn't be cracked!");


    // check if it wrong
    return 2;
}
