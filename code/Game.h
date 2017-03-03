#ifndef GAME_H
#define GAME_H
//comment ý deifne new object with 3 variable, ý set and get of these


using namespace std;
class Game
{
    private:
        int Score;
        int Experience;
        char GameID;


    public:
        Game();
        char GetID();
        int GetScore();
        int GetExperience();
        void SetID(char a);
        void SetScore(int b);
        void SetExperience(int c);



};
    Game::Game(){
        GameID = 'N';
        Score = 1200;
        Experience = 0;
         }

    char Game::GetID(){
        return GameID;
    }

    int Game::GetScore(){
        return Score;

    }
    int Game::GetExperience(){
        return Experience;

    }

    void Game::SetID(char a){
        GameID = a;
    }
    void Game::SetExperience(int b){
        Experience = b;
    }
    void Game::SetScore(int c){
        Score = c;
    }

#endif // GAME_H
