#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "contacts.h"

enum MenuMainItems
{
	MENU_MAIN,
	MENU_ITEM_ADD,
	MENU_ITEM_CHANGE,
	MENU_ITEM_REMOVE,
	MENU_ITEM_DISPLAY,
    MENU_ITEM_FILELOAD,
    MENU_ITEM_FILESAVE,
	MENU_ITEM_CLOSE
};

enum MenuChangeItems
{
	MENU_ITEM_CHANGE_NAME = 1,
	MENU_ITEM_CHANGE_PHONE,
	MENU_ITEM_CHANGE_GROUP
};

enum MenuDisplayItems
{
	MENU_ITEM_DISPLAY_BYNAME = 1,
	MENU_ITEM_DISPLAY_BYPHONE,
	MENU_ITEM_DISPLAY_ALL,
	MENU_ITEM_DISPLAY_ALLFROMGROUP
};

void clear()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void get_string(char* buff, size_t size)
{
	fgets(buff, size, stdin);

	char *pos;
	if ((pos = strchr(buff, '\n')) != NULL)
		*pos = '\0';
}

void display_error(char *text) {

	clear();
	printf("\a%s", text);
	int c = getchar();
}

void change_menu(char* name)
{
	clear();

	printf("\n"
		" Please choose what to change from \"%s\":\n"
		"  1) Change name\n"
		"  2) Change phone\n"
		"  3) Change group\n\n- ", name);

	int item = 0;
	char buf[3];

	get_string(buf, 3);
	sscanf(buf, "%i", &item);

	clear();

	char new_name[80];
	char new_phone[12];
	char new_group[10];

	switch (item)
	{
	case MENU_ITEM_CHANGE_NAME:

		printf("\n - Please enter a new Name: ");
		get_string(new_name, 80);

		change_contact_name(name, new_name);
		break;
	case MENU_ITEM_CHANGE_PHONE:

		printf("\n - Please enter a new phone: ");
		get_string(new_phone, 13);

		change_contact_phone(name, new_phone);
		break;
	case MENU_ITEM_CHANGE_GROUP:

		printf("\n - Please enter a new group: ");
		get_string(new_group, 10);

		change_contact_group(name, get_group_index_by_name(new_group));
		break;
	default:
		break;
	}
	int c = getchar();
}

void display_menu()
{
	clear();

	printf("\n"
		" Please select:\n"
		"  1) Display contact by name\n"
		"  2) Display contact by phone\n"
		"  3) Display all contacts\n"
		"  4) Display all contacts from group\n\n- ");

	int item = 0;
	char buf[3];

	get_string(buf, 3);
	sscanf(buf, "%i", &item);

	clear();

	char name[80];
	char phone[12];
	char group[10];

	switch (item)
	{
	case MENU_ITEM_DISPLAY_BYNAME:

		printf("\n - Please enter a name: ");
		get_string(name, 80);

		print_contacts_by_name(name);
		break;
	case MENU_ITEM_DISPLAY_BYPHONE:

		printf("\n - Please enter a phone: ");
		get_string(phone, 13);

		print_contacts_by_phone(phone);
		break;
	case MENU_ITEM_DISPLAY_ALL:

		clear();

		print_all_contacts();
		break;
	case MENU_ITEM_DISPLAY_ALLFROMGROUP:

		printf("\n - Please enter a group: ");
		get_string(group, 10);

		print_contacts_by_group(get_group_index_by_name(group));
		break;
	default:
		break;
	}
	int c = getchar();
}

void main_menu(short item)
{
	clear();

	char name[80];
	char phone[13];
	char group[10];
    char filename[120];

	switch (item)
	{
	case MENU_MAIN:
		printf("\n"
			" Welcome to Contact Manager!\n"
			" Please select option:\n"
			"  1) Add contact\n"
			"  2) Change contact name/phone/group\n"
			"  3) Remove contact\n"
			"  4) Display\n"
            "  5) Load contacts\n"
            "  6) Save contacts\n"
			"  7) Close the program\n\n- ");
		break;
	case MENU_ITEM_ADD:
		printf("\n Please fill in the details.\n\n");

		printf("  - Name: ");
		get_string(name, 80);

		if (get_index_contact(name) != -1) {
			
			display_error("\n - Error! Contact name is already taken.\n\n - Please press \"ENTER\" for continue...");
			return;
		}

		printf("  - Phone: ");
		get_string(phone, 13);

		printf("  - Group: ");
		get_string(group, 10);

		add_contact(name, phone, get_group_index_by_name(group));
		break;
	case MENU_ITEM_CHANGE:
		
		printf("\n - Please enter a name: ");
		get_string(name, 80);

		if (get_index_contact(name) == -1) {

			display_error("\n - Error! Contact does not exist.\n\n - Please press \"ENTER\" for continue...");
			return;
		}
		change_menu(name);
		break;
	case MENU_ITEM_REMOVE:

		printf("\n - Please enter a name: ");
		get_string(name, 80);

		remove_contact(name);
		break;
    case MENU_ITEM_FILELOAD:
        printf("\n - Please enter a file name: ");
        get_string(filename, 120);
            
        load_contacts(filename);
        break;
    case MENU_ITEM_FILESAVE:
        printf("\n - Please enter a file name: ");
        get_string(filename, 120);
        
        save_contacts(filename);
        break;
	case MENU_ITEM_DISPLAY:
		display_menu();
		break;
	default:
		break;
	}
}


int main(int argc, char* argv[])
{
	int item = 0;
	char buf[3];

	while (item != MENU_ITEM_CLOSE)
	{
		main_menu(MENU_MAIN);

		get_string(buf, 3);
		sscanf(buf, "%i", &item);

		main_menu(item);
	}

	return 0;
}
