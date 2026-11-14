// First game made by me
#include <iostream>
#include <ctime>

void drawboard(char *spaces)
{
    std::cout << '\n';
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << '\n';
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << '\n';
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << '\n';
    std::cout << "     |     |     \n\n";
}

void playermove(char *spaces, char player)
{
    int number;

    while (true)
    {
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;

        if (number < 1 || number > 9)
        {
            std::cout << "Invalid position! Choose between 1 and 9.\n";
            continue;
        }

        number--;

        if (spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
        else
        {
            std::cout << "Position already occupied! Try again.\n";
        }
    }
}

void computermove(char *spaces, char computer)
{
    int number;

    while (true)
    {
        number = std::rand() % 9;

        if (spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkwinner(char *spaces, char player, char computer)
{
    int winpatterns[8][3] =
        {
            {0, 1, 2},
            {3, 4, 5},
            {6, 7, 8},
            {0, 3, 6},
            {1, 4, 7},
            {2, 5, 8},
            {0, 4, 8},
            {2, 4, 6}};

    for (int i = 0; i < 8; i++)
    {
        int a = winpatterns[i][0];
        int b = winpatterns[i][1];
        int c = winpatterns[i][2];

        if (spaces[a] != ' ' &&
            spaces[a] == spaces[b] &&
            spaces[b] == spaces[c])
        {
            if (spaces[a] == player)
                std::cout << "YOU WIN!\n";
            else
                std::cout << "COMPUTER WINS! YOU LOSE!\n";

            return true;
        }
    }

    return false;
}

bool checktie(char *spaces)
{
    for (int i = 0; i < 9; i++)
    {
        if (spaces[i] == ' ')
        {
            return false;
        }
    }

    std::cout << "IT'S A TIE!\n";
    return true;
}

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    char player, computer;
    bool running = true;

    std::srand(std::time(0));

    std::cout << "Choose (X or O): ";
    std::cin >> player;

    if (player == 'x')
        player = 'X';
    else if (player == 'o' || player == '0')
        player = 'O';

    while (player != 'X' && player != 'O')
    {
        std::cout << "Choose only between X and O: ";
        std::cin >> player;

        if (player == 'x')
            player = 'X';
        else if (player == 'o' || player == '0')
            player = 'O';
    }

    if (player == 'X')
        computer = 'O';
    else
        computer = 'X';

    std::cout << "You are: " << player << '\n';
    std::cout << "Computer is: " << computer << '\n';

    drawboard(spaces);

    while (running)
    {
        playermove(spaces, player);
        drawboard(spaces);

        if (checkwinner(spaces, player, computer))
        {
            running = false;
            break;
        }

        if (checktie(spaces))
        {
            running = false;
            break;
        }

        computermove(spaces, computer);
        drawboard(spaces);

        if (checkwinner(spaces, player, computer))
        {
            running = false;
            break;
        }

        if (checktie(spaces))
        {
            running = false;
            break;
        }
    }

    std::cout << "Thanks for playing!\n";

    return 0;
}
