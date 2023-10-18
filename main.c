/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:58:05 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/18 16:08:59 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __linux__
	#define MY_OS "Working in Linux..."
#elif __APPLE__
	#define MY_OS "Working in Mac..."
#endif

#include <stdio.h>

int	main()
{
	char	*s = MY_OS;
	printf("%s\n", s);
}
