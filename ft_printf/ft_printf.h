/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niespana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:24:08 by niespana          #+#    #+#             */
/*   Updated: 2022/04/09 13:24:09 by niespana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *p, ...);
int	ft_print_hex(unsigned int s, int cas);
int	*ft_putnbr_base(unsigned long s, char *base, int *res);
int	pf_putnbr_fd(long n, int fd, int unsign, int *res);
int	pf_putstr_fd(char *s, int fd);
int	pf_putchar_fd(char c, int fd, int *res);
int	ft_print_ptr(void *s);

#endif
