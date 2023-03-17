#include "bitmap.h"
#include <stdio.h>


int main() {

	bit_map_t *bitmap = bitmap_init(15, 10);
	
	bitmap_set(bitmap, 0, 0, 1);
	bitmap_set(bitmap, 1, 1, 1);
	bitmap_set(bitmap, 2, 2, 1);
	bitmap_set(bitmap, 3, 3, 1);
	bitmap_set(bitmap, 3, 3, 0);

	bitmap_display(bitmap);

	printf("0,0 %d \n", bitmap_get(bitmap, 0, 0));
	printf("1,1 %d \n", bitmap_get(bitmap, 1, 1));
	printf("2,2 %d \n", bitmap_get(bitmap, 2, 2));
	printf("3,3 %d \n", bitmap_get(bitmap, 3, 3));
	printf("4,4 %d \n", bitmap_get(bitmap, 4, 4));

	bitmap_destroy(bitmap);


	return 0;
}

