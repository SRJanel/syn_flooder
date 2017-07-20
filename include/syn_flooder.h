/*
** syn_flooder.h for SYN_FLOODER_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 14:45:33 2017 Janel
** Last update Thu Jul 13 11:15:31 2017 Janel
*/

#ifndef SYN_FLOODER_H_
# define SYN_FLOODER_H_

# include <netinet/in.h>

# define TRUE				1
# define FALSE				!TRUE
# define RANDOM_NBR_RANGE(MIN, MAX)	(rand() % ((MAX > MIN) ?	\
						   ((MAX - MIN) + MIN) : \
						   ((MIN - MAX) + MAX)))
# define SEND_TIME_DELAY		100000

/*
** src/packet.c
*/
char		build_packet(unsigned char *packet,
			     const char *target_ip_address,
			     const int port);
__inline__ void	set_destination_address(struct sockaddr_in *dest_addr,
					const in_addr_t target,
					const int port);
char		send_packet(const int sd, unsigned char *packet,
			    struct sockaddr_in *destination_address, const char *src, const char *dest);

unsigned short		csum(unsigned short *ptr,int nbytes);

#endif /* !SYN_FLOODER_H_ */
