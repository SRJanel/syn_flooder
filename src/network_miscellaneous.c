/*
** network_miscellaneous.c for network_miscellaneous in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Mon May 29 14:38:44 2017 Janel
** Last update Mon May 29 14:45:18 2017 Janel
*/

#include <linux/in.h>
#include <sys/socket.h>
#include "syn_flooder.h"
#include "debug.h"

/*
** Setting IP_HDRINCL on socket. On some OS's,
** IPPROTO_RAW will not set IP_HDRINCL automatically.
*/
__inline__ char	set_header_ip_inclusion(const int sd)
{
  return ((setsockopt(sd, IPPROTO_IP, IP_HDRINCL,
		      &(int){1}, sizeof(int)))
	  ? (TRUE) : (PRINT_ERROR("setsockopt: "), FALSE));
}
