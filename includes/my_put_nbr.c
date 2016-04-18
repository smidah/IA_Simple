/*
** my_put_nbr.c for my_put_nbr.c in /home/iche_n/piscine_c/jour05/my_put_nbr
** 
** Made by ICHE nour el yakine
** Login   <iche_n@etna-alternance.net>
** 
** Started on  Sat Oct  3 16:24:44 2015 ICHE nour el yakine
** Last update Sat Oct  3 22:49:40 2015 ICHE nour el yakine
*/
void	my_putchar(char c);

void	my_putstr(char *str);

void	my_put_nbr(int n)
{
  int	div;
  int	res;
  
  div = 1;
  if (n == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (n < 0)
        {
          my_putchar('-');
          n *= -1;
        }
      while ((n / div) >= 10)
	{
	  div *= 10;
	}
      while (div > 0)
	{
	  res = (n / div) % 10;
	  my_putchar(res + '0');
	  div /= 10;
	}
    }
}
