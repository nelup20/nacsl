
#include <stdlib.h>

int get_array_length(char array[], int array_type_size)
{
	int i = 0;
	
	while (*(array + (i * array_type_size)) != 0){
		i++;
	}
	
	return i;
}