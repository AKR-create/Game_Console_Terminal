#include <iostream>
#include <ctime>
#include <string>
void player_check(std::string &posisi, char player, std::string tebak, int &error);
void hangman(int error);

int main(){
    std::string kata[] = {"gorilla", "kucing", "nyamuk", "beruang", "paus", "kutu"};
    char player;
    int size = sizeof(kata) / sizeof(kata[0]);
    srand(time(NULL));
    int computer = (rand() % size);
    std::string tebak = kata[computer];
    std::string posisi(tebak.length(), '_');
    int error = 0;
    bool run = 1;
    //opening stuff belom
        std::cout << "WELCOME TO THE HANGMAN GAME!!!" << std::endl; 
        std::cout << "       THEME = ANIMAL         " << std::endl;
        hangman(error);

    while(run == 1){
        std::cout << "give me a char (a - z) = ";
        std::cin >> player;

        player = tolower(player);
        player_check(posisi, player, tebak, error);
        std::cout << posisi;
        std::cout << '\n';

        if(posisi == tebak){
            std::cout << "WIN!!" << std::endl;
            run = 0;
        }
        else{
            hangman(error);
        }
    }
    
    return 0;
}
void player_check(std::string &posisi, char player, std::string tebak, int &error){
    bool ditemukan = false; // Awalnya kita anggap belum ketemu
    for(int i = 0; i < tebak.length(); i++){
        if(player == tebak[i]){
            posisi[i] = tebak[i];
            ditemukan = true; // Tandai bahwa kita ketemu minimal satu huruf
        }
    }
    // Sekarang kita baru kasih tahu hasilnya setelah loop benar-benar selesai
    if(ditemukan) {
        std::cout << "BENAR!" << std::endl;
        return;
    } else {
        std::cout << "SALAH!" << std::endl;
        error++;
        return;
        // Di sini nanti kamu bisa panggil fungsi untuk menambah error
    }
}
void hangman(int error){
    switch (error){
    case 0:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    case 1:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "    O     \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    case 2:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "    O     \n";
        std::cout << "    |     \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    case 3:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "    O     \n";
        std::cout << "   /|     \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    case 4:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "    O     \n";
        std::cout << "   /|L    \n";
        std::cout << "          \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    case 5:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "    O     \n";
        std::cout << "   /|L    \n";
        std::cout << "   /      \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    case 6:
        std::cout << "==========\n";
        std::cout << "    |     \n";
        std::cout << "    O     \n";
        std::cout << "   /|L    \n";
        std::cout << "   / ]    \n";
        std::cout << "          \n";
        std::cout << "==========\n";
        break;
    }
}
/* ERROR WHILE DOING = 
1. jika ada huruf double malah gk selesai anjir. ternyata emg salah loopnya wkwk
    di player_check
2. saat & dan * lagi, lupa kalau pointer tu manja parah, beda ama &. kalau pointer dan mau manggil wajib (* nama var)*/