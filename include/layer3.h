/*
** layer3.h for LAYER3_H_ in /home/janel/sniffer
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Tue Apr 11 14:37:28 2017 Janel
** Last update Mon May 29 18:42:55 2017 Janel
*/

#ifndef LAYER3_H_
# define LAYER3_H_

/* # include <linux/in.h>	shame :/  */

#include <arpa/inet.h>

typedef struct		s_ip_header
{
#if __BYTE_ORDER == __LITTLE_ENDIAN
  unsigned int		header_length:4;
  unsigned int		version:4;

#elif __BYTE_ORDER == __BIG_ENDIAN
  unsigned int		version:4;
  unsigned int		header_length:4;

#else
# error "Fix your <bits/endian.h>"
#endif /* !__BYTE_ORDER */

  unsigned char		type_of_service;
  unsigned short	total_length;
  unsigned short	identification;

  unsigned short	ip_fragment_offset;

  unsigned char		time_to_live;
  unsigned char		protocol;
  unsigned short	header_checksum;
  struct in_addr	source_address;
  struct in_addr	destination_address;
}			t_ip_header;

#if 0
# define RF_FLAG_MASK			0x8000
# define DF_FLAG_MASK			0x4000
# define MF_FLAG_MASK			0x2000
# define F_OFFSET_MASK			0x1FFF
# define GET_IP_RF_FLAG(IPHDR)		((ntohs(IPHDR->ip_fragment_offset) & RF_FLAG_MASK) >> 0xF)
# define GET_IP_DF_FLAG(IPHDR)		((ntohs(IPHDR->ip_fragment_offset) & DF_FLAG_MASK) >> 0xE)
# define GET_IP_MF_FLAG(IPHDR)		((ntohs(IPHDR->ip_fragment_offset) & MF_FLAG_MASK) >> 0xD)
# define GET_IP_OFFSET_BITS(IPHDR)	(ntohs(iphdr->ip_fragment_offset) & F_OFFSET_MASK)

void			print_ip_header(const char buffer[const]);
#endif /* !0 */

#endif /* !LAYER3_H_ */
