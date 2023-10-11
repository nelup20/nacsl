
#include <stdlib.h>
#include <stdio.h>
#include "data_structures/array_list.h"

int main() 
{
	struct ArrayList *my_list = array_list_init(5, sizeof(long), NULL);
	
	printf("Old length: %d\n", my_list->items_length);
	printf("Old max_size: %d\n", my_list->items_max_size);

	for (int i = 1; i < 20; i++) {
		array_list_add(my_list, i*i);
	}
	
	printf("New length: %d\n", my_list->items_length);
	printf("New max_size: %d\n", my_list->items_max_size);

	array_list_print(my_list);
	
	array_list_delete(my_list);
	my_list = NULL;

	return 0;
}
