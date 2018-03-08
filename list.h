#ifndef __LIST__
#define __LIST__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "generics.h"

typedef struct LIST LIST;
typedef struct LIST_NODE LIST_NODE;

struct LIST {
  LIST_NODE *head_, *tail_;
};

struct LIST_NODE {
  DATA data_;
  LIST_NODE *next_, *prev_;
};

void  list_create     (LIST **list);
void  list_delete     (LIST **list, void (*f)(DATA*));

DATA* list_back       (LIST *list);
void  list_clear      (LIST *list, void (*f)(DATA*));
bool  list_empty      (LIST *list);
DATA* list_front      (LIST *list);
void  list_handle     (LIST *list, void (*f)(DATA*));
void  list_merge      (LIST *list_left, LIST *list_right);
void  list_pop_back   (LIST *list);
void  list_pop_front  (LIST *list);
void  list_push_back  (LIST *list, DATA data);
void  list_push_front (LIST *list, DATA data);
void  list_remove     (LIST *list, DATA data);

#endif // LIST //

