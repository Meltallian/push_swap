#define ERROR_MODE (0)
#define VALUE_MODE (1)

typedef struct s_data {
	int mode; //0 ou 1
	int value; //long value
} t_data;



int main(void){
	t_data data[2];
	data[0].mode = ERROR_MODE;
	data[0].value = 20202020;

	data[1].mode = VALUE_MODE;
	data[1].value = 12;



	init_stack(&stackA, values, VALUE_MODE);
	init_stack(&stackB, NULL, ERROR_MODE);
}

init_stack(t_data *pdata, int mode){
}

//init_stacks -> init_stackA + init_stackB



