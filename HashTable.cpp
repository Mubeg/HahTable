#include"HashTable.h"

int main(){	

	int buff_size = 0;
	Buff_elem_t *buff = read_file_to_created_buff(ITABLE_FILE, &buff_size);

	change_ch1_to_ch2_and_count_in_ch_buff(' ', '\0', buff, buff_size);

	int text_size = 0;
	str_ptr text = make_text_must_free(buff, buff_size, &text_size);

	FILE * file = fopen(OTABLE_FILE, "w");
	if(file == nullptr){
		fprintf(stderr, "Not able to open file %s for writing\n", OTABLE_FILE);
		return 1;
	}


	for(int _ = 0; _ >= 0; _++){
		
		Hash_table_t hash_table = {};
		HASH_TABLE_INIT(&hash_table, THE_GREATEST_PRIME_NUMBER);

		for(size_t i = 0; i < text_size; i++){	

			hash_t hash = 0;
			
			#define DEF_HASH(num, name, hash_code) else if(num == _){\
					if(hash_table.hash_name == nullptr){\
						hash_table.hash_name = #name;\
					}\
					hash_code;\
			}

			if(true == false){return 1303;}
			#include"hashes.h"
			
			#undef DEF_HASH

			hash_table_put(&hash_table, text[i].str, hash);
		}

		ready_for_gnu_plot(&hash_table, file);

		hash_table_deinit(&hash_table);
	}

	free(text);
	fclose(file);

	return 0;	
}


bool hash_table_init(Hash_table_t *hash_table, const char name[], const size_t init_table_size /*= HASH_TABLE_INIT_SIZE*/){

	assert(hash_table != nullptr);
	if(init_table_size < 0){
		return false;	
	}

	hash_table->canary1 = CANARY_VALUE;
	
	hash_table->size = init_table_size;

	for(size_t i = 0; i < hash_table->size; i++){
		LIST_INIT(hash_table->data[i]);
	}
	
	
	hash_table->name = name[0] == '&' ? name + 1 : name;

	hash_table->canary2 = CANARY_VALUE;

	//assert(check_list(hash_table, __LOCATION__));
 
	return true;
}


bool hash_table_put(Hash_table_t *hash_table, Elem_t elem, hash_t hash){

	assert(hash_table != nullptr);

	List_t * list = (hash_table->data + hash % THE_GREATEST_PRIME_NUMBER);
 	list -> head == 0 ? (list_add_head(list), list_set(list, list->head, elem)) : list_add_after(list, elem, list->head);
	//assert(check_list(hash_table, __LOCATION__));
 
	return true;
}

void ready_for_gnu_plot(Hash_table_t *hash_table, FILE * file){

	fprintf(file, "%s,", hash_table->hash_name);

	for(int i = 0; i < hash_table->size; i++){
		fprintf(file, "%d,", (hash_table->data + i)->size);
	}
	fprintf(file, "\n");
}

bool hash_table_deinit(Hash_table_t *hash_table){	
	
	for(int i = 0; i < hash_table->size; i++){
		if(!list_deinit(hash_table->data + i)){
			return false;
		}
	}
	return true;
}


