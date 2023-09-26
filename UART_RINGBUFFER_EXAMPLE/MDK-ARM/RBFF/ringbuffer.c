#include "ringbuffer.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a macro for incrementing an index modulo the size
#define RING_BUFFER_INC(index, size) (((index) + 1) % (size))
static ring_buffer_t gRingBuffer;
// initialize the buffer with a given size
void ring_buffer_init(ring_buffer_t *buffer, int size) {
    buffer->data = malloc(size * sizeof(char)); // allocate memory for the data array
    buffer->size = size; 
    buffer->head = 0; 
    buffer->tail = 0; 
}

// free the memory allocated for the buffer
void ring_buffer_free(ring_buffer_t *buffer) {
    free(buffer->data); // free the data array
    buffer->data = NULL; 
    buffer->size = 0;
    buffer->head = 0;
    buffer->tail = 0;
}

// check if the buffer is empty
int ring_buffer_is_empty(ring_buffer_t *buffer) {
    return (buffer->head == buffer->tail); // return true(1) if the head and tail are equal
}

// check if the buffer is full
int ring_buffer_is_full(ring_buffer_t *buffer) {
    return (RING_BUFFER_INC(buffer->tail, buffer->size) == buffer->head); // return true if incrementing the tail modulo the size equals the head
}

// put a character into the buffer
void ring_buffer_put(ring_buffer_t *buffer, char c) {
    if (!ring_buffer_is_full(buffer)) { // if the buffer is not full
        buffer->data[buffer->tail] = c; // store the character at the tail position
        buffer->tail = RING_BUFFER_INC(buffer->tail, buffer->size); // increment the tail modulo the size
    }
}

// get a character from the buffer
char ring_buffer_get(ring_buffer_t *buffer) {
    char c = '\0'; // the character to return
    if (!ring_buffer_is_empty(buffer)) { // if the buffer is not empty
        c = buffer->data[buffer->head]; // get the character from the head position
        buffer->head = RING_BUFFER_INC(buffer->head, buffer->size); // increment the head modulo the size
    }
    return c;
}

// clear the buffer
void ring_buffer_clear(ring_buffer_t *buffer) {
    memset(buffer->data, '\0', buffer->size); // fill the data array with '\0'
    buffer->head = 0; // set the head index to zero
    buffer->tail = 0; // set the tail index to zero
}

//count buffer element
int ring_buffer_count(ring_buffer_t *buffer){
	int count =0; 
	int index = buffer->head; 
	while(index!=(buffer->tail)){
		count++;
		index = ((index+1)%(buffer->size)); 
	} 
	return count; 
}

