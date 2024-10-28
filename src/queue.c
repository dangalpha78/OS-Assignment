#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if (q->size > MAX_QUEUE_SIZE){
                return;
        }
        q->proc[q->size] = proc;
        q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if (!empty(q)){
                struct pcb_t * result = q->proc[0];
                uint32_t highestPriority = result->priority;
                int temp = 0;

                for (int index = 0; index < q->size; index++){
                        if (q->proc[index]->priority < highestPriority){
                                highestPriority = q->proc[index]->priority;
                                result = q->proc[index];
                                temp = index;
                        }
                }

                for (int index = temp; index < q->size - 1; index++){
                        q->proc[index] = q->proc[index + 1];
                }

                q->proc[q->size - 1] = NULL;
                q->size--;

                return result;
        }
	return NULL;
}

