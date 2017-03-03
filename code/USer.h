#ifndef USER_H
#define USER_H
#include<Game.h>

// these object uses game object to define each users games and game statistics

using namespace std;

class User
{
    private:
        Game Game_Array[5];
        int User_ID;
        int number_of_games = 0;

    public:
        User();
        void Add_Game(char game);
        void Add_Existing_Game(Game a);
        void AssignID(int ID);
        void Get_Game_Data(char game_id,int *score,int *experience);
        void putingame(char a, int b, int c);
        int checkGame(char a);

};
    User::User(){ User_ID = 100;
    }

    int User::checkGame(char a){
        int j = 0;
        int i=0;


        for(int j = 0 ; j<5 ; j++){

            if(Game_Array[j].GetID() == a)
            {
                i = 1;

                 break;
            }




            }




    return i;
    }



    void User::Add_Game(char a){

        for(int j = 0 ; j<5; j++){
        if(Game_Array[j].GetID() == 'N' ) {

            Game_Array[j].SetID(a);
            number_of_games++;
            break;
        }

        }

    }



    void User::putingame(char a, int b, int c){
        for(int j = 0 ; j<5; j++){

                if(Game_Array[j].GetID() == a ) {


                 Game_Array[j].SetExperience(c);
                 Game_Array[j].SetScore(b);
                 //cout<<Game_Array[j].GetID()<<" "<<Game_Array[j].GetExperience()<<" "<<Game_Array[j].GetScore()<<endl;
                    break;
        }
        }
        }


        void User :: Add_Existing_Game(Game a){
       for(int i=0;i<5;i++)
     {
         if(Game_Array[i].GetID()=='N')
            {
               Game_Array[i]=a;
                break;
            }

     }

    }



    void User::AssignID(int ID){
        User_ID = ID;

    }



void User::Get_Game_Data(char game_id,int *score,int *experience)
 {
    int i=0;
    while(i<5)
    {
        if(Game_Array[i].GetID()==game_id)
        {
            *score=Game_Array[i].GetScore();
            *experience=Game_Array[i].GetExperience();

        }
        i=i+1;
    }
 }



#endif // USER_H

