/*
Name: Tony Alperov

Assignment: Create a fun game called "craps" that is played in casinos and back alleys throughout the world.
I may use suggested functions (recommended) or create my own as needed.

Lab Section: Myles Bridges

Date Started/Attempted: 2/12/25

This is the dice.c file
*/


#include "dice.h"

void display_menu(void)
{
	printf("Welcome to Craps!\n");
	printf("1. Print game rules.\n");
	printf("2. Play Craps\n");
	printf("3. Exit game\n");

}

int get_choice(void)
{
	int choice = 0;
	scanf("%d", &choice);

	return choice;
}

int roll_die(void)
{
	return rand() % 6 + 1;
}

void print_game_rules(void)
{
	printf("A.Win instantly if the sum is 7 or 11 on the first roll.\nB.Lose instantly(craps) if the sum is 2, 3, or 12 on the first roll.\nC.If the sum is 4, 5, 6, 8, 9, or 10, that number becomes the point.\nD.The player must roll again until they either match the point(win) or roll a 7 (lose).\n");
}

double get_bank_balance(void)
{
	double amount = 0.0;
	printf("Enter Initial Bank Balance: $");
	scanf("%lf", &amount);

	while (amount <= 0)
	{
		printf("Please try again!!! Enter Initial Bank Balance: $");
		scanf("%lf", &amount);
	}
	return amount;
}

double get_wager_amount(void)
	{
	double wager = 0.0;
	do
	{
		printf("Enter how much you're betting: $");
		scanf("%lf", &wager);

		if (wager <= 0)
		{
			printf("Not allowed! Please enter a signficant amount of wager money: $");
		}
	} while (wager <= 0);

	return wager;
	}

int check_wager_amount(double wager, double amount)
{
	if (wager > 0 && wager <= amount)
	{
		return 1; // This indicates that there is no error running it
	}
	return 0; // This indicates that there is an error when running this
}

int calculate_sum_dice(int die1, int die2)
{
	return die1 + die2;
}
// stopped working 2/13/25
// continued working 2/14/25
int is_win_loss_point(int sum) {
	if (sum == 7 || sum == 11) {
		return 1; //The player wins
	}
	else if (sum == 2 || sum == 3 || sum == 12) {
		return 0; //The player loses
	}
	else {
		return -1; //The point is established
	}
}
int is_point_loss_or_neither(int sum, int point)
{
	if (sum == point) {
		return 1; // The player wins
	}
	else if (sum == 7) {
		return 0; // The player loses
	}
	else {
		return -1; // The point is established and the game continues
	}
}
double adjust_bank_balance(double amount, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1) { 
		amount +=  wager_amount; // Add wager to bank balance (win)
	}
	else if (add_or_subtract == 0) {
		amount -= wager_amount; // Subtract wager from bank balance (loss)
	}
	return amount; // Return updated balance
}
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
	if (number_rolls == 1) printf("Good start!\n"); // compliments
	else if (number_rolls > 5 && number_rolls <= 10) printf("On fire!\n"); // complimnents
	else if (number_rolls > 10) printf("Taking your time, huh?\n"); // teasing comment

	if (win_loss_neither == 1) printf("Keep the momentum!\n"); // encouragement
	else if (win_loss_neither == 0) printf("Let's turn it around!\n"); // uplifting
	else printf("Still in play!\n"); // uplifting

	if (current_bank_balance > initial_bank_balance) printf("You're doing great!\n"); // positive comment
	else printf("Be careful! New balance: $%.2lf\n", current_bank_balance); // warning
}

		
		
		
		

























