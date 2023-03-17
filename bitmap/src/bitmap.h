#ifndef __BITMAP_H__
#define __BITMAP_H__

// bit operate macro
#define SET_BIT(x, n) ( x = ( x | ( 0x1 << n ) ) )
#define CLE_BIT(x, n) ( x = ( x & ~( 0x1 << n ) ) )
#define GET_BIT(x, n) ( (x >> n) & 0x1 )

// map struct
typedef char* bit_line_t;
typedef bit_line_t* map_t;

typedef struct {
	map_t map;
	int line_size;
	int row_size;
	int real_line;
} bit_map_t;


// get
static inline int bitmap_get(bit_map_t *bit_map, int row, int line) {
	return GET_BIT(bit_map->map[row][line / ((sizeof(char) * 8))], line % ((sizeof(char) * 8)));
}

// set 
static inline void bitmap_set(bit_map_t *bit_map, int row, int line, int val) {
	if (0 != val) {
		SET_BIT(bit_map->map[row][line / ((sizeof(char) * 8))], line % ((sizeof(char) * 8)));
	} else {
		CLE_BIT(bit_map->map[row][line / ((sizeof(char) * 8))], line % ((sizeof(char) * 8)));
	}
	return ;
}


bit_map_t *bitmap_init(int line, int row);
void bitmap_destroy(bit_map_t *bit_map);
void bitmap_display(bit_map_t *bit_map);

#endif //__BITMAP_H__
