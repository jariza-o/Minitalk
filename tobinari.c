unsigned long long    *ft_bi(unsigned long long n)
{
	unsigned long long	num[7];
	int	i;

	i = 0;
	if (n > 1)
	{
		ft_bi((n / 2));
		ft_bi((n % 2));
	}
	else
		num[i++] = n;
	return (*num);
}

void	ft_send(int pid, char c)
{
	int	n;
	int i;
	unsigned long long	*bi;
	unsigned long long	bi8[7];
	
	*bi = ft_bi((unsigned long long)c);
	n = 0;
	while (bi[n] != '\0')
		n++;
	while (n != 7 && n >= 0)
	{
		i = 7;
		bi8[i] = bi[n];
		i--;
		n--;
	}
	while (i >= 0)
	{
		bi8[i] = 0;
		i--;
	}
	i = 0;
	while (i <= 7)
	{
		if (bi8[i] == 1)
			kill(pid, SIGUSR1); //manda una señal al PID indicado
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}