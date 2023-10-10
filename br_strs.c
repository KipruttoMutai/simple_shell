#include "shell.h"
/**
 * br_strncmp - Compare two strings up to a specified length.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Maximum number of characters to compare.
 * Return: 0 if equal
 */
int br_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char a;
	unsigned char b;

	while (n-- > 0)
	{
		a = (unsigned char) *s1++;
		b = (unsigned char) *s2++;

		if (a != b)
			return (a - b);
		if (a == '\0')
			break;
	}

	return (0);
}
