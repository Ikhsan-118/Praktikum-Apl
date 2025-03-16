#include <iostream>
using namespace std;

#define MAX_CONCERT 100 // Ukuran maksimum array konser
#define INFO 4          // Kolom: {judul, lokasi, tanggal, harga}

int main() {
    // Data konser: setiap baris berisi {judul, lokasi, tanggal, harga}
    string concerts[MAX_CONCERT][INFO] = {
        {"Lyodra", "Samarinda", "11-Oktober-2024", "200000"},
        {"Tulus", "Balikpapan", "12-Oktober-2024", "500000"},
        {"Bruno Mars", "Jakarta", "4-Desember-2024", "3000000"},
        {"Denny Caknan", "Samarinda", "1-Januari-2025", "80000"},
        {"Payung Teduh", "Bandung", "4-Januari-2025", "200000"}
    };
    int concertCount = 5;
    
    while (true) {
        // Tampilan Menu Utama
        cout << "\n\n============================================\n";
        cout << "         Pemesanan Tiket Konser\n";
        cout << "  Silahkan Pilih Opsi Login atau Exit\n";
        cout << "============================================\n";
        cout << "    1. Login\n";
        cout << "    2. Exit\n";
        cout << "============================================\n";
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;
        cin.ignore(); // bersihkan newline
        cout << "\n";
        
        if (opsi == 1) {
            // Batas 3 kali login
            int attempts = 0;
            bool loggedIn = false;
            string user, pass;
            while (attempts < 3 && !loggedIn) {
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                cin.ignore();
                if (user == "admin" && pass == "admin") {
                    loggedIn = true;
                } else {
                    cout << "\nLogin gagal. Username atau password salah.\n";
                    attempts++;
                    if (attempts < 3)
                        cout << "Coba lagi (" << 3 - attempts << " kali tersisa).\n";
                }
            }
            if (!loggedIn) {
                cout << "\nAnda gagal login tiga kali. Program akan keluar.\n";
                break;
            }
            
            // Menu Admin
            while (true) {
                cout << "\n\n========== Menu Admin ==========\n";
                cout << "1. Tambah Konser\n";
                cout << "2. Lihat Konser\n";
                cout << "3. Edit Konser\n";
                cout << "4. Hapus Konser\n";
                cout << "5. Logout\n";
                cout << "================================\n";
                cout << "Pilih opsi: ";
                int optAdmin;
                cin >> optAdmin;
                cin.ignore();
                
                if (optAdmin == 1) { // Tambah Konser
                    if (concertCount < MAX_CONCERT) {
                        cout << "\n=== Tambah Konser ===\n";
                        cout << "Judul Konser: ";
                        getline(cin, concerts[concertCount][0]);
                        cout << "Lokasi Konser: ";
                        getline(cin, concerts[concertCount][1]);
                        cout << "Hari/Tanggal Konser: ";
                        getline(cin, concerts[concertCount][2]);
                        cout << "Harga Tiket: ";
                        getline(cin, concerts[concertCount][3]);
                        concertCount++;
                        cout << "\nKonser berhasil ditambahkan.\n";
                    } else {
                        cout << "\nData konser penuh.\n";
                    }
                }
                else if (optAdmin == 2) { // Lihat Konser
                    cout << "\n----- Daftar Konser -----\n";
                    cout << "+----------------------+----------------+----------------------+------------+\n";
                    cout << "| Judul Konser         | Lokasi Konser  | Hari/Tanggal Konser  | Harga Tiket|\n";
                    cout << "+----------------------+----------------+----------------------+------------+\n";
                    for (int i = 0; i < concertCount; i++) {
                        cout << "| " << concerts[i][0];
                        int sp = 20 - concerts[i][0].length();
                        for (int j = 0; j < sp; j++) cout << " ";
                        cout << " | " << concerts[i][1];
                        sp = 14 - concerts[i][1].length();
                        for (int j = 0; j < sp; j++) cout << " ";
                        cout << " | " << concerts[i][2];
                        sp = 20 - concerts[i][2].length();
                        for (int j = 0; j < sp; j++) cout << " ";
                        cout << " | " << concerts[i][3];
                        sp = 10 - concerts[i][3].length();
                        for (int j = 0; j < sp; j++) cout << " ";
                        cout << " |\n";
                    }
                    cout << "+----------------------+----------------+----------------------+------------+\n";
                }
                else if (optAdmin == 3) { // Edit Konser
                    if (concertCount == 0)
                        cout << "\nTidak ada konser yang bisa diedit.\n";
                    else {
                        cout << "\nDaftar Konser:\n";
                        for (int i = 0; i < concertCount; i++) {
                            cout << i+1 << ". " << concerts[i][0] << "\n";
                        }
                        cout << "Masukkan nomor konser yang ingin diedit: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num < 1 || num > concertCount)
                            cout << "Nomor tidak valid.\n";
                        else {
                            int idx = num - 1;
                            cout << "Edit Judul Konser (" << concerts[idx][0] << "): ";
                            getline(cin, concerts[idx][0]);
                            cout << "Edit Lokasi Konser (" << concerts[idx][1] << "): ";
                            getline(cin, concerts[idx][1]);
                            cout << "Edit Hari/Tanggal (" << concerts[idx][2] << "): ";
                            getline(cin, concerts[idx][2]);
                            cout << "Edit Harga Tiket (" << concerts[idx][3] << "): ";
                            getline(cin, concerts[idx][3]);
                            cout << "\nKonser berhasil diubah.\n";
                        }
                    }
                }
                else if (optAdmin == 4) { // Hapus Konser
                    if (concertCount == 0)
                        cout << "\nTidak ada konser yang bisa dihapus.\n";
                    else {
                        cout << "\nDaftar Konser:\n";
                        for (int i = 0; i < concertCount; i++) {
                            cout << i+1 << ". " << concerts[i][0] << "\n";
                        }
                        cout << "Masukkan nomor konser yang ingin dihapus: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num < 1 || num > concertCount)
                            cout << "Nomor tidak valid.\n";
                        else {
                            int idx = num - 1;
                            // Geser data konser ke atas untuk menghapus konser pada indeks idx
                            for (int i = idx; i < concertCount - 1; i++) {
                                concerts[i][0] = concerts[i+1][0];
                                concerts[i][1] = concerts[i+1][1];
                                concerts[i][2] = concerts[i+1][2];
                                concerts[i][3] = concerts[i+1][3];
                            }
                            concertCount--;
                            cout << "\nKonser berhasil dihapus.\n";
                        }
                    }
                }
                else if (optAdmin == 5) { // Logout
                    break;
                }
                else {
                    cout << "\nOpsi tidak valid.\n";
                }
                cout << "\nTekan Enter untuk melanjutkan...";
                cin.ignore();
                cin.get();
            }
        }
        else if (opsi == 2) {
            cout << "\nTerima kasih telah menggunakan aplikasi.\n";
            break;
        }
        else {
            cout << "\nInput tidak valid.\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}
