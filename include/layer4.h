/*
** layer4.h for LAYER4_H_ in /home/janel/dns_poisoning
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Tue Apr 11 14:37:28 2017 Janel
** Last update Wed May 31 20:05:40 2017 Janel
*/

#ifndef LAYER4_H_
# define LAYER4_H_

typedef struct		s_tcp_header
{
  /* LINE 1 */
  unsigned short	source_port;
  unsigned short	destination_port;
  /* LINE 2 */
  unsigned int		sequence_number;
  /* LINE 3 */
  unsigned int		acknowledgement_number;

  /* LINE 4 */
#if __BYTE_ORDER == __LITTLE_ENDIAN
  unsigned short	reserved:4;
  unsigned short	offset:4;

  unsigned short	tcp_flag_fin:1;
  unsigned short	tcp_flag_syn:1;
  unsigned short	tcp_flag_rst:1;
  unsigned short	tcp_flag_psh:1;
  unsigned short	tcp_flag_ack:1;
  unsigned short	tcp_flag_urg:1;
  unsigned short	tcp_flag_ece:1;
  unsigned short	tcp_flag_cwr:1;
#elif __BYTE_ORDER == __BIG_ENDIAN
  unsigned short	offset:4;
  unsigned short	reserved:4;

  unsigned short	tcp_flag_cwr:1;
  unsigned short	tcp_flag_ece:1;
  unsigned short	tcp_flag_urg:1;
  unsigned short	tcp_flag_ack:1;
  unsigned short	tcp_flag_psh:1;
  unsigned short	tcp_flag_rst:1;
  unsigned short	tcp_flag_syn:1;
  unsigned short	tcp_flag_fin:1;
#else
# error "Please fix your <bits/endian.h>"
#endif /* !__BYTE_ORDER */
  unsigned short	window;

  /* LINE 5 */
  unsigned short	checksum;
  unsigned short	urgent_pointer;
}			t_tcp_header;

typedef struct		s_tcp_pseudoheader
{
  unsigned int		source_address;
  unsigned int		destination_address;
  unsigned char		reserved;
  unsigned char		protocol;
  unsigned short	tcp_segment_length;
  t_tcp_header		*tcp_header;
}			t_tcp_pseudoheader;

#if 0
void					print_tcp_header(const char buffer[const]);
void					__attribute__((unused))print_udp_header(const char buffer[const]);
#endif /* !0 */

#endif /* !LAYER4_H_ */
