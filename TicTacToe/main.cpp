/*  Author: Brian Gueterman
    Date:   September 5, 2018
    Purpose:Print a playable tic-tac-toe
            game to the console and
            determine winner based on
            inputs
*/

#include <iostream>
#include "tictactoe.cpp"

int main()
{

    in_out("init");                      // initialize board and instructions
    draw_board();

    in_out("place");                     // first turn, no check at end because impossible to win game on first turn
    draw_board();                        // draw the board

    while(game_finished() == false)      // loop through our game until the array is all X's and O's or win condition is met
    {
        in_out("update");
        in_out("place");                 // take user input and update the necessary player_turn and piece_placement values
        draw_board();                    // update board based on current array values
    }

    in_out("winner");
    return 0;
}
