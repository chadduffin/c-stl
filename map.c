#include "map.h"

void map_create(MAP **map, bool (*cmp)(KEY*, KEY*)) {
  ERROR_NULL(map);
  ERROR_NULL(cmp);

  *map = (MAP*)(malloc(sizeof(MAP)));

  red_black_tree_create(&((*map)->red_black_tree_), cmp);
}

void map_delete(MAP **map) {
  ERROR_NULL(map);
  ERROR_NULL(*map);
  ERROR_NULL((*map)->red_black_tree_);

  red_black_tree_delete(&((*map)->red_black_tree_));

  free(*map);
}

void map_clear(MAP *map) {
  ERROR_NULL(map);
  ERROR_NULL(map->red_black_tree_);

  red_black_tree_clear(map->red_black_tree_->root_);

  map->red_black_tree_->size_ = 0;
  map->red_black_tree_->root_ = &NIL;
}

bool map_empty(MAP *map) {
  ERROR_NULL(map);
  ERROR_NULL(map->red_black_tree_);

  return red_black_tree_empty(map->red_black_tree_);
}

void map_erase(MAP *map, KEY key) {
  ERROR_NULL(map);
  ERROR_NULL(map->red_black_tree_);

  red_black_tree_erase(map->red_black_tree_, key);
}

DATA* map_find(MAP *map, KEY key) {
  ERROR_NULL(map);
  ERROR_NULL(map->red_black_tree_);

  return &(red_black_tree_find(map->red_black_tree_, key)->data_);
}

void map_insert(MAP *map, KEY key, DATA data) {
  ERROR_NULL(map);
  ERROR_NULL(map->red_black_tree_);

  red_black_tree_insert(map->red_black_tree_, key, data);
}

unsigned int map_size(MAP *map) {
  ERROR_NULL(map);
  ERROR_NULL(map->red_black_tree_);

  return red_black_tree_size(map->red_black_tree_);
}

