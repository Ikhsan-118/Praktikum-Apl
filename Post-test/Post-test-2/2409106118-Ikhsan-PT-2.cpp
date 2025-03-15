#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <cstdlib>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

using namespace std;

// Struktur untuk akun pengguna (tiket dipesan disimpan sebagai array multidimensi)
struct Pengguna {
    string password;
    string role;
    vector<vector<string>> tiket; // tiap tiket: {judul, lokasi, tanggal, harga}
};

int main() {
    // Data konser disimpan dalam array multidimensi (setiap baris: {judul, lokasi, tanggal, harga})
    vector<vector<string>> konser = {
        {"Lyodra", "Samarinda", "11-Oktober-2024", "200000"},
        {"Tulus", "Balikpapan", "12-Oktober-2024", "500000"},
        {"Bruno Mars", "Jakarta", "4-Desember-2024", "3000000"},
        {"Denny Caknan", "Samarinda", "1-Januari-2025", "80000"},
        {"Payung Teduh", "Bandung", "4-Januari-2025", "200000"}
    };
    
    // Inisialisasi akun pengguna; akun admin sudah ada.
    map<string, Pengguna> akun_pengguna = {
        {"admin", {"admin", "admin", {}}}
    };
    
    int total_tiket_terboking = 0;
    
    // Main loop
    while (true) {
        // --- Tampilan Menu Utama ---
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        cout << "--------------------------------------------\n";
        cout << "        Pemesanan Tiket Konser\n";
        cout << "  Silahkan Pilih Opsi Sign-In atau Sign-Up\n";
        cout << "--------------------------------------------\n";
        cout << "    1. Daftar Akun\n";
        cout << "    2. Login\n";
        cout << "    3. Exit\n";
        cout << "--------------------------------------------\n";
        cout << "    Copyright Kelompok 4 C2\n";
        cout << "--------------------------------------------\n";
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n";
        
        if (opsi == 1) { // Registrasi Akun
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            cout << "Halo Pengguna baru! Ayo buat akun dulu\n";
            cout << "Username: ";
            string username;
            cin >> username;
            if (akun_pengguna.find(username) != akun_pengguna.end()) {
                cout << "Nama sudah terpakai, silahkan coba lagi.\n";
            } else {
                cout << "Password: ";
                string password;
#ifdef _WIN32
                // Input password tersembunyi
                char ch;
                while ((ch = _getch()) != '\r') {
                    if (ch == '\b') {
                        if (!password.empty()) {
                            password.pop_back();
                            cout << "\b \b";
                        }
                    } else {
                        password.push_back(ch);
                        cout << "*";
                    }
                }
                cout << "\n";
#else
                cin >> password;
#endif
                if (password.length() < 8) {
                    cout << "\nPassword tidak boleh kurang dari 8 karakter.\n";
                } else {
                    akun_pengguna[username] = {password, "pengguna", {}};
                    cout << "Akun Anda berhasil terdaftar dengan ID: " << username << "\n";
                }
            }
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            
        } else if (opsi == 2) { // Login
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            cout << "Hi, silahkan login dulu ya!\n";
            cout << "Username: ";
            string username;
            cin >> username;
            cout << "Password: ";
            string password;
#ifdef _WIN32
            char ch;
            while ((ch = _getch()) != '\r') {
                if (ch == '\b') {
                    if (!password.empty()) {
                        password.pop_back();
                        cout << "\b \b";
                    }
                } else {
                    password.push_back(ch);
                    cout << "*";
                }
            }
            cout << "\n";
#else
            cin >> password;
#endif
            if (akun_pengguna.find(username) != akun_pengguna.end() && akun_pengguna[username].password == password) {
                // Jika login berhasil, masuk ke submenu berdasarkan role
                while (true) {
                    // Jika admin
                    if (akun_pengguna[username].role == "admin") {
#ifdef _WIN32
                        system("cls");
#else
                        system("clear");
#endif
                        cout << "============================================\n";
                        cout << "          Pemesanan Tiket Konser\n";
                        cout << "         " << username << " - Menu Admin\n";
                        cout << "============================================\n";
                        cout << "    1. Tambah Konser\n";
                        cout << "    2. Lihat Konser\n";
                        cout << "    3. Edit Konser\n";
                        cout << "    4. Hapus Konser\n";
                        cout << "    5. Lihat Statistik\n";
                        cout << "    6. Exit\n";
                        cout << "============================================\n";
                        cout << "    Copyright Kelompok 4 C2\n";
                        cout << "============================================\n";
                        cout << "Pilih opsi: ";
                        string status;
                        cin >> status;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n";
                        if (status == "1") { // Tambah Konser
#ifdef _WIN32
                            system("cls");
#else
                            system("clear");
#endif
                            cout << "=== Tambah Konser ===\n";
                            cout << "Judul Konser: ";
                            string judul, lokasi, tanggal, harga;
                            getline(cin, judul);
                            cout << "Lokasi Konser: ";
                            getline(cin, lokasi);
                            cout << "Hari/Tanggal Konser: ";
                            getline(cin, tanggal);
                            cout << "Harga Tiket: ";
                            getline(cin, harga);
                            konser.push_back({judul, lokasi, tanggal, harga});
                            cout << "\nKonser berhasil ditambahkan!\n";
                        } else if (status == "2") { // Lihat Konser
                            clearScreen:
#ifdef _WIN32
                            system("cls");
#else
                            system("clear");
#endif
                            cout << "===== Daftar Konser =====\n\n";
                            cout << "+----------------------+----------------+----------------------+------------+\n";
                            cout << "| Judul Konser         | Lokasi Konser  | Hari/Tanggal Konser  | Harga Tiket|\n";
                            cout << "+----------------------+----------------+----------------------+------------+\n";
                            for (auto &row : konser) {
                                cout << "| " << row[0] << string(20 - row[0].size(), ' ')
                                     << " | " << row[1] << string(14 - row[1].size(), ' ')
                                     << " | " << row[2] << string(20 - row[2].size(), ' ')
                                     << " | " << row[3] << string(10 - row[3].size(), ' ')
                                     << " |\n";
                            }
                            cout << "+----------------------+----------------+----------------------+------------+\n";
                        } else if (status == "3") { // Edit Konser
#ifdef _WIN32
                            system("cls");
#else
                            system("clear");
#endif
                            if (konser.empty()) {
                                cout << "Tidak ada konser yang bisa diedit.\n";
                            } else {
                                cout << "Daftar Konser:\n";
                                for (size_t i = 0; i < konser.size(); i++) {
                                    cout << i+1 << ". " << konser[i][0] << "\n";
                                }
                                cout << "Masukkan nomor konser yang ingin diedit: ";
                                int idx;
                                cin >> idx;
                                idx--;
                                if (idx < 0 || idx >= (int)konser.size()) {
                                    cout << "Nomor konser tidak valid.\n";
                                } else {
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    cout << "Masukkan judul baru: ";
                                    string judul, lokasi, tanggal, harga;
                                    getline(cin, judul);
                                    cout << "Masukkan lokasi baru: ";
                                    getline(cin, lokasi);
                                    cout << "Masukkan hari/tanggal baru: ";
                                    getline(cin, tanggal);
                                    cout << "Masukkan harga baru: ";
                                    getline(cin, harga);
                                    cout << "\nApakah Anda yakin ingin mengedit konser ini? (1 = Iya, 2 = Tidak): ";
                                    string confirm;
                                    cin >> confirm;
                                    if (confirm == "1") {
                                        konser[idx] = {judul, lokasi, tanggal, harga};
                                        cout << "\nKonser berhasil diubah!\n";
                                    } else {
                                        cout << "\nEdit dibatalkan.\n";
                                    }
                                }
                            }
                        } else if (status == "4") { // Hapus Konser
#ifdef _WIN32
                            system("cls");
#else
                            system("clear");
#endif
                            if (konser.empty()) {
                                cout << "Tidak ada konser yang bisa dihapus.\n";
                            } else {
                                cout << "===== Hapus Konser =====\n\n";
                                cout << "+----------------------+----------------+----------------------+------------+\n";
                                cout << "| Judul Konser         | Lokasi Konser  | Hari/Tanggal Konser  | Harga Tiket|\n";
                                cout << "+----------------------+----------------+----------------------+------------+\n";
                                for (auto &row : konser) {
                                    cout << "| " << row[0] << string(20 - row[0].size(), ' ')
                                         << " | " << row[1] << string(14 - row[1].size(), ' ')
                                         << " | " << row[2] << string(20 - row[2].size(), ' ')
                                         << " | " << row[3] << string(10 - row[3].size(), ' ')
                                         << " |\n";
                                }
                                cout << "+----------------------+----------------+----------------------+------------+\n";
                                cout << "Masukkan judul konser yang ingin dihapus: ";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                string hapus;
                                getline(cin, hapus);
                                bool found = false;
                                for (auto it = konser.begin(); it != konser.end(); it++) {
                                    if ((*it)[0] == hapus) {
                                        konser.erase(it);
                                        found = true;
                                        cout << "\nKonser berhasil dihapus!\n";
                                        break;
                                    }
                                }
                                if (!found) {
                                    cout << "\nKonser tidak ditemukan.\n";
                                }
                            }
                        } else if (status == "5") { // Lihat Statistik
#ifdef _WIN32
                            system("cls");
#else
                            system("clear");
#endif
                            cout << "========= Statistik =========\n\n";
                            cout << "+-------------------------------+-------------------------+\n";
                            cout << "| Total Konser Yang Tersedia    | Total Tiket Terboking   |\n";
                            cout << "+-------------------------------+-------------------------+\n";
                            string totalK = to_string(konser.size());
                            string totalT = to_string(total_tiket_terboking);
                            cout << "| " << totalK << string(29 - totalK.size(), ' ')
                                 << " | " << totalT << string(23 - totalT.size(), ' ') << " |\n";
                            cout << "+-------------------------------+-------------------------+\n";
                        } else if (status == "6") { // Exit submenu Admin
                            break;
                        } else {
                            cout << "Input tidak valid, silahkan pilih opsi yang tersedia.\n";
                        }
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                    }
                    // --- Submenu Pengguna ---
                    else { // Jika role bukan admin
#ifdef _WIN32
                        system("cls");
#else
                        system("clear");
#endif
                        cout << "============================================\n";
                        cout << "          Pemesanan Tiket Konser\n";
                        cout << "         " << username << " - Menu Pengguna\n";
                        cout << "============================================\n";
                        cout << "    1. Booking Tiket Konser\n";
                        cout << "    2. Lihat Tiket yang Dipesan\n";
                        cout << "    3. Exit\n";
                        cout << "============================================\n";
                        cout << "    Copyright Kelompok 4 C2\n";
                        cout << "============================================\n";
                        cout << "Pilih opsi: ";
                        string status;
                        cin >> status;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n";
                        if (status == "1") {
                            cout << "===== Daftar Konser =====\n\n";
                            for (auto &row : konser) {
                                cout << "- " << row[0] << " | " << row[1] << " | " << row[2] << " | Rp" << row[3] << "\n";
                            }
                            cout << "\nMasukkan judul konser yang ingin dipesan: ";
                            string judul;
                            getline(cin, judul);
                            bool found = false;
                            for (auto &row : konser) {
                                if (row[0] == judul) {
                                    akun_pengguna[username].tiket.push_back(row);
                                    total_tiket_terboking++;
                                    cout << "\nTiket konser berhasil dipesan!\n";
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                cout << "\nKonser tidak tersedia.\n";
                            }
                        } else if (status == "2") {
                            cout << "===== Tiket yang Dipesan =====\n\n";
                            if (akun_pengguna[username].tiket.empty()) {
                                cout << "Anda belum memesan tiket apapun.\n";
                            } else {
                                cout << "+----------------------+----------------+----------------------+------------+\n";
                                cout << "| Judul Konser         | Lokasi Konser  | Hari/Tanggal Konser  | Harga Tiket|\n";
                                cout << "+----------------------+----------------+----------------------+------------+\n";
                                for (auto &row : akun_pengguna[username].tiket) {
                                    cout << "| " << row[0] << string(20 - row[0].size(), ' ')
                                         << " | " << row[1] << string(14 - row[1].size(), ' ')
                                         << " | " << row[2] << string(20 - row[2].size(), ' ')
                                         << " | " << row[3] << string(10 - row[3].size(), ' ')
                                         << " |\n";
                                }
                                cout << "+----------------------+----------------+----------------------+------------+\n";
                            }
                        } else if (status == "3") { // Exit submenu Pengguna
                            break;
                        } else {
                            cout << "Input tidak valid, silahkan pilih opsi yang tersedia.\n";
                        }
                        cout << "\nTekan Enter untuk melanjutkan...";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin.get();
                    }
                }
            }
        } else if (opsi == 3) {
            cout << "Apakah kamu yakin ingin keluar dari aplikasi? \n";
            cout << "1. Iya\n";
            cout << "2. Tidak\n";
            cout << "Input pilihan: ";
            string pilih;
            cin >> pilih;
            cout << "\n";
            if (pilih == "1") {
                cout << "Terimakasih sudah menggunakan aplikasi, semoga harimu menyenangkan!\n";
                break;
            }
        } else {
            cout << "Input tidak valid, silahkan pilih 1, 2, atau 3\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
    return 0;
}
