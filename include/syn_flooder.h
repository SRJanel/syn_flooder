/*
** syn_flooder.h for SYN_FLOODER_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 14:45:33 2017 Janel
** Last update Mon Oct 23 00:26:57 2017 
*/

#ifndef SYN_FLOODER_H_
# define SYN_FLOODER_H_

# include <netinet/tcp.h>

# define SEND_TIME_DELAY		0x42

typedef struct		s_tcp_pseudoheader
{
  unsigned int		source_address;
  unsigned int		destination_address;
  unsigned char		reserved;
  unsigned char		protocol;
  unsigned short	tcp_segment_length;
  struct tcphdr		tcp_header;
}			t_tcp_pseudoheader;

# define TRUE				1
# define FALSE				!TRUE
# define RANDOM_NBR_RANGE(MIN, MAX)	(rand() % ((MAX > MIN) ?	\
						   ((MAX - MIN) + MIN) : \
						   ((MIN - MAX) + MAX)))

/*
** src/packet.c
*/
char		build_packet(unsigned char *packet,
			     const char *target_ip_address,
			     const int port);
void		set_destination_address(struct sockaddr_in *dest_addr,
					const in_addr_t target,
					const int port);
char		send_packet(const int sd, unsigned char *packet,
			    struct sockaddr_in *destination_address);
unsigned short	csum(unsigned short *ptr,int nbytes);
void		checksum_packets(struct iphdr *ip_header, struct tcphdr *tcp_header);

#endif /* !SYN_FLOODER_H_ */
