/*
** syn_flooder.h for SYN_FLOODER_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 14:45:33 2017 Janel
** Last update Tue Jul 25 16:19:04 2017 Janel
*/

#ifndef SYN_FLOODER_H_
# define SYN_FLOODER_H_

# include <netinet/in.h>
# include "layer3.h"
# include "layer4.h"

# define TRUE				1
# define FALSE				!TRUE
# define RANDOM_NBR_RANGE(MIN, MAX)	(rand() % ((MAX > MIN) ?	\
						   ((MAX - MIN) + MIN) : \
						   ((MIN - MAX) + MAX)))
# define SEND_TIME_DELAY		100

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
			    struct sockaddr_in *destination_address);
unsigned short		csum(unsigned short *ptr,int nbytes);
void		build_tcp_pseudoheader(t_tcp_pseudoheader *tcp_pseudoheader,
				       t_ip_header *ip_header,
				       t_tcp_header *tcp_header);
void		checksum_packets(t_ip_header *ip_header, t_tcp_header *tcp_header);

#endif /* !SYN_FLOODER_H_ */
