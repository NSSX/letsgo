#include "my_printf.h"
#define TYPE int
#include <wchar.h>

void accurate_d(int size, t_main *main)
{
  if(main->signemoin == 1)
  {
    main->accurate++;
  }
     while(size < main->accurate)
    	{
    	  main->print = ft_strjoin(main->print, "0");
    	  size++;
    	  main->size++;
    	}
}

void join_lld(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((long long int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_ld(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((long int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_hd(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((short int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_hhd(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((signed char)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_jd(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((long long int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_zd(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((long long int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_d(t_main *main)
{
  char *number;
  int size;

  number = my_itoa((int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_lu(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((unsigned long int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_llu(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((unsigned long long int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_hu(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((unsigned short int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_hhu(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((unsigned char)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_ju(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((size_t)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_zu(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((size_t)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}

void join_u(t_main *main)
{
  char *number;
  int size;

  number = my_utoa((unsigned int)main->elem);
  size = ft_strlen(number);
  main->size += size;
  if(main->accurate != -1)
    accurate_d(size, main);
  main->print = ft_strjoin(main->print, number);
}


//ECOUTE BIEN SI YA PAS DE CONVERTER ON ECRIT LE TRUC NORMAL
// SDU
//http://personal.ee.surrey.ac.u           k/Personal/R.Bowden/C/printf.html
int manage_arg(t_main *main)
{
  main->i++;
  if(main->chaine[main->i] == 'd' || main->chaine[main->i] == 'i' || main->chaine[main->i] == 'D')
    {
    long long int a;
    a = (long long int)main->elem;
    if ((int)a < 0 && main->type == 0)// || (long int)a < 0 || (long long int)a < 0)
	    main->signemoin = 1;
    else if ((long int)a < 0 && main->type == 1)
        main->signemoin = 1;
      else if ((long long int)a < 0 && main->type == 2)
        main->signemoin = 1;
      if(main->type == 0)
        join_d(main);
      else  if(main->type == 1)
	     join_ld(main);
      else  if(main->type == 2)
	     join_lld(main);
      else if(main->type == 3)
	     join_hd(main);
      else if(main->type == 4)
	     join_hhd(main);
      else if(main->type == 5)
	     join_jd(main);
      else if(main->type == 6)
	     join_zd(main);
  
       if(main->signemoin == 1)
        {
          int i = 0;
          int i2 = 0;
          char *temp;
          temp = (char *)malloc(sizeof(char) + ft_strlen(main->print));
           while(main->print[i] != '\0')
           {
            if(main->print[i] != '-')
            {
            
              temp[i2] = main->print[i];
              i2++;
            }
            i++;
          }
          temp[i2] = '\0';
          main->print = temp;
        main->print = ft_strjoin("-", main->print);
        }
       
     }  


    else if(main->chaine[main->i] == 'o')
    {
      int size;
      int i;

      i = 0;
      if(main->dietat == 1)
  	   {
  	      main->print = ft_strjoin(main->print, "0");
  	      main->size++;
	     }
      base_converter(main, (unsigned long long int)main->elem, 8);
      size = ft_strlen(main->print);
      if(main->accurate > 0)
	{
	  while(size < main->accurate)
	    {
	      main->print = ft_strjoin("0",main->print); 
	      i++;
	      size++;
	      main->size++;
	    }
	}
   }
  else if(main->chaine[main->i] == 'u')
    {
      if(main->type == 0)
        join_u(main);
      else  if(main->type == 1)
        join_lu(main);
      else  if(main->type == 2)
        join_llu(main);
      else if(main->type == 3)
        join_hu(main);
      else if(main->type == 4)
        join_hhu(main);
      else if(main->type == 5)
        join_ju(main);
      else if(main->type == 6)
      	join_zu(main);
    }
  else if(main->chaine[main->i] == 'U')
    {
        join_u(main);
    }
  else if(main->chaine[main->i] == 's')
    {
      if((char *)main->elem)
  	   {
          	  if(main->accurate == -1)
          	    main->accurate = ft_strlen((char *)main->elem);
          	  char *lp;
          	  
          	  lp = (char *)main->elem;
          	  lp = ft_strsub(lp, 0, main->accurate);
          	  main->print = ft_strjoin(main->print, &lp[0]);
          	  if((size_t)main->accurate > ft_strlen(lp))
          	    main->size = ft_strlen(lp);
          	  else
          	    main->size += main->accurate;
          	    }
                else
          	   {
                      char *null;
                      int i;
                      i = 0;
                      null = "(null)";
                      while(i < main->accurate && i < 6)
                      {
                        main->print= ft_strjoin_carac(main->print, null[i]);
                  	    main->size++;
                        i++;
                      }
               }
    }
  else if(main->chaine[main->i] == 'S')
    {
   int i;
      wchar_t *chaine;

      chaine = (wchar_t *)main->elem;
      i=0;

      //need precision here with var OK PREC pretty easy  ces dla merde sa
      while(chaine[i] != '\0' && main->size < main->accurate)
      {
        mywchar(main, chaine[i]);
        i++;
      }
    }
  else if(main->chaine[main->i] == 'c')
    {
      if((int)main->elem != 0)
      {
	       main->size++;
	      main->print = ft_strjoin_carac(main->print, (int)main->elem);
      }
        else
          {
            main->size++;
           }
    }
  else if(main->chaine[main->i] == 'C')
    {
        mywchar(main, (wint_t)main->elem);
    }
  else if(main->chaine[main->i] == '%')
    {
      main->sizeword++;
      main->print = ft_strjoin_carac(main->print, '%');
    }
  else if(main->chaine[main->i] == 'p')
    {
      if((unsigned long long int)main->elem == 0)
	   {
	      main->size += 3;
	     main->print = ft_strjoin(main->print, "0x0");
  	}
      else
	   {
	     main->size += 2;
	     main->print = ft_strjoin(main->print, "0x");
	     base_converter(main, (unsigned long long int)main->elem, 16);
	   }

    }
  else if(main->chaine[main->i] == 'x')
    {

      int i;
      int size;
      i = 0;
      if(main->dietat == 1)
	{
	  main->print = ft_strjoin(main->print, "0x");
	  main->size += 2;
	}
      if((unsigned long long int)main->elem != 0)
	base_converter(main, (unsigned long long int)main->elem, 16);
      size = ft_strlen(main->print);
      if(main->accurate > 0)
        {
          while(size < main->accurate)
            {
              main->print = ft_strjoin("0",main->print);
              i++;
              size++;
              main->size++;
            }
        }
    }
  else if(main->chaine[main->i] == 'X')
    {
      int i = 0;
      int size;

      if(main->dietat == 1)
	{
          main->print = ft_strjoin(main->print,"0X");
	  main->size += 2;        
	}
      if((unsigned long long int)main->elem != 0)
	       base_converter_upper(main, (unsigned long long int)main->elem, 16);
      size = ft_strlen(main->print);
      if(main->accurate > 0)
        {
          while(size < main->accurate)
            {
              main->print = ft_strjoin("0",main->print);
              i++;
              size++;
              main->size++;
            }
        }

    }
  else
    main->i--;
  return (1);
}
