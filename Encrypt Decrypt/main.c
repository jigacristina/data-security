#include <stdio.h>
#include <stdlib.h>

int main()
{
    char message[100], ch;
    int i, key;
    char choice;
    printf("\nPlease, enter a message: ");
    gets(message);
    printf("\nPlease choose following options:\n");
    printf("E = Encrypt the string.\n");
    printf("D = Decrypt the string.\n");
    scanf("%c", &choice);

    switch(choice){

    case 'E':
        printf("Enter key: ");
        scanf("%d", &key);

        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch + key;
                if(ch > 'z'){
                    ch = ch - 'z' + 'a' - 1;
                }
                message[i] = ch;
            }

            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch + key;
                if(ch > 'Z'){
                    ch = ch - 'Z' + 'A' - 1;
                }
                message[i] = ch;
            }
        }

    printf("Encrypted message: %s", message);
    break;

    case 'D':
        printf("Enter key: ");
        scanf("%d", &key);

        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];

            if(ch >= 'a' && ch <= 'z'){
                ch = ch - key;
                if(ch < 'a'){
                    ch = ch + 'z' - 'a' + 1;
                }
                message[i] = ch;
            }

            else if(ch >= 'A' && ch <= 'Z'){
                ch = ch - key;
                if(ch < 'A'){
                    ch = ch + 'Z' - 'A' + 1;
                }
                message[i] = ch;
            }
        }

        printf("Decrypted message: %s", message);
        break;

    default:
        printf("Error! ");
}
return 0;
}
