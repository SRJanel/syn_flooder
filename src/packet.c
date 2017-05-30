/*
** packet.c for packet in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 16:18:58 2017 Janel
** Last update Tue May 30 02:09:32 2017 Janel
*/

# define _BSD_SOURCE
#include <stdlib.h>
/* #include <arpa/inet.h> */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/if_ether.h>
#include "syn_flooder.h"
#include "layer4.h"
#include "layer3.h"
#include "debug.h"

static t_ip_header	*build_ip_header(void)
{
  t_ip_header		*ip_header;

  INSIDE;
  if (!(ip_header = malloc(sizeof(t_ip_header))))
    return (PRINT_ERROR("malloc:"), NULL);
  memset(ip_header, 0, sizeof(t_ip_header));
  ip_header->header_length = 5;
  ip_header->version = 4;
  ip_header->type_of_service = 0;
  ip_header->ip_fragment_offset = 0;
  ip_header->time_to_live = htons(RANDOM_NBR_RANGE(64, 255));
  ip_header->protocol = htons(IPPROTO_TCP);
  ip_header->identification = htons(RANDOM_NBR_RANGE(0, 0xFFFF));

  /* ip_header->total_length = sizeof(struct iphdr) + sizeof(struct ethhdr); */
  /* ip_header->header_checksum = 0; */
  if (inet_aton("41.41.41.41", &ip_header->source_address) != 1
      || inet_aton("42.42.42.42", &ip_header->destination_address) != 1) /* !!!! CHANGE TO TARGET IP */
    return (PRINT_ERROR("inet_pton:"), NULL);

  return (ip_header);
}

/* static char	build_tcp_header(void) */
/* { */
/*   t_tcp_header	*tcp_header; */

/*   if (!(tcp_header = malloc(sizeof(t_tcp_header)))) */
/*     return (PRINT_ERROR("malloc: "), FALSE); */
/*   memset(&tcp_header, 0, sizeof *tcp_header); */
/*   tcp_header->ipv = 4; */
/* } */

unsigned char	*build_packet(void)
{
  t_ip_header	*ip_header;
  /* t_tcp_header	*tcp_header; */

  INSIDE;
  if (!(ip_header = build_ip_header()))
    return (NULL);

  /* if (!(tcp_header = build_tcp_header())) */
  /*   return ; */

  return ((unsigned char *)ip_header);
}
