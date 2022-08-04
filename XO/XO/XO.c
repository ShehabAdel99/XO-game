#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

bool places_available = true;
bool play_again = false;

struct player {
	unsigned char name[50];
	bool is_x;
	bool is_o;
	bool win;
};

void show_table(char arr[]) {
	printf("-------------\n");
	for (int i = 0; i < 9; i++) {
		printf("| %c ", arr[i]);
		if ((i + 1) % 3 == 0) {
			printf("|\n-------------\n");
		}
	}
}

void show_positions(char arr[]) {
	printf("-------------\n");
	for (int i = 0; i < 9; i++) {
		printf("| %d ", (i+1));
		if ((i + 1) % 3 == 0) {
			printf("|\n-------------\n");
		}
	}
}

char win_condition(char arr[]) {
	if (arr[4] != '-') {
		if (arr[0] == arr[4] && arr[4] == arr[8]) {
			return arr[4];
		}
		else if (arr[2] == arr[4] && arr[4] == arr[6]) {
			return arr[4];
		}
		else if (arr[1] == arr[4] && arr[4] == arr[7]) {
			return arr[4];
		}
		else if (arr[3] == arr[4] && arr[4] == arr[5]) {
			return arr[4];
		}
	}
	else if (arr[2] != '-') {
		if (arr[0] == arr[1] && arr[1] == arr[2]) {
			return arr[2];
		}
		else if (arr[2] == arr[5] && arr[5] == arr[8]) {
			return arr[2];
		}
	}
	else if (arr[6] != '-') {
		if (arr[0] == arr[3] && arr[3] == arr[6]) {
			return arr[6];
		}
		else if (arr[6] == arr[7] && arr[7] == arr[8]) {
			return arr[6];
		}
	}
	else {
		return'-';
	}
}

void get_winner(struct player player_1, struct player player_2) {
	if (win_condition == 'x') {
		if (player_1.is_x) {
			printf("The winner is %s\n", player_1.name);
			player_1.win = true;
			printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
			unsigned int choice;
			do {
				printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
				scanf("%d", &choice);
				if (choice == 1) {
					play_again = true;
					return;
				}
				else if (choice == 2) {
					play_again = false;
					return;
				}
				else {
					printf("Unrecognized choice, Please enter a number as follows.\n");
				}
			} while (choice != 1 && choice != 2);
		}
		else {
			printf("The winner is %s\n", player_2.name);
			player_2.win = true;
			printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
			unsigned int choice;
			do {
				printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
				scanf("%d", &choice);
				if (choice == 1) {
					play_again = true;
					return;
				}
				else if (choice == 2) {
					play_again = false;
					return;
				}
				else {
					printf("Unrecognized choice, Please enter a number as follows.\n");
				}
			} while (choice != 1 && choice != 2);
		}
	}
	else if (win_condition == 'o') {
		if (player_1.is_o) {
			printf("The winner is %s\n", player_1.name);
			player_1.win = true;
			printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
			unsigned int choice;
			do {
				printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
				scanf("%d", &choice);
				if (choice == 1) {
					play_again = true;
					return;
				}
				else if (choice == 2) {
					play_again = false;
					return;
				}
				else {
					printf("Unrecognized choice, Please enter a number as follows.\n");
				}
			} while (choice != 1 && choice != 2);
		}
		else {
			printf("The winner is %s\n", player_2.name);
			player_2.win = true;
			printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
			unsigned int choice;
			do {
				printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
				scanf("%d", &choice);
				if (choice == 1) {
					play_again = true;
					return;
				}
				else if (choice == 2) {
					play_again = false;
					return;
				}
				else {
					printf("Unrecognized choice, Please enter a number as follows.\n");
				}
			} while (choice != 1 && choice != 2);
		}
	}
	else {
		return;
	}
}

void check_available_places(char arr[]) {
	places_available = false;
	for (int i = 0; i < 9; i++) {
		if (arr[i] == '-') {
			places_available = true;
			return;
		}
	}
}

