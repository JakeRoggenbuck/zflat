/**
 * A variably-sized linked list.
 */

#pragma once

struct zf_linked_list;

/**
 * Initialize a new list.
 */
void zfll_init(struct zf_linked_list *);

/**
 * Add an element to the list.
 */
void zfll_add(struct zf_linked_list *, void *);

/**
 * Iterate over a list. The return value is the sum of all calls of the callback
 * function provided.
 */
int zfll_iterate(struct zf_linked_list *, int (*)(void *, void *));

/**
 * Destroy a list.
 */
void zfll_destroy(struct zf_linked_list *);