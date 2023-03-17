#include "bitmap.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// display bitmap
void bitmap_display(bit_map_t *bit_map) {
	printf("bit map ==>\n");
	for (int i = 0; i < bit_map->row_size; i++) {
		for (int j = 0; j < bit_map->line_size; j++) {
			printf("%d ", GET_BIT(bit_map->map[i][j / ((sizeof(char) * 8))], j % ((sizeof(char) * 8))));
		}
		printf("\n");
	}
	printf("end\n");
	return ;
}

// destroy
void bitmap_destroy(bit_map_t *bit_map) {
	if (NULL == bit_map) {
		goto DONE;
	}

	if (NULL == bit_map->map) {
		goto DEL;	
	}
	
	for (int i = 0; i < bit_map->row_size; i++) {
		if (NULL != bit_map->map[i]) {
			free(bit_map->map[i]);
			bit_map->map[i] = NULL;
		}
	}

	free(bit_map->map);
	bit_map->map = NULL;

DEL:
	free(bit_map);
	bit_map = NULL;

DONE:
	return;
}

// init
bit_map_t *bitmap_init(int line, int row) {
	bit_map_t *bit_map = NULL;
	bit_map	= (bit_map_t*)malloc(sizeof(bit_map_t));
	if (NULL == bit_map) {
		goto ERR;
	} 
	memset(bit_map, 0, sizeof(bit_map_t));
	
	bit_map->line_size = line;
	bit_map->row_size = row;
	bit_map->map = NULL;
	bit_map->real_line = (bit_map->line_size / (sizeof(char) * 8)) + (bit_map->line_size % (sizeof(char) * 8) != 0 ? 1 : 0);
	bit_map->map = (map_t)malloc(bit_map->row_size * sizeof(bit_line_t));
	if (NULL == bit_map) {
		goto MAP_ROW_ERR;
	}
	memset(bit_map->map, 0, bit_map->row_size * sizeof(bit_line_t));
	
	for (int i = 0; i < bit_map->row_size; i++) {
		bit_map->map[i] = (bit_line_t)malloc(bit_map->real_line);
		if (NULL == bit_map) {
			goto MAP_LINE_ERR;
	 	}
		memset(bit_map->map[i], 0, bit_map->real_line);
 	}
	goto DONE;

MAP_LINE_ERR:
	for (int i = 0; i < bit_map->real_line; i++) {
		if (NULL != bit_map->map[i]) {
			free(bit_map->map[i]);
			bit_map->map[i] = NULL;
		}
	}
	free(bit_map->map);
	bit_map->map = NULL;

MAP_ROW_ERR:
	free(bit_map);

ERR:
	bit_map = NULL;

DONE:
	return bit_map;
}


