#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "vector.h"
#include "contacts.h"

#define CONFIG_FILE_NAME "data.cfg"

FILE *config;

void strlwr(char *str)
{
	unsigned char *p = (unsigned char *)str;

	while (*p) {
		*p = tolower((unsigned char)*p);
		p++;
	}

	return;
}


void add_contact(char *name, char *phone, int group)
{
	Contact contact;

	strcpy(contact.name, name);
	strcpy(contact.phone, phone);
	contact.group = group;

	append(contact);
}

void remove_contact(char *name)
{
	int index = get_index_contact(name);
	erase(index);
}

int get_index_contact(char *name)
{
	for (size_t i = 0; i < vec_size; i++)
		if (strcmp(vector[i].name, name) == 0)
			return i;

	return -1;
}

void change_contact_name(char *old_name, char *new_name)
{
	int index = get_index_contact(old_name);

	if (get_index_contact(new_name) != -1) {

		printf("\a\n - Error! Contact name is already taken\n");
		return;
	}

	strcpy(vector[index].name, new_name);
}

void change_contact_phone(char *name, char *new_phone)
{
	int index = get_index_contact(name);

	strcpy(vector[index].phone, new_phone);
}

void change_contact_group(char *name, int group)
{
	int index = get_index_contact(name);

	vector[index].group = group;
}

const char *get_group_name_by_index(int index)
{
	switch (index)
	{
		case FAMILY:
			return "family";
		case FRIENDS:
			return "friends";
		case COLLEAGUES:
			return "colleagues";
		default:
			return "no group";
	}
}

int get_group_index_by_name(char *name)
{
	strlwr(name);

	if (strcmp(name, "family") == 0)
		return FAMILY;
	else if (strcmp(name, "friends") == 0)
		return FRIENDS;
	else if (strcmp(name, "colleagues") == 0)
		return COLLEAGUES;
	else
		return NO_GROUP;
}

void print_all_contacts()
{
	printf("\n Your contacts:\n\n");

	if (vec_size == 0) {

		printf("\a - empty!\n");
		return;
	}

	printf(" %3s %-24s %-12s %-10s\n", "ID", "NAME", "PHONE", "GROUP");

	for (size_t i = 0; i < vec_size; i++)
		printf(" %3lu %-24s %-12s %-10s\n", i, vector[i].name, vector[i].phone, get_group_name_by_index(vector[i].group));
}

void print_contacts_by_name(char *name)
{

	if (vec_size == 0) {
		printf("\a - empty!\n");
		return;
	}

	printf("\n");

	for (size_t i = 0; i < vec_size; i++)
		if (strcmp(vector[i].name, name) == 0) {
			printf(" %3s %-24s %-12s %-10s\n", "ID", "NAME", "PHONE", "GROUP");
			printf(" %3lu %-24s %-12s %-10s\n", i, vector[i].name, vector[i].phone, get_group_name_by_index(vector[i].group));
			return;
		}

	printf("\a - There is no such contact\n");
}

void print_contacts_by_phone(char *phone)
{
	printf("\n Your contacts:\n\n");

	if (vec_size == 0) {

		printf("\a - empty!\n");
		return;
	}

	printf(" %3s %-24s %-12s %-10s\n", "ID", "NAME", "PHONE", "GROUP");

	for (size_t i = 0; i < vec_size; i++)
		if (strcmp(vector[i].phone, phone) == 0)
			printf(" %3lu %-24s %-12s %-10s\n", i, vector[i].name, vector[i].phone, get_group_name_by_index(vector[i].group));
}

void print_contacts_by_group(int id)
{
	printf("\n Your contacts:\n\n");

	if (vec_size == 0) {

		printf("\a - empty!\n");
		return;
	}

	printf(" %3s %-24s %-12s %-10s\n", "ID", "NAME", "PHONE", "GROUP");

	for (size_t i = 0; i < vec_size; i++)
		if (vector[i].group == id)
			printf(" %3lu %-24s %-12s %-10s\n", i, vector[i].name, vector[i].phone, get_group_name_by_index(vector[i].group));
}

void write_contacts()
{
	if (vec_size == 0)
		return;

	config = fopen(CONFIG_FILE_NAME, "w");

	if (config == NULL) {

		printf("\n> Error saving data\n\n");
		return;
	}

	char *c;

	// число записываемых байтов
	int size = vec_size * sizeof(Contact);

	// записываем количество структур
	c = (char *)&vec_size;
	for (int i = 0; i < sizeof(int); i++)
	{
		putc(*c++, config);
	}

	// посимвольно записываем в файл все структуры
	c = (char *)vector;
	for (int i = 0; i < size; i++)
	{
		putc(*c, config);
		c++;
	}

	fclose(config);
}

void read_contacts()
{
	config = fopen(CONFIG_FILE_NAME, "r");

	if (config == NULL) {

		printf("\n> Error read data\n\n");
		return;
	}

	char *c;
	int m = sizeof(int);
	int n, i;

	// выделяем память для количества данных
	int *pti = (int *)malloc(m);

	// считываем количество структур
	c = (char *)pti;
	while (m>0)
	{
		i = getc(config);
		if (i == EOF) break;
		*c = i;
		c++;
		m--;
	}

	//получаем число элементов
	n = *pti;

	// выделяем память для считанного массива структур
	Contact * ptr = (Contact *) malloc(n * sizeof(Contact));
	c = (char *)ptr;

	// после записи считываем посимвольно из файла
	while ((i= getc(config))!= EOF)
	{
		*c = i;
		c++;
	}

	for (int k = 0; k<n; k++)
		add_contact((ptr + k)->name, (ptr + k)->phone, (ptr + k)->group);

	free(pti);
	free(ptr);
	fclose(config);
}