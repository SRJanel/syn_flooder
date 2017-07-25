/*
** checksum.c for checksum in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Tue Jul 25 15:41:45 2017 Janel
** Last update Tue Jul 25 16:18:17 2017 Janel
*/

#include <string.h>
#include <netinet/ip.h>
#include "layer3.h"
#include "layer4.h"

unsigned short		csum(unsigned short *ptr, int nbytes)
{
  register long		sum;
  unsigned short	oddbyte;

  sum = 0;
  while (nbytes > 1)
    {
      sum += *ptr++;
      nbytes -= 2;
    }
  if (nbytes == 1)
    {
      oddbyte = 0;
      *((unsigned char *)&oddbyte) = *(unsigned char *)ptr;
      sum += oddbyte;
    }
  sum = (sum >> 16) + (sum & 0xFFFF);
  sum = sum + (sum >> 16);
  return ((short)~sum);
}

static void		build_tcp_pseudoheader(t_tcp_pseudoheader *tcp_pseudoheader,
					       t_ip_header *ip_header,
					       t_tcp_header *tcp_header)
{
  tcp_pseudoheader->source_address = ip_header->source_address.s_addr;
  tcp_pseudoheader->destination_address = ip_header->destination_address.s_addr;
  tcp_pseudoheader->reserved = 0;
  tcp_pseudoheader->protocol = IPPROTO_TCP;
  tcp_pseudoheader->tcp_segment_length = htons(sizeof(t_tcp_header));
  memcpy(&tcp_pseudoheader->tcp_header, tcp_header, sizeof(t_tcp_header));
}

void			checksum_packets(t_ip_header *ip_header, t_tcp_header *tcp_header)
{
  t_tcp_pseudoheader	tcp_pseudoheader;

  tcp_header->checksum = 0;
  ip_header->header_checksum = 0;
  build_tcp_pseudoheader(&tcp_pseudoheader, ip_header, tcp_header);
  ip_header->header_checksum = csum((unsigned short *)ip_header, sizeof(ip_header->total_length >> 1));
  tcp_header->checksum = csum((unsigned short *)&tcp_pseudoheader, sizeof(t_tcp_pseudoheader));
}
