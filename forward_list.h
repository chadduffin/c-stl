#ifndef __FORWARD_LIST__
#define __FORWARD_LIST__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "error.h"
#include "generics.h"

typedef struct FORWARD_LIST FORWARD_LIST;
typedef struct FORWARD_LIST_NODE FORWARD_LIST_NODE;

struct FORWARD_LIST {
  FORWARD_LIST_NODE *head_, *tail_;
};

struct FORWARD_LIST_NODE {
  DATA data_;
  FORWARD_LIST_NODE *next_;
};

void  forward_list_create     (FORWARD_LIST **forward_list);
void  forward_list_delete     (FORWARD_LIST **forward_list, void (*f)(DATA*));

DATA* forward_list_back       (FORWARD_LIST *forward_list);
void  forward_list_clear      (FORWARD_LIST *forward_list, void (*f)(DATA*));
bool  forward_list_empty      (FORWARD_LIST *forward_list);
DATA* forward_list_front      (FORWARD_LIST *forward_list);
void  forward_list_handle     (FORWARD_LIST *forward_list, void (*f)(DATA*));
void  forward_list_merge      (FORWARD_LIST *forward_list_left,
                               FORWARD_LIST *forward_list_right);
void  forward_list_pop_front  (FORWARD_LIST *forward_list);
void  forward_list_push_front (FORWARD_LIST *forward_list, DATA data);
void  forward_list_remove     (FORWARD_LIST *forward_list, DATA data);

#endif // FORWARD_LIST //

