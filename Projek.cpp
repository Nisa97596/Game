#include <iostream> // Preprosesor untuk memasukkan file
#include <string> // Digunakan untuk tipe data string
#include <cstdlib> // header yg menyediakan fungsi dengan tujuan umum
#include <ctime> // header untuk memanipulasi waktu
using namespace std;
void rules();
int main()
{
	string playerName;
    int balance; // menyimpan saldo pemain
    int bettingAmount;
    int guess;
    int dice; // menyimpan nomor acak
    char pilih;
    srand(time(0)); // "Seed" generator acak
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\n\nMasukkan Namamu : ";
    getline(cin, playerName);
    cout << "\n\nMasukkan saldo awal untuk bermain game : Rp.";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "\n\nSaldo Anda saat ini adalah Rp." << balance << "\n";
        do
        {
            cout << "Hey, " << playerName<<", Masukkan jumlah uang taruhan : Rp.";
            cin >> bettingAmount;
            if(bettingAmount > balance)
                cout << "Saldo taruhan tidak boleh lebih dari saldo saat ini!\n"
                       <<"\nMasukkan kembali saldo\n ";
        }while(bettingAmount > balance);
        do
        {
            cout << "pilih nomor antara 1 - 20 :";
            cin >> guess;
            if(guess <= 0 || guess > 20)
                cout << "\n Angka harus antara  1 - 20\n"
                    <<" Masukan ulang nomor \n ";
        }while(guess <= 0 || guess > 20);
        dice = rand()%20 + 1;
        if(dice == guess)
        {
            cout << "\n\n Kamu beruntung!! Anda telah memenangkan taruhan" << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, beruntung lain waktu !! Anda kehilangan Rp. "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;
        }
        cout << "\nNomer yang benar adalah : " << dice <<"\n";
        cout << "\n"<<playerName<<", Saldo Anda adalah Rp. " << balance << "\n";
        if(balance == 0)
        {
            cout << "Anda tidak punya uang untuk bermain ";
            break;
        }
        cout << "\n\n-->Apakah anda ingin bermain lagi (y/n)? ";
        cin >> pilih;
    }while(pilih =='Y'|| pilih =='y');
    cout << "\n\n\n";
    cout << "\n\nTerima kasih telah bermain game ini. Saldo Anda adalah Rp. " << balance << "\n\n";
    return 0;
}
void rules()
{
    system("cls");
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Pilih sebuah nomor antara 1 sampai 20\n";
    cout << "\t2. Pemenang mendapat 10 kali lipat dari uang taruhan\n";
    cout << "\t3. Taruhan salah, dan Anda kehilangan jumlah yang Anda pertaruhkan\n\n";
}

