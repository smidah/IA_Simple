/*
** my_putstr.c for my_putstr.c in /home/iche_n/piscine_c/jour03/iche_n/my_putstr
** 
** Made by ICHE nour el yakine
** Login   <iche_n@etna-alternance.net>
** 
** Started on  Wed Sep 30 09:46:14 2015 ICHE nour el yakine
** Last update Wed Sep 30 10:25:21 2015 ICHE nour el yakine
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  while (*str != '\0')
    {
      my_putchar (*str);
      str++;
    }
}
