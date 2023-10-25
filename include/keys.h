/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 07:10:03 by acaceres          #+#    #+#             */
/*   Updated: 2023/10/25 10:56:15 by acaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# if __APPLE__ == 1
#  define ESCAPE 53

#  define ARROW_UP 126
#  define ARROW_DOWN 125
#  define ARROW_RIGHT 124
#  define ARROW_LEFT 123

#  define PLUS 24
#  define MINUS 27

#  define KEY_K 40
#  define KEY_J 38
#  define KEY_L 37
#  define KEY_H 4

#  define KEY_R 15

#  define KEY_W 13
#  define KEY_S 1

#  define KEY_F 3

#  define KEY_C 8

#  define KEY_V 9

#  define KEY_P 35

#  define MOUSE_UP 5
#  define MOUSE_DOWN 4
# else
#  define ESCAPE 65307

#  define ARROW_UP 65362
#  define ARROW_DOWN 65364
#  define ARROW_RIGHT 65363
#  define ARROW_LEFT 65361

#  define PLUS 61
#  define MINUS 45

#  define KEY_K 107
#  define KEY_J 106
#  define KEY_L 108
#  define KEY_H 104

#  define KEY_R 114

#  define KEY_W 119
#  define KEY_S 115

#  define MOUSE_UP 4
#  define MOUSE_DOWN 5
# endif
#endif
