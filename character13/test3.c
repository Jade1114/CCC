#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Character {
	char *name;
	int level;
	int hp;
} Character;

Character *create_character(const char *name, int level, int hp);

void free_character(Character *Character);

int main(void) {

	Character *hero = create_character("Hero", 1, 100);
	if (hero == NULL) {
		return EXIT_FAILURE;
	}

	free_character(hero);

	return EXIT_SUCCESS;
}

Character *create_character(const char *name, int level, int hp) {
	Character *new_character = (Character *)malloc(sizeof(Character));

	if (new_character == NULL) {
		perror("Failed to allocate memory for new character");
		return EXIT_FAILURE;
	}

	new_character->name = (char *)malloc(strlen(name) + 1);

	if (new_character->name == NULL) {
		perror("Failed to allocate memory for new character");
		free(new_character);
		return EXIT_FAILURE;
	}

	strcpy(new_character->name, name);
	new_character->level = level;
	new_character->hp = hp;

	return new_character;
}

void free_character(Character *Character) {
	if (Character != NULL) {
		free(Character->name);
		free(Character);
	}
}