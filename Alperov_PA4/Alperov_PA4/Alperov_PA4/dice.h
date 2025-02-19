/*
Name: Tony Alperov

Assignment: Create a fun game called "craps" that is played in casinos and back alleys throughout the world.
I may use suggested functions (recommended) or create my own as needed.

Lab Section: Myles Bridges

Date Started/Attempted: 2/12/25

This is the dice.h file
*/
#ifndef DICE_H
#define DICE_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // rand(), // srand()
#include <time.h>

void display_menu(void); // shows options of game

int get_choice(); // gathers result of menu

void print_game_rules(void); // Prints out the rules of the game of "craps"

double get_bank_balance(void); // Gets starting bank balance

double get_wager_amount(void);   // - Prompts the player for a wager on a particular roll.The wager is returned.

int check_wager_amount(double wager, double amount); // Checks to see if the player waged money is valid with amount in bank.
															
int roll_die(); // rolls the die

int calculate_sum_dice(int die1, int die2);
// stopped working 2/13/25
// continued again 2/14/25
int is_win_loss_point(int sum);   // determines die if it is a win or loss point

// continued again 2/18/25
int is_point_loss_or_neither(int sum, int point);  // based on previous statement but adds to records
				
double adjust_bank_balance(double amount, double wager_amount, int add_or_subtract);  // adjusts the bank balance

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance); // shows random messages









#endif 