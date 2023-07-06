# push_swap
Calculate and display on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.
```


'''

'''

```
Now comes the fun part, for the radix algorithm we use 3 functions:

- A function to get the maximum sized index
- A function to get the number of bits that we are going to check
- The radix function

This function searches for the maximum sized index and returns it

```c
int	get_max_index(t_list **lst)
{
	t_list	*head;
	int	max;

	head = *lst;
	max = head->index;
	while (head->next)
	{
		if (max < head->next->index)
			max = head->next->index;
		head = head->next;
	}
	return (max);
}
```

The second necessary function calculates the number of bis, for example if there are 10 numbers, the maximum index is 10, this in binary is 1010 so = 4 bits.

```c
int	get_n_bits(t_list **lst)
{
	int	index;
	int	i;

	i = 10;
	index = get_max_index(lst);
	while (i > 0)
	{
		if ((index >> i & 1) == 0)
			i--;
		else
			break ;
	}
	return (i);
}
```

The most important push swap function is radix, now radix, checks each bit and takes action, if it detects a 1 it does pb else it does ra and when we have done it with every index, it does pa (if there are any values in stack b)

```c
void	radix(t_list **a, t_list **b)
{
	int	n_bits = get_n_bits(a);
	int	i;
	int	index_ct;
	t_list	*stack;

	i = 0;
	index_ct = 0;
	if (is_ordered(a))
		return ;
	while (i < n_bits)
	{
		stack = *a;
		while (index_ct <= get_max_index(a))
		{
			if ((stack->index >> i & 1) == 0)
				pb(a, b);
			else if ((stack->index >> i & 1) == 1)
				ra(a);
			index_ct++;
		}
		while ((*b))
		{
			pa(a, b);
			(*b) = (*b)->next;
		}
		index_ct = 0;
		i++;
	}
}
```

As you can see, we first take the number of bits to determine how many times we will loop thtough, then