#include "my.h"

char **create_tab(int ligne, int colonne)
{ 
	int i; 
	char **tab;
	tab = malloc(ligne * sizeof(*tab));
	if (tab == NULL)
		my_putstr("Erreur de malloc !\n");
	for(i = 0; i < colonne; i++)
	{
		tab[i] = malloc(colonne * sizeof(**tab));
		if (tab[i] == NULL) 
			my_putstr("Erreur de malloc !\n");
	}
	return tab;
}



void buffer_en_tab(char* buffer, int nbLin, int nbCol,char **argv)
{
	int i;
	int j;
	char **tab;
	
	i = 0;
	j = 0;
	tab = create_tab(nbLin, nbCol);
	
	while( buffer[i])
	{
		int h = 0;
		while (buffer[i] != '\n' && buffer[i] != '\0')
		{
			tab[j][h] = buffer[i];
			i++;
			h++;
		}
		j++;
		i++;
	}
	position(tab, nbLin, argv);
}

void	read_map(char **argv)
{
	char *buffer;
    int handle;
	int i;
	int nbCol;
	int nbLin = 1;
	int len;
	int fp;
	char c;

	
	nb_resource = 0;
	len = 0;
	fp = open(argv[3], O_RDONLY);
	while (read(fp, &c, sizeof(c)) > 0)
		len++;
	buffer = malloc(sizeof(char)*len);
    handle = open(argv[3], O_RDONLY, S_IRUSR);
    read(handle, buffer, len);

	i = 0;
	while( buffer[i])
	{
		if (buffer[i] == '\n')
			nbLin++;
		for (nbCol = 0; buffer[nbCol] != '\n'; nbCol++)
		{
			if (buffer[nbCol] == '+')
				nb_resource++;
		}
		 i++;
	}
	buffer_en_tab(buffer, nbLin, nbCol, argv);
}
