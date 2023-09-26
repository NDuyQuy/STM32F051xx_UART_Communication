#ifndef RING_BUFFER_H // include guard
#define RING_BUFFER_H

// define a type for the ring buffer object
typedef struct {
    char *data; // the data array
    int size; // the size of the array
    int head; // the index of the head element
    int tail; // the index of the tail element
} ring_buffer_t;

// declare the functions for the ring buffer
void ring_buffer_init(ring_buffer_t *buffer, int size); // initialize the buffer with a given size
void ring_buffer_free(ring_buffer_t *buffer); // free the memory allocated for the buffer
int ring_buffer_is_empty(ring_buffer_t *buffer); // check if the buffer is empty
int ring_buffer_is_full(ring_buffer_t *buffer); // check if the buffer is full
void ring_buffer_put(ring_buffer_t *buffer, char c); // put a character into the buffer
char ring_buffer_get(ring_buffer_t *buffer); // get a character from the buffer
void ring_buffer_clear(ring_buffer_t *buffer); // clear the buffer
int ring_buffer_count(ring_buffer_t *buffer);//count the elements in the buffer 

#endif
