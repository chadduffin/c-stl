#ifndef __QUEUE__
#define __QUEUE__

#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "error.h"
#include "generics.h"

typedef struct QUEUE QUEUE;

struct QUEUE {
  LIST *list_;
};

void         queue_create(QUEUE **queue);
void         queue_delete(QUEUE **queue);

DATA*        queue_back(QUEUE *queue);
bool         queue_empty(QUEUE *queue);
DATA*        queue_front(QUEUE *queue);
void         queue_pop(QUEUE *queue);
void         queue_push(QUEUE *queue, DATA data);
unsigned int queue_size(QUEUE *queue);

#endif // QUEUE //
