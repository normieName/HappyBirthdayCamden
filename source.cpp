
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class ConnectThree
{
private:
    char player;
    int position;
    int row;
    int col;

public:
    /* Constructor*/
    ConnectThree()
    {
        this->player = 'X';
        this->position = 0;
        this->row = 0;
        this->col = 0;
    }
    /* Destructor*/
    ~ConnectThree() = default;

    /* This is your game board*/

    vector<vector<char>> gameBoard{
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    /* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    /* This method modifes the game board*/
    void modifyGameBoard(char player, int position)
    {
        // this->row = (position - 1) / 3;
        // this->col = (position - 1) % 3;
        bool illegalMove = checkIllegalMove();

        if (!illegalMove)
        {
            gameBoard[row][col] = player;
        }
    }
    void setPosition(int position)
    {
        this->row = (position - 1) / 3;
        this->col = (position - 1) % 3;
    }
    /* This method gets the player */
    char getPlayer()
    {
        return player;
    }
    /* This method switches the player */
    void setNextPlayer()
    {
        if (player == 'X')
        {
            this->player = 'O';
        }
        else
        {
            this->player = 'X';
        }
    }
    /* This method checks if move is illegal */
    bool checkIllegalMove()
    {
        bool illegalMove = false;

        // check if move has already been made
        if (gameBoard[row][col] == 'X' || gameBoard[row][col] == 'O')
        {
            illegalMove = true;
        }

        // check if chip is below
        if (row < 2)
        {
            if (!(gameBoard[row + 1][col] == 'X' || gameBoard[row + 1][col] == 'O'))
            {
                illegalMove = true;
            }
        }
        return illegalMove;
    }
    /* This method checks if a player has won */
    bool checkWin()
    {
        bool win = false;

        // check for horizontal win
        if (gameBoard[row][0] == player && gameBoard[row][1] == player && gameBoard[row][2] == player)
        {
            win = true;
        }

        // check for diagonal win
        if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player)
        {
            win = true;
        }
        else if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)
        {
            win = true;
        }

        // Check vertical win for all columns
        for (int c = 0; c < 3; c++)
        {
            if (gameBoard[0][c] == player && gameBoard[1][c] == player && gameBoard[2][c] == player)
            {
                win = true;
                break;
            }
        }

        return win;
    }
    /* This method checks if the game is a draw */
    bool checkDraw()
    {
        bool draw = true;

        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                if (gameBoard[i][j] != 'X' || gameBoard[i][j] != 'O')
                {
                    draw = false;
                }
            }
        }
        return draw;
    }
    /* This method checks if the game is over */
    bool checkGameOver()
    {
        bool gameOver = false;

        if (checkWin() || checkDraw())
        {
            gameOver = true;
        }

        return gameOver;
    }
};
int main()
{
    ConnectThree game;

    cout << "Connect 3 :" << endl;
    while (!game.checkGameOver())
    {
        int inputPosition = 0;
        int count = 0;

        game.setNextPlayer();
        game.printGameBoard();
        cout << "Player " << game.getPlayer() << " Enter Position: " << endl;

        while (game.checkIllegalMove() == true)
        {
            if (count > 0)
            {
                cout << "Illegal move. Try again." << endl;
            }
            cin >> inputPosition;
            cin.ignore();
            game.setPosition(inputPosition);
            count++;
        }

        game.modifyGameBoard(game.getPlayer(), inputPosition);

        // error handling
        cerr << game.checkWin() << endl
             << endl;
    }

    if (game.checkWin() == true)
    {
        cout << "Player " << game.getPlayer() << " wins!!!" << endl;
        cout << "GAME OVER" << endl;
    }
    else
    {
        cout << "DRAW!!!" << endl;
        cout << "GAME OVER" << endl;
    }

    return 0;
}