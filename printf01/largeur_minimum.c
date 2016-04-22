#include "my_printf.h"

int add_mini(t_main *main)
{
  int needzero;
  char *final;
  char *myfinal;
int ok;

ok = 0;
  myfinal = (char *)malloc(sizeof(char) * 1);
  final = (char *)malloc(sizeof(char) * 1);
  needzero = main->width - main->size;

  if(needzero > 0 || needzero < 0)
    {   
      if(main->zeroetat == 0 || main->pointetat != 0)
    	{
      	  if(main->moinetat == 0)
      	    {
      	      while(needzero > 0)
      	     	{
          		  main->print = ft_strjoin(" ", main->print);
          		  main->size++;
          		  needzero--;
          		}
      	    }
      	  else
      	    {
      	      if(needzero < 0)
        	  	{
      	   	    main->width = -main->width;
      	 	      needzero = main->width - main->size;
      		   }
      		  while(needzero > 0)
      		    {
      		      main->print = ft_strjoin(main->print, " ");
      		      main->size++;
      		      needzero--;
      		    }
      	    }
	   }
      else 
	{
	  if(main->moinetat == 0)
            {
              while(needzero > 0)
                {
                  main->print = ft_strjoin("0", main->print);
                  main->size++;
                  needzero--;
		}
            }
	  else
            {
              while(needzero > 0)
		{
                  main->print = ft_strjoin(main->print, "0");
                  main->size++;
                  needzero--;
		}
            }
	}
    }
  if(main->plusetat == 1)
    main->print = ft_strjoin("+", main->print);
  return (0);
}

int my_width(t_main *main, va_list *myva)
{
  int i;
  int size;
  int i2;
  char *myacc;

  i2 = 0;
  if(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
    {
      i = main->i + 1;
      if(main->chaine[main->i + 1] == '0')
	{
	  main->zeroetat = 1;
	  main->i++;
	}  
    while(main->chaine[main->i + 1] >= '0' && main->chaine[main->i + 1] <= '9')
        {
          main->i++;
        }
      size = main->i - i;
      myacc = (char *)malloc(sizeof(char) * size + 1);
      while(i <= main->i)
        {
          myacc[i2] = main->chaine[i];
          i2++;
          i++;
        }
      myacc[i2] = '\0';
      main->width = ft_atoi(myacc);
    }
  else if(main->chaine[main->i + 1] == '*')
    {
      main->i++;
      main->width = (int)main->elem;
      if(main->width < 0)
	       main->moinetat = 1;
      main->elem = va_arg(*myva, void *);
    }
 
  return (0);
}
