/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:19:39 by disantam          #+#    #+#             */
/*   Updated: 2023/11/09 10:38:18 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_dec(long n, char f);
int	ft_hex(size_t ptr, char f);

#endif
