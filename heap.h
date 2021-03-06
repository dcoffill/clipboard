/*
 * Copyright 2014 David Coffill
 * Licensed under the terms of the GPLv2
 */

#ifndef HEAP_H
#define HEAP_H
#include <linux/mutex.h>
#include <linux/sched.h>

struct heap
{
	char **data;
	int size;
	int end; /* index of last occupied place in heap */
	struct mutex lock;
	wait_queue_head_t read_queue;
};

struct heap *init_heap(int size);
void free_heap(struct heap *heap);

void heap_insert(struct heap *heap, char *address);
void bubble_up(struct heap *heap, int position);
void bubble_down(struct heap *heap, int position);
int parent(int position);
int left(int position);
int right(int position);
char *delete_min(struct heap *heap);

#endif
