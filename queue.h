#ifndef QUEUE_H
#define QUEUE_H

#include "binary_trees.h"

/* Queue node structure for level-order traversal */
typedef struct queue_node_s
{
    const binary_tree_t *node;
    struct queue_node_s *next;
} queue_node_t;

void enqueue(queue_node_t **queue, const binary_tree_t *node);
const binary_tree_t *dequeue(queue_node_t **queue);

#endif /* QUEUE_H */
