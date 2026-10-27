#include <iostream>
#include <ctime>
char playerturn(char player);
int computerturn(int computer);
void winner(char player, int computer);
int main(){

    char player;
    int computer;
    
    std::cout << "***************************************************\n";
    std::cout << "      WELCOME TO THE ROCK-PAPER-SCISSOR GAME       \n";
    std::cout << "***************************************************\n";

    player = playerturn(player);
    computer =  computerturn(computer); //jangan lupa deklarasi pengeluaran nilai function buat siapa
    winner(player, computer);
        
    return 0;
}
char playerturn(char player){ //double check
    do{
        std::cout << "Choose your RPS ! = ";
        std::cin >> player;
        player = tolower(player);
    }while(player != 'r' && player != 's' && player != 'p'); // NGULANG HARUS BENAR, KELUAR LOOP HARUS SALAH (SYARAT)
    
    switch (player){
    case 'r' : std::cout << "You choose rock\n"; break;
    case 's' : std::cout << "You choose scissor\n"; break;
    case 'p' : std::cout << "You choose paper\n"; break;
    }
return player;
}
int computerturn(int computer){

    srand(time(NULL));
    computer = rand() % 3;
    switch (computer)
    {
    case 0 : std::cout << "Computer choose paper\n\n"; break;
    case 1 : std::cout << "Computer choose rock\n\n"; break;
    case 2 : std::cout << "Computer choose scissor\n\n"; break;
    }
    return computer;
}
void winner(char player, int computer){
    if(player == 'r'){
        if(computer == 0){
            std::cout << "********************************\n";
            std::cout << "          YOU LOSE :(         \n";
            std::cout << "********************************\n";
        }
        else if(computer == 1){
            std::cout << "********************************\n";
            std::cout << "          ITS A TIE           \n";
            std::cout << "********************************\n";
        }
        else{
            std::cout << "********************************\n";
            std::cout << "          YOU WIN :)        \n";
            std::cout << "********************************\n";
        }
    }
    else if(player == 'p'){
        if(computer == 0){
            std::cout << "********************************\n";
            std::cout << "          ITS A TIE        \n";
            std::cout << "********************************\n";
        }
        else if(computer == 1){
            std::cout << "********************************\n";
            std::cout << "          YOU WIN :)        \n";
            std::cout << "********************************\n";
        }
        else{
            std::cout << "********************************\n";
            std::cout << "          YOU LOSE :(         \n";
            std::cout << "********************************\n";
        }
    }
    else if(player == 's'){
        if(computer == 0){
            std::cout << "********************************\n";
            std::cout << "          YOU WIN :)        \n";
            std::cout << "********************************\n";
        }
        else if(computer == 1){
            std::cout << "********************************\n";
            std::cout << "          YOU LOSE :(         \n";
            std::cout << "********************************\n";
        }
        else{
            std::cout << "********************************\n";
            std::cout << "          ITS A TIE        \n";
            std::cout << "********************************\n";
        }
    }
}