#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef struct { 

	char name[80];
	char phone[12];
	int group;

} Contact;

extern Contact *vector;
extern size_t vec_size;
extern size_t vec_capacity;

void append(Contact value);
void insert(size_t pos, Contact value);
void erase(size_t pos);
void clear_vector();
void reserve(size_t newCap);
void squeeze();

#endif // VECTOR_H_INCLUDED
