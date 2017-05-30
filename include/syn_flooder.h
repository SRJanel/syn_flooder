/*
** syn_flooder.h for SYN_FLOODER_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 14:45:33 2017 Janel
** Last update Mon May 29 18:52:14 2017 Janel
*/

#ifndef SYN_FLOODER_H_
# define SYN_FLOODER_H_

# define TRUE				1
# define FALSE				!TRUE
# define RANDOM_NBR_RANGE(MIN, MAX)	((MAX > MIN) ? (rand() % (MAX - MIN) + MIN) \
					 : (rand() % (MIN - MAX) + MAX))

/*
** src/packet.c
*/
unsigned char	*build_packet(void);

#endif /* !SYN_FLOODER_H_ */
