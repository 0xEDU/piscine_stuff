
void	answer_h_to_one_at_first_or_last(int h[4][2], int a[4][4]);
void	answer_v_to_one_at_first_or_last(int v[4][2], int a[4][4]);
void	print_answer(int a[4][4]);

void	answer_two_two(int h[4][2], int v[4][2], int a[4][4])
{	
	answer_h_to_one_at_first_or_last(h, a);
	answer_v_to_one_at_first_or_last(v, a);
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
/*
void	answer_h_to_2_and_3_in_the_edges(int h[4][2], int a[4][4])
{
	int	l;

	l = 0;
	while (l < 4)
	{
		if (h[l][0] == 2 && [h][1] == 2)
		{
			if (a[l][0] == 2 && a[l][3] == 3 || )
		}
		l++;
	}
}*/
