
// TODO: maybe include the type itself in the struct? Maybe as a simple int & then users can simply define compile-time constants?
// ex: USER_PTR = 25, then int type = 25 in the struct, in the source code they'll check list->type == USER_PTR
struct ArrayList {
	unsigned int type_size;
	int items_max_size;
	int items_length;
	void *items;
};

void array_list_add(struct ArrayList *list, int data);

void array_list_print(struct ArrayList *list);

struct ArrayList* array_list_init(int max_size, unsigned int data_type_size, char optional_data[]);

void array_list_delete(struct ArrayList *list);