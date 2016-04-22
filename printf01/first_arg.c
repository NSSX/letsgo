#include "my_printf.h"

int flag_fiel(t_main *main)
{
  main->i++;
  if(main->chaine[main->i] == '+')
    {
      if((int)main->elem >= 0)
        {
          main->taille++;
          main->size++;
	  //          main->print = ft_strjoin(main->print, "+");
	  main->plusetat = 1;
        }
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == '#')
    {
      main->dietat = 1;
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == '-')
    {
      main->moinetat = 1;
      flag_fiel(main);
    }
  else if(main->chaine[main->i] == ' ')
    {
      if((int)main->elem >= 0)
        {
          main->taille++;
          main->size++;
          main->print = ft_strjoin(main->print, " ");
	  while(main->chaine[main->i + 1] == ' ')
	    {
	      main->i++;
	    }
        }
      flag_fiel(main);
    }
  else
    main->i--;
  return (0);
}
