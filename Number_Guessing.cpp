#include <Iostream>
#include <ctime>
int main(){
    srand(time(NULL));
    int guess;
    int computer = (rand() % 100) + 1;
    int coba = 0;
    bool running = true;

    std::cout << "**********************************\n";
    std::cout << "  WELCOME TO THE NUMBER GUESSING  \n";
    std::cout << "**********************************\n";
    std::cout << "Computer sudah mendapatkan angkanya ! , coba tebak angka berapa?\n";

    while(running){
        do{
            std::cout << "COBA TEBAK ANGKA BERAPA? (1 - 100) = ";
            std::cin >> guess;
            
        }while(guess > 100 || guess <= 0); //"Looping akan MENGULANG kalau syaratnya BENAR (TRUE), dan akan BERHENTI kalau syaratnya SALAH (FALSE)."
                                           // lalu pakai ATAU, bukan DAN supaya salah 1 aja langsung keulang
        coba++;

        if(guess > computer){
            std::cout << "TERLALU BESAR!!, ";
            coba++;
        }
        else if(guess < computer){
            std::cout << "TERLALU KECIL!!, ";
            coba++;
        }
        else{
            std::cout << "BERHASIL SEBANYAK PERCOBAAN = " << coba << " kali\n";
            std::cout << "***************************************\n";
            running = false;
        }
    }
}