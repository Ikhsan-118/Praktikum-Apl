#include <iostream>
using namespace std;

bool cekPrima(int angka) {
    if (angka < 2) return false;
    for (int i = 2; i * i <= angka; i++) {
        if (angka % i == 0) return false;
    }
    return true;
}

bool cekPalindrome(int angka) {
    int asli = angka, terbalik = 0, digit;
    while (angka > 0) {
        digit = angka % 10;
        terbalik = terbalik * 10 + digit;
        angka /= 10;
    }
    return asli == terbalik;
}

bool login() {
    string namaPengguna, namaBenar = "Ikhsan";
    string kataSandi, sandiBenar = "2409106118";

    cin.ignore();
    while (true) {
        cout << "===== LOGIN =====\n";
        cout << "Nama Pengguna: ";
        getline(cin, namaPengguna);
        cout << "Kata Sandi: ";
        getline(cin, kataSandi);

        if (namaPengguna == namaBenar && kataSandi == sandiBenar) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal! Silakan coba lagi.\n";
        }
    }
}

int main() {
    while (true) {
        int opsi;
        cout << "===== SELAMAT DATANG =====\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih opsi: ";
        
        while (!(cin >> opsi)) {
            cout << "Input tidak valid! Masukkan angka.\nPilih opsi: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (opsi == 2) {
            cout << "Terima kasih, program berhenti.\n";
            return 0;
        } else if (opsi != 1) {
            cout << "Opsi tidak valid! Silakan pilih kembali.\n";
            continue;
        }

        if (!login()) {
            continue;
        }

        while (true) {
            int kodeSandi;
            cout << "\nMasukkan kode sandi (bilangan bulat positif): ";
            while (!(cin >> kodeSandi)) {
                cout << "Input tidak valid! Masukkan angka.\nMasukkan kode sandi: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (kodeSandi <= 100 || kodeSandi >= 99999) {
                cout << "Kode sandi harus lebih dari 100 dan kurang dari 99999!\n";
                continue;
            }

            while (true) {
                int pilihan;
                cout << "\n===== MENU =====\n";
                cout << "1. Cek apakah kode sandi adalah bilangan prima\n";
                cout << "2. Cek apakah kode sandi habis dibagi 2 dan 3 tetapi tidak habis dibagi 5\n";
                cout << "3. Cek apakah kode sandi adalah bilangan palindrome\n";
                cout << "4. Masukkan kode sandi baru\n";
                cout << "5. Logout\n";
                cout << "Pilih menu: ";
                
                while (!(cin >> pilihan)) {
                    cout << "Input tidak valid! Masukkan angka.\nPilih menu: ";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }

                if (pilihan == 1) {
                    cout << (cekPrima(kodeSandi) ? "Kode sandi adalah bilangan prima.\n" : "Kode sandi bukan bilangan prima.\n");
                } 
                else if (pilihan == 2) {
                    if (kodeSandi % 2 == 0 && kodeSandi % 3 == 0 && kodeSandi % 5 != 0)
                        cout << "Kode sandi valid sesuai kriteria.\n";
                    else
                        cout << "Kode sandi tidak valid sesuai kriteria.\n";
                } 
                else if (pilihan == 3) {
                    cout << (cekPalindrome(kodeSandi) ? "Kode sandi adalah bilangan palindrome.\n" : "Kode sandi bukan bilangan palindrome.\n");
                } 
                else if (pilihan == 4) {
                    break;
                } 
                else if (pilihan == 5) {
                    cout << "Logout berhasil! Kembali ke menu utama.\n";
                    goto kembaliKeMenu;
                } 
                else {
                    cout << "Pilihan tidak valid!\n";
                }
            }
        }
        kembaliKeMenu:;
    }
}
