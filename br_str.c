#include "shell.h"
/**
 * br_strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */
int br_strlen(const char *s)
{
        int i = 0;

        if (!s)
                return (0);

        while (*s++)
                i++;
        return (i);
}