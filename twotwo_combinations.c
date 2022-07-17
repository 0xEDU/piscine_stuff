void	answer_h_to_one_at_first_or_last(int h[4][2], int a[4][4]);
void	answer_v_to_one_at_first_or_last(int v[4][2], int a[4][4]);
void	answer_h_for_2_in_first_or_last_position(int h[4][2], int a[4][4]);
void	print_answer(int a[4][4]);
int	has_repetitions(int a[4][4]);
int	has_v_repetition(int a[4][4]);
int	column_has_repetition(int a[4][4], int column);
int	has_h_repetition(int a[4][4]);
int	line_has_repetition(int a[4][4], int line);

void	answer_two_two(int h[4][2], int v[4][2], int a[4][4])
{	
	answer_h_to_one_at_first_or_last(h, a);
	answer_v_to_one_at_first_or_last(v, a);
	answer_h_for_2_in_first_or_last_position(h, a);
}

void	answer_h_to_one_at_first_or_last(int h[4][2], int a[4][4])
{
	int l;

	l = 0;
	while (l < 4)
	{
		if (h[l][0] == 2 && h[l][1] == 2)
		{
			if (a[l][0] == 1)
			{
				a[l][1] = 4;
				a[l][2] = 2;
				a[l][3] = 3;
			}
			if (a[l][3] == 1)
			{
				a[l][0] = 3;
				a[l][1] = 2;
				a[l][2] = 4;
			}
		}	
		l++;
	}
}

void	answer_v_to_one_at_first_or_last(int v[4][2], int a[4][4])
{
	int c;

	c = 0;
	while (c < 4)
	{
		if (v[c][0] == 2 && v[c][1] == 2)
		{
			if (a[0][c] == 1)
			{
				a[1][c] = 4;
				a[2][c] = 2;
				a[3][c] = 3;
			}
			if (a[3][c] == 1)
			{
				a[0][c] = 3;
				a[1][c] = 2;
				a[2][c] = 4;
			}
		}
		c++;
	}
}

void	answer_h_for_2_in_first_or_last_position(int h[4][2], int a[4][4])
{
	int	l;

	l = 0;
	while (l < 4)
	{
		if (h[l][0] == 2 && h[l][1] == 2)
		{
			if (a[l][0] == 2 || a[l][3] == 2)
			{
				a[l][1] = 1;
				a[l][2] = 4;
				if (has_repetitions(a) != 0)
				{
					a[l][1] = 4;
					a[l][2] = 1;
				}
				if (has_repetitions(a) != 0)
				{
					a[l][1] = 0;
					a[l][2] = 0;
				}
			}
		}
		l++;
	}
}

void	answer_v_for_2_in_first_or_last_position(int v[4][2], int a[4][4])
{
	int	c;

	c = 0;
	while (c < 4)
	{
		if (v[c][0] == 2 && v[c][1] == 2)
		{
			if (a[0][c] == 2 || a[3][c] == 2)
			{
				a[1][c] = 1;
				a[2][c] = 4;
				if (has_repetitions(a) != 0)
				{
					a[1][c] = 4;
					a[2][c] = 1;
				}
				if (has_repetitions(a) != 0)
				{
					a[1][c] = 0;
					a[2][c] = 0;
				}
			}
		}
		c++;
	}
}

int	has_repetitions(int a[4][4])
{
	int it_has;

	it_has = 0;
	it_has += has_h_repetition(a);
	it_has += has_v_repetition(a);

	return it_has;
}

int	has_v_repetition(int a[4][4])
{
	int c;

	c = 0;
	while (c < 4)
	{
		if (column_has_repetition(a, c) != 0)
			return 1;
		c++;
	}
	return 0;
}

int	column_has_repetition(int a[4][4], int column)
{
	int l;
	int i;
	int counter;

	i = 1;
	while (i <= 4)
	{
		l = 0;
		counter = 0;
		while (l < 4)
		{
			if (a[l][column] == i)
				counter++;
			l++;
		}
		if (counter > 1)
			return 1;
		i++;
	}
	return 0;
}

int	has_h_repetition(int a[4][4])
{
	int	l;
	int	c;
	int i;
	int counter;

	l = 0;
	while (l < 4)
	{
		if (line_has_repetition(a, l) != 0)
			return 1;
		l++;
	}
	return 0;
}

int	line_has_repetition(int a[4][4], int line)
{
	int c;
	int i;
	int counter;

	i = 1;
	counter = 0;
	while (i <= 4)
	{
		c = 0;
		counter = 0;
		while (c < 4)
		{
			if (a[line][c] == i)
				counter++;
			c++;
		}
		if (counter > 1)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
