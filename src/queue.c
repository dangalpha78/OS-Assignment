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
        else if (!q->size){
                q->proc[0] = proc;
                q->size++;
        }
        else {
                int index = q->size;
                while (index > 0 && q->proc[index - 1]->priority > proc->priority){
                        q->proc[index] = q->proc[index - 1];
                        index--;
                }

                q->proc[index] = proc;
                q->size++;
        }
        //printf("helooooooooooo %d\n", q->size);
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        struct pcb_t * result = NULL;
        if (q->proc[0] != NULL){
                result = q->proc[0];

                for (int i = 0; i < q->size - 1; i++){
                        q->proc[i] = q->proc[i + 1];
                }
                q->proc[q->size - 1] = NULL;
                q->size--;

        }
	return result;
}

