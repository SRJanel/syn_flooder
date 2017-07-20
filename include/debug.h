/*
** debug.h for DEBUG_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 12:36:13 2017 Janel
** Last update Tue Jul 11 11:27:11 2017 Janel
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
# define PRINT_IP_ADDRESS(X)    fprintf(stdout, "|IP address: %02d.%02d.%02d.%02d\n", \
					X[0],				\
					X[1],				\
					X[2],				\
					X[3]);

#endif /* !DEBUG_H_ */
