#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vector.h"

Contact *vector = 0;
size_t vec_size = 0;
size_t vec_capacity = 0;

void reserve(size_t newCap)
{
	if (newCap > vec_capacity)
	{
		vec_capacity = (vec_capacity == 0) ? 1 : vec_capacity;

		while (newCap > vec_capacity)
			vec_capacity <<= 1;

		if (vector == 0)
			vector = (Contact *)malloc(vec_capacity * sizeof(Contact));
		else
			vector = (Contact *)realloc((void *)vector, vec_capacity * sizeof(Contact));
	}
}

void append(Contact value)
{
	reserve(vec_size + 1);

	vector[vec_size] = value;

	vec_size++;
}

void insert(size_t pos, Contact value)
{
	assert(pos < vec_size);

	reserve(vec_size + 1);

	for (int i = vec_size; i > pos; i--)
		vector[i] = vector[i - 1];

	vector[pos] = value;

	vec_size++;
}

void erase(size_t pos)
{
	assert(pos < vec_size);

	for (int i = pos; i < vec_size; i++)
		vector[i] = vector[i + 1];

	vec_size--;
}

void clear_vector()
{
    if (vec_size == 0)
        return;
    
    free(vector);
    vector = 0;
    vec_size = 0;
    vec_capacity = 0;
    
    vec_size--;
}

void squeeze()
{
	if (vector == 0)
		return;

	if (vec_size == 0)
	{
		free(vector);
		return;
	}

	vector = (Contact *)realloc((void *)vector, vec_size * sizeof(Contact));
	vec_capacity = vec_size;
}
