#include "Scoreboard.h"
#include "raylib.h"

Scoreboard::Scoreboard()
{
	
	
}

void Scoreboard::draw()
{
    int i = 0;
    DrawRectangle(1040, 200, 200, 500, WHITE);
    DrawText("Highscores", 1040, 215, 20, BLACK);
    DrawText("-----------", 1040, 235, 20, BLACK);
    std::ifstream score_fileRead("Scoreboard.txt");
    while (std::getline(score_fileRead, scoreString)) {
        DrawText(scoreString.c_str(), 1060, 260 + (20*i), 20, BLACK);
        i++;
    }
    score_fileRead.close();

    

}

void Scoreboard::update()
{
    
    std::ifstream score_fileRead("Scoreboard.txt");
   
    while (std::getline(score_fileRead, scoreString)) {
        scores.push_back(std::stoi(scoreString));
        std::cout << "reading" << std::endl;
    }
    
    score_fileRead.close();

    std::sort(scores.begin(), scores.end(), std::greater<int>());

    scores.erase(std::unique(scores.begin(), scores.end()), scores.end());

    while (scores.size() > 25) {
        scores.pop_back();
    }
        
    std::ofstream score_fileWrite("Scoreboard.txt");
    for (const auto& score : scores) {
        streamOut(score_fileWrite, score);
        std::cout << "writing" << std::endl;
    }
    score_fileWrite.close();
        
    
}

