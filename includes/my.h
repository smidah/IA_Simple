#ifndef MY_H
#define MY_H
#include "lib.h"



typedef struct Map Map;
struct Map
{
    int fin_x;
    int fin_y;
    int perso_x;
    int perso_y;
};

char    **create_tab(int ligne, int colonne);
void    buffer_en_tab(char* buffer, int nbLin, int nbCol,char **argv);
void	read_map(char **argv);
char	*readtab(char *chemin);
void    position(char **tab, int nbLin, char **argv);
void	calcule_simple(Map pos_init, char ** argv);
int		verif_arg(int 	argc, char	**argv);
int	    verif_nbr(char *str);
int		map_open(char	*map);

int     nb_resource;

typedef struct Perso Perso;
struct Perso
{
    int x;
    int y;
    int nb_vie;
};

typedef struct Bonus Bonus;
struct Bonus
{
    int x;
    int y;
};


	

#endif
