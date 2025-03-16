#include <iostream>
using namespace std;

// Data akun (login sederhana)
// Admin: username "admin", password "admin"
// Pengguna: username "Ikhsan", password "2409106118"

#define MAX_CONCERT 100 // Ukuran maksimum array konser
#define INFO 4 // Kolom untuk menyimpan informasi tambahan (judul, lokasi, tanggal, harga)
#define MAX_BOOKING 100 // Ukuran maksimum array booking

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
    
    // Data tiket yang dipesan oleh pengguna (khusus untuk akun Ikhsan)
    string bookings[MAX_BOOKING][INFO];
    int bookingCount = 0;
    
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
        
        if (opsi == 1) {
            // Proses login
            string user, pass;
            cout << "\nUsername: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;
            cin.ignore();
            
            if (user == "admin" && pass == "admin") {
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
                        if (concertCount < 100) {
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
                                // Geser data konser ke atas untuk menghapus konser idx
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
            else if (user == "Ikhsan" && pass == "2409106118") {
                // Menu Pengguna
                while (true) {
                    cout << "\n========== Menu Pengguna ==========\n";
                    cout << "1. Booking Tiket Konser\n";
                    cout << "2. Lihat Tiket yang Dipesan\n";
                    cout << "3. Logout\n";
                    cout << "=====================================\n";
                    cout << "Pilih opsi: ";
                    int optUser;
                    cin >> optUser;
                    cin.ignore();
                    if (optUser == 1) { // Booking tiket
                        cout << "\n----- Daftar Konser -----\n";
                        for (int i = 0; i < concertCount; i++) {
                            cout << i+1 << ". " << concerts[i][0] << " | " 
                                 << concerts[i][1] << " | " 
                                 << concerts[i][2] << " | " 
                                 << concerts[i][3] << "\n";
                        }
                        cout << "\nMasukkan nomor konser yang ingin dipesan: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num < 1 || num > concertCount)
                            cout << "Nomor tidak valid.\n";
                        else {
                            int idx = num - 1;
                            // Simpan booking untuk Ikhsan
                            for (int i = 0; i < 4; i++) {
                                bookings[bookingCount][i] = concerts[idx][i];
                            }
                            bookingCount++;
                            cout << "\nTiket berhasil dipesan.\n";
                        }
                    }
                    else if (optUser == 2) { // Lihat tiket yang dipesan
                        cout << "\n===== Tiket yang Dipesan =====\n";
                        if (bookingCount == 0)
                            cout << "Anda belum memesan tiket.\n";
                        else {
                            for (int i = 0; i < bookingCount; i++) {
                                cout << i+1 << ". " << bookings[i][0] << " | " 
                                     << bookings[i][1] << " | " 
                                     << bookings[i][2] << " | " 
                                     << bookings[i][3] << "\n";
                            }
                        }
                    }
                    else if (optUser == 3) {
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
            else {
                cout << "\nLogin gagal. Username atau password salah.\n";
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