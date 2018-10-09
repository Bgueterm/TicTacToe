/*  Author: Brian Gueterman
    Date:   September 5, 2018
    Purpose:Print a playable tic-tac-toe
            game to the console and
            determine winner based on
            inputs
*/
#include <iostream>
using namespace std;

//global variable for easy access
int player_turn = 1;
char player_choice[9] = {'1','2','3','4','5','6','7','8','9'};

//Technically an output, but all it does is draw the board to the screen so it should be okay I think
void draw_board()
{
    //Loop to print each row of the board
    for(int i = 0; i < 9; i+=3)
    {
        cout << " " << player_choice[i] << " | " << player_choice[(i+1)] << " | " << player_choice[(i+2)] << '\n';
        if(i < 6)
        {
            cout << "---+---+---" << '\n';
        }
    }
}

//handles all other basic input and output operations
void in_out(string choice)
{
    int piece_placement = 0;//Where they want to put their piece
    char x_or_o = 'n'; //set to n to initialize

    if(choice == "init")
    {
        cout << "The rules of the game are simple: \nFirst, select the place you want to put a piece by typing a number 1 through 9 \nNext, type either X or O to place a piece, depending on your turn.\n" << '\n';
    }
    else if(choice == "update")
    {
        cout << '\n' << "It is now player " << player_turn << "'s turn." << '\n';
    }
    else if(choice == "place")
    {
        cout << '\n' << "Player " << player_turn << '\n' << "Where do you want your piece?: ";
        cin >> piece_placement;

        //Check to see if the player picked a legal spot
        if(piece_placement == 1 || piece_placement == 2 || piece_placement == 3 ||
                piece_placement == 4 || piece_placement == 5 || piece_placement == 6 ||
                piece_placement == 7 || piece_placement == 8 || piece_placement == 9)
        {
            //check to see if there's something there already
            if(player_choice[(piece_placement-1)] == 'X' || player_choice[(piece_placement-1)] == 'O')
            {
                cout << '\n' << "Space already taken, turn forfeit" << '\n';
                if(player_turn == 1)
                {
                    player_turn = 2;
                }
                else
                {
                    player_turn = 1;
                }
            }
            else //the space is empty so populate it
            {
                cout << "What are you placing?: ";
                cin >> x_or_o;

                if(player_turn == 1) // player 1's turn conditions
                {
                    if(x_or_o == 'x' || x_or_o == 'X')
                    {
                        cout << '\n' << "Piece placed" << '\n' << '\n';
                        player_choice[(piece_placement - 1)] = toupper(x_or_o);
                        player_turn = 2;
                    }
                    else
                    {
                        cout << '\n' << "Incorrect piece, turn forfeit" << '\n';
                        player_turn = 2;
                    }
                }
                else if(player_turn == 2) // player 2's turn conditions
                {
                    if(x_or_o == 'o' || x_or_o == 'O')
                    {
                        cout << '\n' << "Piece placed" << '\n';
                        player_choice[(piece_placement - 1)] = toupper(x_or_o);
                        player_turn = 1;

                    }
                    else
                    {
                        cout << '\n' << "Incorrect piece, turn forfeit" << '\n';
                        player_turn = 1;
                    }
                }
            }
        }
        else // the input was not an expected or acceptable value
        {
            cout << '\n' << "That is not a valid choice, turn forfeit" << '\n';
            if(player_turn == 1)
            {
                player_turn = 2;
            }
            else
            {
                player_turn = 1;
            }
        }
    }
    else if(choice == "winner")
    {
        if(player_turn == 3) // condition for when game is a draw
        {
            cout << '\n' << "!--BETTER LUCK NEXT TIME--!\nGAME IS A DRAW" << '\n';
        }
        else // Because of how I track the player_turn, I have to invert the values before printing to console
        {
            if(player_turn == 1)
            {
                player_turn = 2;
            }
            else if(player_turn == 2)
            {
                player_turn = 1;
            }
            cout << '\n' << "!--CONGRATULATIONS--!\nTHE WINNER IS: Player " << player_turn;
        }
    }
}

// This should return true or false depending on the outcome of each turn
bool game_finished()
{
    char compare = 'X';
    for(int i = 0; i < 2; i++)
    {
        // The worlds absolute BEST LOOKING end-game comparison check that isn't gross looking whatsoever.  Tests all game-win conditions.
        if(player_choice[0] == compare && player_choice[1] == compare && player_choice[2] == compare ||
                player_choice[3] == compare && player_choice[4] == compare && player_choice[5] == compare ||
                player_choice[6] == compare && player_choice[7] == compare && player_choice[8] == compare ||
                player_choice[0] == compare && player_choice[3] == compare && player_choice[6] == compare ||
                player_choice[1] == compare && player_choice[4] == compare && player_choice[7] == compare ||
                player_choice[2] == compare && player_choice[5] == compare && player_choice[8] == compare ||
                player_choice[0] == compare && player_choice[4] == compare && player_choice[8] == compare ||
                player_choice[2] == compare && player_choice[4] == compare && player_choice[6] == compare)
        {
            return true; //if a win condition is met, end the game.
        }
        compare = 'O'; //after testing every X, test every O on the board
    }
    // Additional check for if the board is full
    if(player_choice[0] == '1' || player_choice[1] == '2' || player_choice[2] == '3' ||
            player_choice[3] == '4' || player_choice[4] == '5' || player_choice[5] == '6' ||
            player_choice[6] == '7' || player_choice[7] == '8' || player_choice[8] == '9')
    {
        return false; // The board still has empty spots, so keep going
    }
    player_turn = 3; // our board is full so game is over and a draw
    return true;
}
