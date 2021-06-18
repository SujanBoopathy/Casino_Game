#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<unistd.h>
#include<windows.h>
using namespace std;

//casino-royal game class
class casino{
    private:
      int accountBalance,BettingAmount,guess,dice,choice;
      string playerName;
      
    public:
      void welcome();
      void rules();
      void get_player_details();
      void casino_game();
      void player_Betting();
      void game_play();
};


//WELCOME MESSAGE IN HOME PAGE OF THE GAME

void casino::welcome(){
    system("cls");
    cout<<"\n\n";
    cout<<"==================================WELCOME TO CASINO WORLD====================================="<<endl;
    cout<<"Enter the player Name : "<<endl;
    getline(cin,playerName);
    cout<<"Enter the starting balance to play game : "<<endl;
    cin>>accountBalance;
    

}

//RULES FOR CASINO GUESSING GAME

void casino::rules(){
    system("cls");
    cout<<"\n\n\n\n\n=========================  CASINO GUESSING GAME RULES  ========================\n\n\n\n\n\n"<<endl;
    cout<<"\t\t1.Choose a number between 1 to 10"<<endl;
    cout<<"\t\t2.Winner gets 10 times of the money bet"<<endl;
    cout<<"\t\t3.Wrong bet, and you lose the amount you bet "<<endl;
    
    cout<<"\n\n\nYour current balance is : "<<accountBalance<<endl;
    sleep(5);
    system("cls");


}

//GAME PLAY OF CASINO ROYAL GAME 

void casino::player_Betting(){

    
    do{
        cout<<"\n\n\nHey "<<playerName<<" !!!\n\n\nEnter your Betting amount: "<<endl;
        cin>>BettingAmount;
        if(BettingAmount > accountBalance){
            cout<<"Betting amount is greater than current account Balance , re-enter your betting balance  !!!"<<endl;
        }
    }while(BettingAmount > accountBalance);
    cout<<"\n\n";
}

void casino::game_play(){
    do{
        cout<<"Guess the Betting number between 1 - 10 \nEnter your guess :";
        cin>>guess;
        if(guess <=0 || guess >10)
           cout<<"Betting number should be in between 1 and 10 \n Re-enter your guess :"<<endl;
    }while (guess <=0 || guess >10 );

    cout<<"\n\n"; 
    //Random number generator function to generate random guess
    dice=rand()%10 +1;
    
    if(guess == dice){
        cout<<"You are in LUCK !!! you won the amount $ "<<BettingAmount*10<< " /-"<<endl;
        accountBalance+=BettingAmount*10;
    }

    else{
        cout<<"Better LUCK next time !! you lost the amount $ "<<BettingAmount<<"/-"<<endl;
        accountBalance-=BettingAmount;
    }
    cout<<"\n\n";
    cout<<"Winning number was :  "<<dice<<endl;
    cout<<playerName<<" ! you have balance of $ "<<accountBalance<<endl;
    if(accountBalance==0)
       cout<<"you have no money more !!"<<endl;
    
    
    cout<<"\n\n";
    
}


// CASINO GAME CO-ORDINATE METHOD 

void casino::casino_game(){
    this->welcome();
    do{
        this->casino::rules();
        this->casino::player_Betting();
        this->casino::game_play();

        

        cout<<"Do you want to continue (1/0) :"<<endl;
        cin>>choice;

        if(accountBalance==0)
          break;
    }while (choice==1);
    system("cls");
    cout<<"Thank you for playing casino royal game ....\n\nHave a good day "<<endl;   
}

int main(){    
    srand(time(0));
    casino c;
    c.casino_game();
    return 0;
}