/*
** debug.h for DEBUG_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 12:36:13 2017 Janel
** Last update Mon May 29 16:39:25 2017 Janel
*/

#ifndef DEBUG_H_
# define DEBUG_H_

# include <errno.h>
# include <string.h>
# include <stdio.h>

# define ERROR_TAG		"[-] ERROR "
# define ADD_ERROR(STRING)	ERROR_TAG STRING
# define PRINT_ERROR(STRING)	fprintf(stderr, "%s %s\n", ADD_ERROR(STRING), strerror(errno))
# define INSIDE			fprintf(stderr, "INSIDE: %s\n", __FUNCTION__)

#endif /* !DEBUG_H_ */
