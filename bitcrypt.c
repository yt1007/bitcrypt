/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitcrypt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:52:53 by yetay             #+#    #+#             */
/*   Updated: 2023/08/31 16:52:53 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	isbinary(char *s);
int b2a(char *s);
int a2b(char *s);

/* Program encrypts/decrypts given string between binary bits */
/* and ascii bytes */
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("bitcrypt: no input.\n");
		return (1);
	}
	if (isbinary(argv[1]))
		return(b2a(argv[1]));
	else
		return(a2b(argv[1]));
}

/* Function returns 1 if all characters in the given string */
/* are '0', '1', or ' '; otherwise, returns 0 */
int	isbinary(char *s)
{
	while (*s)
	{
		if (*s == '0')
		{
			s++;
			continue ;
		}
		if (*s == '1')
		{
			s++;
			continue ;
		}
		if (*s == ' ')
		{
			s++;
			continue ;
		}
		return (0);
	}
	return (1);
}

/* Function converts consecutive '0's and '1's into a decimal */
/* integer, and prints it as an unsigned char */
int	b2a(char *s)
{
	unsigned char	c;

	while (*s)
	{
		while(*s == ' ')
			s++;
		c = 0;
		while(*s == '0' || *s == '1')
		{
			c = (c * 2) + *s;
			s++;
		}
		printf("%c", c);
	}
	printf("\n");
	return (0);
}

/* Function converts each ascii byte (unsigned char) to 8 */
/* binary bits and prints them to the screen. */
/* Each character is separated by a space. */
int	a2b(char *s)
{
	unsigned int	i;
	unsigned char	c;

	while (*s)
	{
		i = 8;
		while (--i >= 0)
		{
			c = *s;
			printf("%c", ((c >> i) & 1) + '0');
		}
		printf(" ");
	}
	printf("\n");
	return (0);
}
