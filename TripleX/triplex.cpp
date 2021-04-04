#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
    {
        std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
        std::cout << " secure server room...\n Enter the correct code to continue...\n\n";
    }

bool PlayGame(int Difficulty)
{
   PrintIntroduction (Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There is 3 numbers int the code";
    std::cout <<  "\n+ The codes add-up to:" << CodeSum;
    std::cout << "\n+ The codes multpy to give:" << CodeProduct << std::endl;
 
 // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

// Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n You passed level agent, keep going! " << std::endl;
        return true;
    }  
    else
    {
        std::cout << "\n You Lose! " << std::endl;
        return false;
    }
}

int main()
{ 
    srand (time(NULL));  //random based on the time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel) //Loop game untill all levels completed
    {
        std::cout << rand () %10 << "\n";
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discard the buffer
    
        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "You win!!! Now gett out grom here!! \n";

    std::cin.get();
    
    return 0;   
}