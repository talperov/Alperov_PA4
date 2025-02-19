/*
Name: Tony Alperov

Assignment: Create a fun game called "craps" that is played in casinos and back alleys throughout the world.
I may use suggested functions (recommended) or create my own as needed.

Lab Section: Myles Bridges

Date Started/Attempted: 2/12/25

This is the main.c file
*/

#include "dice.h"

int main(void) {
    double amount = 0.0, wager = 0.0; // Player's bank balance and wager amount
    int rolls = 0, choice = 0, die1 = 0, die2 = 0, sum = 0, result = 0, point = 0;

    srand((unsigned int)time(NULL)); // Seed for random number generator

    do {
        display_menu(); // Display game menu
        choice = get_choice(); // Get user choice

        switch (choice) {
        case 1: // Option to display game rules
            print_game_rules();
            break;
        case 2: // Option to play the game
            amount = get_bank_balance(); // Get the player's initial balance
            printf("Your starting balance: $%.2lf\n", amount);

            while (amount > 0) { // Continue playing while bank balance is positive
                do {
                    wager = get_wager_amount(); // Get wager from user
                    if (!check_wager_amount(wager, amount)) {
                        printf("Invalid wager! Must be within bank balance.\n");
                    }
                } while (!check_wager_amount(wager, amount)); // Ensure valid wager

                die1 = roll_die(); // Roll first die
                die2 = roll_die(); // Roll second die
                sum = calculate_sum_dice(die1, die2); // Calculate sum of dice
                rolls++;

                printf("You rolled %d + %d = %d\n", die1, die2, sum);
                result = is_win_loss_point(sum); // Determine if the player won/lost or has a point

                if (result == 1) { // Player wins instantly
                    printf("You won!\n");
                    amount = adjust_bank_balance(amount, wager, 1);
                }
                else if (result == 0) { // Player loses instantly
                    printf("You lost!\n");
                    amount = adjust_bank_balance(amount, wager, 0);
                }
                else { // Establishes a point and continues rolling
                    point = sum;
                    printf("Point set to %d. Rolling again!\n", point);
                    do {
                        die1 = roll_die(); // Roll dice again
                        die2 = roll_die();
                        sum = calculate_sum_dice(die1, die2);
                        rolls++;
                        printf("You rolled %d + %d = %d\n", die1, die2, sum);
                        result = is_point_loss_or_neither(sum, point); // Check for win/loss or continue rolling
                    } while (result == -1); // Continue until a win or loss

                    amount = adjust_bank_balance(amount, wager, result); // Adjust balance based on result
                }

                chatter_messages(rolls, result, amount + wager, amount); // Display chatter messages
                printf("Current bank balance: $%.2lf\n", amount); // Show updated balance
            }
            break;
        case 3: // Option to exit the game
            printf("Exiting game.\n");
            break;
        }
    } while (choice != 3); // Keep looping until the user chooses to exit

    return 0;
}
