#include "my_printf.h"
#include <wchar.h>
#include <locale.h>
//SpdDoOuUxXcC
int main()
{
  int res1;
  int res2;
  setlocale(LC_ALL, "");
  //  long int a = LONG_MIN;
  //  unsigned long a = 200;
   //   char *i = "lol";
  res1 = 0;
  res2 = 0;
//80 800 10000 200000 /
  wchar_t *l = L"oh tu te calme";
  //les modifier l ll etc voir dans le man 3 printf
  //La precision dit cb de carac afficher
  //peut etre un ft_strjoin pour un bloc ?
  printf("VRAI PRINTF : \n");
  res1 = printf("%80S|", l);
  printf("\n");
  printf("MON PRINTF : \n");
  res2 = ft_printf("%80S|", l);
  ft_putstr("\nret 1 : ");
  ft_putnbr(res1);
  ft_putstr("\nret 2 : ");
  ft_putnbr(res2);
  return (0);
}