void play(char arr[], struct player player_1, struct player player_2) {
	do {
		check_available_places(arr);
		unsigned int position;
		bool wrong_input = false;
		if (places_available) {
			printf("The game is currently as shown: \n");
			show_table(arr);
			printf("Game positions are like this: \n");
			show_positions(arr);
			printf("%s, Please select a position.\n", player_1.name);
			scanf("%d", &position);
			do {
				if (position < 1 || position > 9) {
					printf("Unrecognized position, Please a correct position.\n");
					scanf("%d", &position);
					wrong_input = true;
				}
				else if (arr[position - 1] != '-') {
					printf("This position is occupied.\nPlease select another one.\n");
					scanf("%d", &position);
					wrong_input = true;
				}
				else {
					wrong_input = false;
				}
			} while (wrong_input);
			if (player_1.is_x) {
				arr[position - 1] = 'x';
			}
			else {
				arr[position - 1] = 'o';
			}
			if (win_condition(arr) != '-') {
				get_winner(player_1,player_2);
				return;
			}
			//////////////////////////////////////////
			check_available_places(arr);
			if (places_available) {
				printf("The game is currently as shown: \n");
				show_table(arr);
				printf("Game positions are like this: \n");
				show_positions(arr);
				printf("%s, Please select a position.\n", player_2.name);
				scanf("%d", &position);
				do {
					if (position < 1 || position>9) {
						printf("Unrecognized position, Please a correct position.\n");
						scanf("%d", &position);
						wrong_input = true;
					}
					else if (arr[position - 1] != '-') {
						printf("This position is occupied.\nPlease select another one.\n");
						scanf("%d", &position);
						wrong_input = true;
					}
					else {
						wrong_input = false;
					}
				} while (wrong_input);
				if (player_2.is_x) {
					arr[position - 1] = 'x';
				}
				else {
					arr[position - 1] = 'o';
				}
				if (win_condition(arr) != '-') {
					get_winner(player_1, player_2);
					return;
				}
			}
			else {
				places_available = true;
			}
		}
		else {
			if (player_1.win ==false && player_2.win==false) {
				printf("It's a draw.\n");
				printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
				unsigned int choice;
				do {
					printf("Do you want to play again?\n	Click (1) for YES.\n	Click (1) for NO.\n");
					scanf("%d", &choice);
					if (choice == 1) {
						play_again = true;
						return;
					}
					else if (choice == 2) {
						play_again = false;
						return;
					}
					else {
						printf("Unrecognized choice, Please enter a number as follows.\n");
					}
				} while (choice != 1 && choice != 2);
			}
			else {
				printf("oops... I don't know what the current situation is. Please restart :(\n");
			}
		}
	} while (places_available);
}



int main() {
	unsigned char arr[9];
	for (int i = 0; i < 9; i++) {
		arr[i] = '-';
	}


	struct player player_1;
	struct player player_2;
	do {
		printf("Player 1, Please enter your name.\n");
		scanf("%50s", player_1.name);
		unsigned int choice = 0;
		do {
			printf("%s, Please enter:\n		(1) if you want to be X.\n		(2) if you want to be O.\n", player_1.name);
			scanf("%d", &choice);
			if (choice == 1) {
				player_1.is_x = true;
				player_1.is_o = false;
				player_2.is_x = false;
				player_2.is_o = true;
			}
			else if (choice == 2) {
				player_1.is_x = false;
				player_1.is_o = true;
				player_2.is_x = true;
				player_2.is_o = false;
			}
			else {
				printf("Unrecognized choice, Please enter a number as follows.\n");
			}
		} while (choice != 1 && choice != 2);
		printf("Player 2, Please enter your name.\n");
		scanf("%50s", player_2.name);
		if (player_2.is_o) {
			printf("%s, You are O.\n",player_2.name);
		}
		else {
			printf("%s, You are X.\n", player_2.name);
		}

		play(arr, player_1, player_2);

	} while (play_again);

	return 0;
}