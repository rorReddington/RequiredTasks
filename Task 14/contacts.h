#ifndef VECTOR_H_CONTACTS
#define VECTOR_H_CONTACTS

extern FILE *config;

enum Groups
{
	NO_GROUP,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

/* Функция добавления контакта */
void add_contact(char *name, char *phone, int group);

/* Функция удаления контакта */
void remove_contact(char *name);

/* Функция, которая возвращает индекс по которому находится контакт */
int get_index_contact(char *name);

/* Функция изменения имени контакта на заданное */
void change_contact_name(char *old_name, char *new_name);

/* Функция изменения номера у заданного контакта */
void change_contact_phone(char *name, char *new_phone);

/* Функция изменения группы контакта на заданную */
void change_contact_group(char *name, int group);

/* Функция, которая возвращает название группы по номеру */
const char *get_group_name_by_index(int index);

/* Функция, которая возвращает номер группы по имени */
int get_group_index_by_name(char *name);

/* Функция выводит все контакты */
void print_all_contacts();

/* Функция выводит все контакты по заданному имени */
void print_contacts_by_name(char *name);

/* Функция выводит все контакты по заданному номеру */
void print_contacts_by_phone(char *phone);

/* Функция выводит все контакты по заданной группе */
void print_contacts_by_group(int id);

/* Функция, которая записывает контакты в файл */
void write_contacts();

/* Функция, которая читает записанные в файл контакты */
void read_contacts();

#endif // VECTOR_H_CONTACTS