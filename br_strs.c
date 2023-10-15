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

/**
 * br_strcpy - copies a string
 * @dest: the destination
 * @src: the source
 * Return: pointer to destination
 */
char *br_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * br_strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *br_strcat(char *dest, const char *src)
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
 **br_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *br_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
