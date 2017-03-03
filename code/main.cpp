#include <iostream>
#include<USer.h>
#include<Game.h>
#include<math.h>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sstream>

using namespace std;

    void Play_game(User *user_1a, User *user_2a, User *user_3a){
    User user_1,user_2;
    int Si = -1, Sj = -1;
    int Ei, Ej;
    int first_id;
    int second_id;
    char game_id;
    float Pi,Pj;
    string line;
    int flag1=0,flag2=0, flag3=0;
    cout<<"lets play a game :) "<<endl;

    while(flag1==0)
    {


    cout<<"enter first users ID"<<endl;
    cin>>line;
    stringstream ss(line);
    ss>>first_id;

    if(first_id == 101)
        {flag1=1;
          user_1=*user_1a;  }
     else if(first_id == 102)
            {flag1=1;
            user_1=*user_2a;}
    else if(first_id == 103)
         {flag1=1;
         user_1=*user_3a;}
         else
    {
        cout<<line<<" is not a valid ID"<<endl;
        flag1=0;
    }

    }

    while(flag2==0)
    {


    cout<<"enter second users ID"<<endl;
    cin>>line;
    stringstream ss2(line);
    ss2>>second_id;

    if(second_id == 101)
        {flag2=1;
          user_2=*user_1a;  }
     else if(second_id == 102)
            {flag2=1;
            user_2=*user_2a;}
    else if(second_id == 103)
         {flag2=1;
         user_2=*user_3a;}
    else
    {
        cout<<line<<" is not a valid ID"<<endl;
        flag2=0;
    }

    }

    while(flag3==0){
     cout<<"Enter a valid game ID"<<endl;
     cin>> line;
     stringstream ss3(line);
     ss3>>game_id;


     if(user_1.checkGame(game_id) && user_2.checkGame(game_id))
        {flag3=1;}
     else
        flag3=0;
        int asd=-1;
        if(!user_1.checkGame(game_id)){
            cout<<first_id<<" does not have this game"<<endl;
            }
         if(!user_2.checkGame(game_id)){
            cout<<second_id<<" does not have this game"<<endl;
            }







    }


    user_1.Get_Game_Data(game_id,&Si,&Ei);
    user_2.Get_Game_Data(game_id,&Sj,&Ej);
    float deltap;

    deltap = ((float)Si - (float)Sj)/1000.0;
    cout<<deltap<<endl;
    Pi = (((0.8*deltap)+1)/2)*100;
    Pj = 100-Pi;
    cout<<"Chance of first player is :";
    cout<<Pi<<endl;
    cout<<"Chance of second player is : ";
    cout<<Pj<<endl;

    int v1;

    srand((unsigned)time(0));
    v1 = (rand()%100)+1;

    //cout<<"chance factor"<<" "<<v1<<endl;
    // if chance factor is bigger thar first users probablity 2 user wins.


    int Sai;
    int Saj;
    float c = 0.2;
    int nPi = (int)Pi;
    int nPj = 100-nPi;

    if(v1<nPi){
        //first player wins
        Sai = Si +((2000.0-Si)/1000.0)*(Sj-1000.0)*c;
        Saj = Sj -((2000.0-Si)/1000.0)*(Sj-1000.0)*c;
        cout<<"user "<<first_id<<" wins"<<endl;
        }

    else if(v1>nPi){
        //second player player wins
        Sai = Si -((2000.0-Sj)/1000.0)*(Si-1000.0)*c;
        Saj = Sj +((2000.0-Sj)/1000.0)*(Si-1000.0)*c;
        cout<<"user "<<second_id<<" wins"<<endl;
        }


            //cout<<"assdfg"<<endl;
            //cout<<Sai<<"    "<<Ei<<endl;
        user_1.putingame(game_id, Sai, Ei);




        user_2.putingame(game_id, Saj, Ej);

    cout<<"old score of player 1: "<<Si<<endl;
    cout<<"new score of player 1: "<<Sai<<endl;
    cout<<"old score of player 2: "<<Sj<<endl;
    cout<<"new score of player 2: "<<Saj<<endl;

    if(first_id == 101)
        {  *user_1a=user_1;  }
     else if(first_id == 102)
            {*user_2a=user_1;}
    else if(first_id == 103)
         {*user_3a=user_1;}

    if(second_id == 101)
        {  *user_1a=user_2;  }
     else if(second_id == 102)
            {*user_2a=user_2;}
    else if(second_id == 103)
         {*user_3a=user_2;}


    }


    void Show_Players(User user_1,User user_2,User user_3){

    Game game_1, game_2, game_3;
    char gameID;
    int x,y,z,k,l;
    cout<<"please enter valid game ID(example games A,B,C)"<<endl;
    cin >> gameID;
    cout<< gameID<<endl;
    //if(gameID == 'A'){
     //   cout<<"reis"<<endl;}
    x = user_1.checkGame(gameID);
    //cout<<"x"<<x<<endl;
    y = user_2.checkGame(gameID);
    z = user_3.checkGame(gameID);

        cout<<"ID"<<"        "<< "Score" <<"      "<< "expereience"<< endl;
    if (x == 1){
        user_1.Get_Game_Data(gameID,&k,&l);
        cout<<101<<"       "<<k<<"           "<<l<<endl;
    }
    if (y == 1){
        user_2.Get_Game_Data(gameID,&k,&l);
        cout<<102<<"       "<<k<<"           "<<l<<endl;
    }
    if (z == 1){
        user_3.Get_Game_Data(gameID,&k,&l);
        cout<<103<<"       "<<k<<"           "<<l<<endl;
    }
   }










    void add_newly_game(User *user_1,User *user_2,User *user_3){
    User a,b,c;
    a=*user_1;
    b=*user_2;
    c=*user_3;
    cout<< "please enter your ID"<< endl;
    int userID,k,l;
   // cin>>userID;
    //cout<< endl;
    int flag=0;
    while(flag == 0){
    string line;
    cin>>line;
    stringstream ss(line);
    ss>>userID;

// I miss wrong game ID situations but ý could it with string method, but ý dont have enough time for that

    if(userID == 101){
        char newGame;
        cout<<"please enter game ID"<<endl;
        cin>>newGame;
        cout << endl;
        flag = 1;
        a.Add_Game(newGame);
        a.Get_Game_Data(newGame,&k,&l);
        cout<<"game "<<" "<< newGame<< " is added "<< userID<<endl;

    }
    else if(userID == 102){
        char newGame;
        cout<<"please enter game ID"<<endl;
        cin>>newGame;
        cout << endl;
        flag = 1;
        b.Add_Game(newGame);
        b.Get_Game_Data(newGame,&k,&l);
        cout<<"game "<< newGame<< " is added "<< userID<<endl;

    }
    else if(userID == 103){
        char newGame;
        cout<<"please enter game ID"<<endl;
        cin>>newGame;
        cout << endl;
        flag = 1;
        c.Add_Game(newGame);
        c.Get_Game_Data(newGame,&k,&l);
        cout<<"game "<< newGame<< " is added "<< userID<<endl;

        }
    else{
        cout<< "wrong ID is pushed, try again"<<endl;
        flag = 0;
    }
    }
    *user_1=a;
    *user_2=b;
    *user_3=c;
    }

    int main()
{
    cout<<"Welcome to gamers database and match simulation"<<endl;


    User user_1, user_2, user_3;
    Game game_1, game_2, game_3;
    User user[10];

    user_1.AssignID(101);
    user_2.AssignID(102);
    user_3.AssignID(103);

    char C,B,A,D,E,newGame;
    user_1.Add_Game('C');

    user_1.putingame('C',1412,34);

    user_1.Add_Game('A');

   user_1.putingame('A',1630,14);

    int k,l;



    user_1.Add_Game('B');
    user_1.putingame('B',1080,2);

    user_2.Add_Game('A');

    user_2.putingame('A',1570,23);

    user_2.Add_Game('C');
    user_2.putingame('C',1708,11);

    user_3.Add_Game('B');
    user_3.putingame('B',1886,60);

        user[0] = user_1;
        user[1] = user_2;
        user[2] = user_3;


        while(1){
            string line;

        cout<<"enter function number"<<endl;
        cout<<"1- Display users having same game"<<endl;
        cout<<"2- simulate a match"<<endl;
        cout<<"3- Add new game "<<endl;

        int select,flag=0;
        while(flag==0)
        {


        cin>>line;
        stringstream ss(line);
        ss>>select;
        if(select == 1){
          Show_Players(user[0],user[1],user[2]);
          flag=1;

        }
        else if(select == 2){
            Play_game(&user[0],&user[1],&user[2]);
            flag=1;
        }
        else if(select == 3)
        {
            add_newly_game(&user[0], &user[1], &user[2]);
            flag=1;

        }
        else{
            cout<<line<<" is not a valid number"<<endl;
            flag=0;


        }

        }

        }
    return 0;
}


// i could not implement ESC command.

