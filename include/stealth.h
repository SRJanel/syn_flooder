/*
** stealth.h for STEALTH_H_ in /home/janel/Projects/templates/network/SYN_flooder
**
** Made by Janel
** Login   <janel@epitech.net>
**
** Started on  Tue Jul 25 13:17:18 2017 Janel
** Last update Tue Jul 25 15:08:57 2017 Janel
*/

#ifndef STEALTH_H_
# define STEALTH_H_

typedef struct		s_os_simulation
{
  unsigned char		ttl;
  unsigned short	window_size;
  char			*tag;
}			t_os_simulation;

# define OS_TABLE							\
  ENTRY(LINUX_KERNEL_2_4_AND_2_6 = 0,		64, 5840,	"Linux 2.4 and 2.6") \
  ENTRY(GOOGLE_CUSTOMIZED_LINUX,		64, 5720,	"Google") \
  ENTRY(FREE_BSD,				64, 65535,	"Free BSD") \
  ENTRY(WINDOWS_XP,				128, 65535,	"Windows xp") \
  ENTRY(WINDOWS_7_VISTA_AND_SERVER_2008,	128, 8192,	"Windows 7") \
  ENTRY(CISCO_ROUTER,				255, 4128,	"Cisco router")	\
  ENTRY(DEFAULT,				64, 65535,	"Default OS")

enum {
# define ENTRY(a, b, c, d) a,
  OS_TABLE
# undef ENTRY
  MAX_NBR_STATE
};

t_os_simulation		g_os_simulation[MAX_NBR_STATE] =
  {
# define ENTRY(a, b, c, d) {b, c, d},
    OS_TABLE
# undef ENTRY
  };

#endif /* !STEALTH_H_ */
