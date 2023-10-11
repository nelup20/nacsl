
#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"
#include "../util/arrays.h"

void array_list_add(struct ArrayList *list, int data)
{
	int old_items_max_size = list->items_max_size;
	int items_length = list->items_length;
	int type_size = list->type_size;

	if (items_length + 1 > old_items_max_size) {
		// 4x array
		int new_items_max_size = old_items_max_size * 4;
		void* new_items = calloc(new_items_max_size, type_size);
		
		if (new_items != NULL) {
			// Copy old items into new array (memcpy?)
			for (int i = 0; i < old_items_max_size; i++){
				*((int*) ((char*)new_items + (i * type_size))) = *((int*) ((char*)list->items + (i * type_size)));
			}

			list->items_max_size = new_items_max_size;
			list->items = new_items;
		} else {
			// TODO: Retry/Error handling
		}
	}
	
	*((int*) ((char*) list->items + (items_length * type_size))) = data;

	list->items_length = ++items_length;
}

void array_list_print(struct ArrayList *list) 
{
	printf("ArrayList(");
	
	int type_size = list->type_size;
	for (int i = 0; i < list->items_max_size; i++){
		printf("%#010x, ", *((int*) ((char*)list->items + (i * type_size))));
	}
	
	printf(")\n");
}

struct ArrayList* array_list_init(int max_size, unsigned int data_type_size, char optional_data[]) 
{
	if (max_size < 1 || data_type_size == 0) return NULL;
	
	int optional_data_length = optional_data != NULL ? get_array_length(optional_data, data_type_size) : 0;
	
	if (optional_data != NULL && optional_data_length > max_size) return NULL;
	 
	struct ArrayList *array_list = malloc(sizeof(struct ArrayList));
	array_list->items_max_size = max_size;
	array_list->items_length = optional_data_length;
	array_list->type_size = data_type_size;
	array_list->items = calloc(max_size, data_type_size);

	if (optional_data != NULL){
		// TODO: copy
		// array_list->items = optional_data;
	}
	
	return array_list;
}

void array_list_delete(struct ArrayList *list)
{
	free(list->items);
	list->items = NULL;

	free(list);
}