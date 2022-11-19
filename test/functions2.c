#include "main.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
        int length = 0;
        char *ret;

        if (str == NULL)
                return (NULL);
        while (*str++)
                length++;
        ret = malloc(sizeof(char) * (length + 1));
        if (!ret)
	 return (NULL);
        for (length++; length--;)
                ret[length] = *--str;
        return (ret);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
        char *ret = dest;
	while (*dest)
                dest++;
        while (*src)
                *dest++ = *src++;
        *dest = *src;
        return (ret);
}

/**
 * _strstr - locate a substring
 * @haystack: string
 * @needle: string substring
 * Return: Pointer to beginning of substring, or NULL if not found.
 */
char *_strstr(char *haystack, char *needle)
{
        int i, j, c;

        i = 0;
        c = 0;
        while (haystack[i] != '\0')
        {
                j = 0;
                while (needle[j + c] != '\0' && haystack[i + c] != '\0'
                       && needle[j + c] == haystack[i + c])
                {
                        if (haystack[i + c] != needle[j + c])
                                break;
                        c++;
                }
                if (needle[j + c] == '\0')
			 return (&haystack[i]);
                j++;
                i++;
        }

        return (NULL);
}

