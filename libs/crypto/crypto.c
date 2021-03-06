#include "crypto.h"

char * encrypt(char * text, int key)
{
    int i;
    char encryptedText[STRING_MAX_LENGTH];
    char *s_ptr = encryptedText;

    strcpy(encryptedText, text);

    for (i = 0; text[i] != '\0'; i++ )
    {
        encryptedText[i] = shiftCharacter(text[i], key);
    }

    return s_ptr;
}

char * decrypt(char * text, int key)
{
    char decryptedText[STRING_MAX_LENGTH];
    char *s_ptr = decryptedText;

    strcpy(decryptedText, encrypt(text, -1 * key));

    return s_ptr;
}

void setAlphabetCase(char ch, char *first_ch, char *last_ch)
{
    if (isalpha(ch))
    {
        if (isupper(ch))
        { 
            *first_ch = FIRST_LETTER_UPPER;
            *last_ch = LAST_LETTER_UPPER;
        }

        else
        {
            *first_ch = FIRST_LETTER_LOWER;
            *last_ch = LAST_LETTER_LOWER;
        }
    }

    else
    {
        *first_ch = '\0';
        *last_ch = '\0';
    }
}

int mod(int a, int b)
{
    int result = a % b;

    while (result < 0)
    {
        result += b;
    }

    return result;
}

char shiftCharacter(char ch, int offset)
{
    char first_ch, last_ch;
    int dist_ch, dist_total, new_ch_pos;

    if (!isalpha(ch))   return ch; 
    if (offset == 0)    return ch;

    setAlphabetCase(ch, &first_ch, &last_ch);
   
    dist_ch = ch - first_ch;
    dist_total = last_ch - first_ch;
    new_ch_pos = mod(dist_ch + offset, dist_total+1);

    return  first_ch + new_ch_pos;
}