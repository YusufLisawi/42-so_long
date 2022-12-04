/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelaissa <yelaissa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:52:04 by yelaissa          #+#    #+#             */
/*   Updated: 2022/10/19 10:16:08 by yelaissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// format specification
int	formatspecs(va_list ap, char format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size = ft_putchar(va_arg(ap, int));
	else if (format == 's')
		size = ft_putstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		size = ft_put_itoa(va_arg(ap, int));
	else if (format == 'u')
		size = ft_put_uitoa(va_arg(ap, int));
	else if (format == 'x' || format == 'X')
		size = ft_put_hexa(va_arg(ap, int), format);
	else if (format == 'p')
		size += ft_put_pointer(va_arg(ap, unsigned long long int));
	return (size);
}

int	ft_printf(const char *s, ...)
{
	size_t	printed;
	va_list	ap;
	int		i;

	i = 0;
	printed = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (!s[i])
				break ;
			if (s[i] == '%' && s[i])
				printed += ft_putchar('%');
			printed += formatspecs(ap, s[i]);
		}
		else
			printed += ft_putchar(s[i]);
		i++;
	}
	va_end(ap);
	return (printed);
}

/* int main(void)
{
	int a = 0;
	int b = 0;
	a += printf("%c \n", 'a');
	a += printf("%s \n", "abc");
	a += printf("%p \n", &a);
	a += printf("%d %i \n", 42, 42);
	a += printf("%u \n", 42);
	a += printf("%x %X \n", 42, 42);
	a += printf("%% \n");
	ft_printf("######################dyalom^\n");
	b += ft_printf("%c \n", 'a');
	b += ft_printf("%s \n", "abc");
	b += ft_printf("%p \n", &a);
	b += ft_printf("%d %i \n", 42, 42);
	b += ft_printf("%u \n", 42);
	b += ft_printf("%x %X \n", 42, 42);
	b += ft_printf("%% \n");

	ft_printf("\nLength : \n%d\n%d\n", a, b);

	return 0;
} */