#include "my.h"

void	calcule_simple(Map pos_init, char ** argv)
{
		int x;
		int y;
		int distance;
		int nb_coup;
		int nb_vie;
		
		
		nb_coup = my_getnbr(argv[1]);
		x = pos_init.fin_x - pos_init.perso_x;
		x = (x > 0) ? x : x * (-1);
		y = pos_init.fin_y - pos_init.perso_y;
		y = (y > 0) ? y : y * (-1);
		distance = x + y;
		nb_vie = nb_coup - distance;
		if (distance <= nb_coup)
		{
			my_putstr("OK\nNombre de vie: ");
			my_put_nbr(nb_vie);
			my_putstr("\n");
		}
			
		else
			my_putstr("KO\n");
}

void    position(char **tab, int nbLin, char **argv)
{
    int i;
    int j;
    
    Map pos_init;
    i = 0;
    j = 0;

    for(i = 0; i <= nbLin; i++)
	{
	    for(j = 0; tab[i][j]; j++)
	    {
	        if (tab[i][j] == '@')
	        {
	            pos_init.perso_x = i;
	            pos_init.perso_y = j;
	        }
	        if (tab[i][j] == '#')
	        {
	            pos_init.fin_x = i;
	            pos_init.fin_y = j;
	        }
	        
	    }
    }
    calcule_simple(pos_init, argv);
}

int	verif_nbr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			i++;
		else
			return 0;
	}
    return (1);
}

int	my_getnbr(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			++j;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10;
		k = k + (str[i] - '0');
		++i;
	}
	if (j % 2)
		k = k * -1;
	return (k);
}

int		verif_arg(int 	argc, char	**argv)
{
	if (argc == 4)
	{
		if (my_getnbr(argv[1]) >= 0 && verif_nbr(argv[1]) == 1 && (my_getnbr(argv[2]) >= 0 && verif_nbr(argv[2]) == 1))
		{
			if (map_open(argv[3]) == 1)
				read_map(argv);
		}
		else
			my_putstr("-> Veuillez rentrer un nombre valide\n");
	}
	else
		my_putstr("-> Exemple d'utilisation: ./solve 5 2 map.txt\n");
	return 0;
}

int		map_open(char	*map)
{
	if (open(map, O_RDONLY) != -1)
		return 1;
	else
		my_putstr("-> Impossible d'ouvrir la map.\n");
	return 0;
}