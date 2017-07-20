/*
** network.c for network in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Wed Jun  7 14:44:54 2017 Janel
** Last update Mon Jul 10 15:01:58 2017 Janel
*/

#include <netinet/in.h>
#include <sys/socket.h>

void	 set_destination_address(struct sockaddr_in *dest_addr,
					const in_addr_t target,
					const int port)
{
  dest_addr->sin_family = AF_INET;
  dest_addr->sin_port = htons(port);
  dest_addr->sin_addr.s_addr = target;
}
