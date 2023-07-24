# Push_swap
Calculate and display on the standard output the smallest program, made of Push swap language instructions, that sorts the integers received as arguments.

## Evaluation y comprobation

- Print *error* or *OK* or *KO* depending on the case. The **`ARG`** variable is used to pass arguments to the **`push_swap`** and **`checker`** executables.

- Throw in the terminal to check:

`ARG="random values"; ./push_swap $ARG | ./checker $ARG`

OR

- You can set ARG as an environment variable:

`export ARG=”values of choice”`

- Check it after with the command:

`env`

- Execute:

`./push_swap $ARG | ./checker $ARG`

- To count the operations used for sorting:

`./push_swap $ARG | wc -l`

### for memory leaks:

```c
void   ft_leaks(void)
{
    system("leaks -q push_swap");
		atexit(ft_leaks); // this goes into main after variable declerations
}
```
