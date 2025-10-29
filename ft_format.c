int ft_print_char (int c)
{
	int res;
	int count;

	count = 0;
	res = write (1, &c, 1);
	if (res == -1) 
		return (-1); 
	count = res + count;
	return (count);
}



ft_print_nbr(int n) → para %d y %i

ft_print_unsigned(unsigned int n) → para %u

ft_print_hex(unsigned int n, int uppercase) → para %x y %X

ft_putnbr_base(unsigned long n, char *base) → función común para conversión