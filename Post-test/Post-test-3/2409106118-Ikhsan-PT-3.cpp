#include <iostream>
using namespace std;

#define MAX_CONCERT 100  // Ukuran maksimum array konser
#define INFO 4           // Kolom: {judul, lokasi, tanggal, harga}
#define MAX_BOOKING 100  // Ukuran maksimum array booking per user
#define MAX_USER 100     // Ukuran maksimum array pengguna

struct Concert {
    string title;
    string location;
    string date;
    string price;
};

struct Booking {
    Concert concert;
};

struct User {
    string username;
    string password;
    string role;      // "admin" atau "user"
    int bookingCount;
    Booking bookings[MAX_BOOKING];
};

int main() {
    Concert concerts[MAX_CONCERT] = {
        {"Midnigth Serenade", "Samarinda", "11-Oktober-2024", "200000"},
        {"Arctic Monkey", "Balikpapan", "12-Oktober-2024", "500000"}
    };
    int concertCount = 2;
    
    User users[MAX_USER];
    int userCount = 2;
    // Pre-registered akun
    users[0].username = "admin";
    users[0].password = "admin";
    users[0].role = "admin";
    users[0].bookingCount = 0;
    
    users[1].username = "Ikhsan";
    users[1].password = "2409106118";
    users[1].role = "user";
    users[1].bookingCount = 0;
    
    int bookingCount = 0;
    
    while (true) {
        cout << "\n\n============================================\n";
        cout << "         Pemesanan Tiket Konser\n";
        cout << "  Pilih opsi: 1. Register   2. Login   3. Exit\n";
        cout << "============================================\n";
        cout << "Pilih opsi: ";
        int opsi;
        cin >> opsi;
        cin.ignore();
        cout << "\n";
        
        if (opsi == 1) {
            cout << "\n=== Registrasi Pengguna Baru ===\n";
            if (userCount < MAX_USER) {
                cout << "Masukkan username: ";
                cin >> users[userCount].username;
                cout << "Masukkan password: ";
                cin >> users[userCount].password;
                users[userCount].role = "user";
                users[userCount].bookingCount = 0;
                userCount++;
                cout << "\nRegistrasi berhasil! Silakan login.\n";
            } else {
                cout << "\nMaksimum pengguna telah tercapai.\n";
            }
        }
        else if (opsi == 2) {
            int attempts = 0;
            bool loggedIn = false;
            string user, pass;
            int loggedInIndex = -1;
            while (attempts < 3 && !loggedIn) {
                cout << "Username: ";
                cin >> user;
                cout << "Password: ";
                cin >> pass;
                cin.ignore();
                for (int i = 0; i < userCount; i++) {
                    if (users[i].username == user && users[i].password == pass) {
                        loggedIn = true;
                        loggedInIndex = i;
                        cout << "\nLogin berhasil!\n";
                        break;
                    }
                }
                if (!loggedIn) {
                    attempts++;
                    if (attempts < 3)
                        cout << "\nLogin gagal. Coba lagi (" << 3 - attempts << " kali tersisa).\n";
                }
            }
            if (!loggedIn) {
                cout << "\nAnda gagal login 3 kali. Program akan keluar.\n";
                break;
            }
            
            // Tampilkan menu berdasarkan role tanpa memeriksa username secara eksplisit
            if (users[loggedInIndex].role == "admin") {
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
                    
                    if (optAdmin == 1) {
                        if (concertCount < MAX_CONCERT) {
                            cout << "\n=== Tambah Konser ===\n";
                            cout << "Judul Konser: ";
                            getline(cin, concerts[concertCount].title);
                            cout << "Lokasi Konser: ";
                            getline(cin, concerts[concertCount].location);
                            cout << "Hari/Tanggal Konser: ";
                            getline(cin, concerts[concertCount].date);
                            cout << "Harga Tiket: ";
                            getline(cin, concerts[concertCount].price);
                            concertCount++;
                            cout << "\nKonser berhasil ditambahkan.\n";
                        } else {
                            cout << "\nData konser penuh.\n";
                        }
                    }
                    else if (optAdmin == 2) {
                        cout << "\n----- Daftar Konser -----\n";
                        cout << "+----------------------+----------------+----------------------+------------+\n";
                        cout << "| Judul Konser         | Lokasi Konser  | Hari/Tanggal Konser  | Harga Tiket|\n";
                        cout << "+----------------------+----------------+----------------------+------------+\n";
                        for (int i = 0; i < concertCount; i++) {
                            cout << "| " << concerts[i].title;
                            int sp = 20 - concerts[i].title.length();
                            for (int j = 0; j < sp; j++) cout << " ";
                            cout << " | " << concerts[i].location;
                            sp = 14 - concerts[i].location.length();
                            for (int j = 0; j < sp; j++) cout << " ";
                            cout << " | " << concerts[i].date;
                            sp = 20 - concerts[i].date.length();
                            for (int j = 0; j < sp; j++) cout << " ";
                            cout << " | " << concerts[i].price;
                            sp = 10 - concerts[i].price.length();
                            for (int j = 0; j < sp; j++) cout << " ";
                            cout << " |\n";
                        }
                        cout << "+----------------------+----------------+----------------------+------------+\n";
                    }
                    else if (optAdmin == 3) {
                        if (concertCount == 0)
                            cout << "\nTidak ada konser yang bisa diedit.\n";
                        else {
                            cout << "\nDaftar Konser:\n";
                            for (int i = 0; i < concertCount; i++) {
                                cout << i + 1 << ". " << concerts[i].title << "\n";
                            }
                            cout << "Masukkan nomor konser yang ingin diedit: ";
                            int num;
                            cin >> num;
                            cin.ignore();
                            if (num < 1 || num > concertCount)
                                cout << "Nomor tidak valid.\n";
                            else {
                                int idx = num - 1;
                                cout << "Edit Judul Konser (" << concerts[idx].title << "): ";
                                getline(cin, concerts[idx].title);
                                cout << "Edit Lokasi Konser (" << concerts[idx].location << "): ";
                                getline(cin, concerts[idx].location);
                                cout << "Edit Hari/Tanggal (" << concerts[idx].date << "): ";
                                getline(cin, concerts[idx].date);
                                cout << "Edit Harga Tiket (" << concerts[idx].price << "): ";
                                getline(cin, concerts[idx].price);
                                cout << "\nKonser berhasil diubah.\n";
                            }
                        }
                    }
                    else if (optAdmin == 4) {
                        if (concertCount == 0)
                            cout << "\nTidak ada konser yang bisa dihapus.\n";
                        else {
                            cout << "\nDaftar Konser:\n";
                            for (int i = 0; i < concertCount; i++) {
                                cout << i + 1 << ". " << concerts[i].title << "\n";
                            }
                            cout << "Masukkan nomor konser yang ingin dihapus: ";
                            int num;
                            cin >> num;
                            cin.ignore();
                            if (num < 1 || num > concertCount)
                                cout << "Nomor tidak valid.\n";
                            else {
                                int idx = num - 1;
                                for (int i = idx; i < concertCount - 1; i++) {
                                    concerts[i] = concerts[i + 1];
                                }
                                concertCount--;
                                cout << "\nKonser berhasil dihapus.\n";
                            }
                        }
                    }
                    else if (optAdmin == 5) {
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
            else { // Menu Pengguna untuk semua akun yang bukan admin
                while (true) {
                    cout << "\n========== Menu Pengguna ==========" << endl;
                    cout << "1. Booking Tiket Konser" << endl;
                    cout << "2. Lihat Tiket yang Dipesan" << endl;
                    cout << "3. Logout" << endl;
                    cout << "=====================================" << endl;
                    cout << "Pilih opsi: ";
                    int optUser;
                    cin >> optUser;
                    cin.ignore();
                    if (optUser == 1) {
                        cout << "\n----- Daftar Konser -----\n";
                        for (int i = 0; i < concertCount; i++) {
                            cout << i + 1 << ". " << concerts[i].title << " | "
                                 << concerts[i].location << " | "
                                 << concerts[i].date << " | "
                                 << concerts[i].price << "\n";
                        }
                        cout << "\nMasukkan nomor konser yang ingin dipesan: ";
                        int num;
                        cin >> num;
                        cin.ignore();
                        if (num < 1 || num > concertCount)
                            cout << "Nomor tidak valid.\n";
                        else {
                            int idx = num - 1;
                            users[loggedInIndex].bookings[users[loggedInIndex].bookingCount].concert = concerts[idx];
                            users[loggedInIndex].bookingCount++;
                            cout << "\nTiket berhasil dipesan.\n";
                        }
                    }
                    else if (optUser == 2) {
                        cout << "\n===== Tiket yang Dipesan =====\n";
                        if (users[loggedInIndex].bookingCount == 0)
                            cout << "Anda belum memesan tiket.\n";
                        else {
                            cout << "+----------------------+----------------+----------------------+------------+\n";
                            cout << "| Judul Konser         | Lokasi Konser  | Hari/Tanggal Konser  | Harga Tiket|\n";
                            cout << "+----------------------+----------------+----------------------+------------+\n";
                            for (int i = 0; i < users[loggedInIndex].bookingCount; i++) {
                                cout << "| " << users[loggedInIndex].bookings[i].concert.title;
                                int sp = 20 - users[loggedInIndex].bookings[i].concert.title.length();
                                for (int j = 0; j < sp; j++) cout << " ";
                                cout << " | " << users[loggedInIndex].bookings[i].concert.location;
                                sp = 14 - users[loggedInIndex].bookings[i].concert.location.length();
                                for (int j = 0; j < sp; j++) cout << " ";
                                cout << " | " << users[loggedInIndex].bookings[i].concert.date;
                                sp = 20 - users[loggedInIndex].bookings[i].concert.date.length();
                                for (int j = 0; j < sp; j++) cout << " ";
                                cout << " | " << users[loggedInIndex].bookings[i].concert.price;
                                sp = 10 - users[loggedInIndex].bookings[i].concert.price.length();
                                for (int j = 0; j < sp; j++) cout << " ";
                                cout << " |\n";
                            }
                            cout << "+----------------------+----------------+----------------------+------------+\n";
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
        }
        else if (opsi == 3) {
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