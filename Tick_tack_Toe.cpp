#include <iostream>
#include <ctime>
void game_board(std::string *space);
void choose_player(std::string *space, int player);
void computer(std::string *space, int computer_choice, int player);
int check_winner(std::string *space, int computer, int player, int size);
int main(){
    srand(time(NULL));
    std::string space[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
    int player; // lambang X
    int computer_choice = (rand() % 9) + 1; // lambang O
    int size = sizeof(space) / sizeof(space[0]);
    bool run = 1;

        std::cout << "----------------------------" << '\n';
        std::cout << "WELCOME TO THE TICK-TACK-TOE" << '\n';
        std::cout << "----------------------------" << '\n';
        game_board(space);
        std::cout << '\n';
    while(run == 1){
        std::cout << "Choose your number to place! = ";
        std::cin >> player;
        player--;
        choose_player(space, player);
        game_board(space);
        computer(space, computer_choice, player); //gk boleh sama nama var dan function. atau nggk ewror
        if(check_winner(space, computer_choice, player, size) == 1){
            std::cout << "YOU WIN!";
            run = 0;
        }
        if(check_winner(space, computer_choice, player, size) == -1){
            std::cout << "YOU LOSE";
            run = 0;
        }
        if(check_winner(space, computer_choice, player, size) == 0){
            continue;
        }
    }
    
    return 0;
}
void game_board(std::string *space){
    std::cout << "----------------" << '\n';
    std::cout << "| " << space[0] << " | " << space[1] << " | " << space[2] << " |" << '\n';
    std::cout << "----------------" << '\n';
    std::cout << "| " << space[3] << " | " << space[4] << " | " << space[5] << " |" << '\n';
    std::cout << "----------------" << '\n';
    std::cout << "| " << space[6] << " | " << space[7] << " | " << space[8] << " |" << '\n';
    std::cout << "----------------" << '\n';
}
void choose_player(std::string *space, int player){
    if(player >= 0 && player < 9){
        space[player] = "X";
    }
}
void computer(std::string *space, int computer_choice, int player){
    bool run = 1;
    while(run){
        if(space[computer_choice] == " " && computer_choice != player){
            space[computer_choice] = "O";
            run = 0;
        }
        else{
            computer_choice = (rand() % 9);
        }
    }
}
int check_winner(std::string *space, int computer, int player, int size){ //lanjutin lagi pls. gua muak
    for (int i = 0; i < size - 1; i++){
        if((space[0] != " ") && space[0] == space[1] && space[1] == space[2]){
            if(space[0] == "X"){
                return 1;
            }
            else if(space[0] ==  "O"){
                return -1;
            }
        }
    }
    return 0;
}
