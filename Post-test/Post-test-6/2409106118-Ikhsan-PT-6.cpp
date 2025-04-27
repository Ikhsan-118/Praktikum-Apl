#include <iostream>
#include <string>
using namespace std;

#define MAKS_KONSER 100
#define MAKS_BOOKING 100
#define MAKS_USER 100

struct Konser {
    string judul, lokasi, tanggal, harga;
};

struct Booking {
    Konser konser;
};

struct Pengguna {
    string nama, sandi, peran;
    int jumlahBooking;
    Booking daftarBooking[MAKS_BOOKING];
};

// Overloading tampilkanPesan
void tampilkanPesan(const string &pesan) {
    cout << pesan << "\n";
}
void tampilkanPesan(const string &pesan, int x) {
    cout << pesan << x << "\n";
}

// Prosedur registrasi
void registrasi(Pengguna pengguna[], int &jumlahUser) {
    tampilkanPesan("\n=== Registrasi Pengguna Baru ===");
    if (jumlahUser < MAKS_USER) {
        cout << "Masukkan nama pengguna: "; cin >> pengguna[jumlahUser].nama;
        cout << "Masukkan kata sandi: ";     cin >> pengguna[jumlahUser].sandi;
        pengguna[jumlahUser].peran = "user";
        pengguna[jumlahUser].jumlahBooking = 0;
        jumlahUser++;
        tampilkanPesan("Registrasi berhasil! Silakan login.");
    } else {
        tampilkanPesan("Maksimum pengguna tercapai.");
    }
}

// Fungsi login
int login(Pengguna pengguna[], int jumlahUser) {
    int percobaan = 0;
    while (percobaan < 3) {
        string nama, sandi;
        cout << "Nama pengguna: "; cin >> nama;
        cout << "Kata sandi: ";    cin >> sandi;
        for (int i = 0; i < jumlahUser; i++) {
            if (pengguna[i].nama == nama && pengguna[i].sandi == sandi) {
                tampilkanPesan("Login berhasil!");
                return i;
            }
        }
        percobaan++;
        tampilkanPesan("Login gagal. Sisa percobaan: ", 3 - percobaan);
    }
    tampilkanPesan("Anda gagal login 3 kali. Program keluar.");
    return -1;
}

// Rekursif menampilkan tabel konser
void tampilkanTabelKonserRekursif(const Konser konser[], int idx, int jumlah) {
    if (idx == 0) {
        cout << "+----+----------------------+--------------+-----------------+----------+\n";
        cout << "| No | Judul                | Lokasi       | Tanggal         | Harga    |\n";
        cout << "+----+----------------------+--------------+-----------------+----------+\n";
    }
    if (idx >= jumlah) {
        cout << "+----+----------------------+--------------+-----------------+----------+\n";
        return;
    }
    auto &k = konser[idx];
    printf("| %2d | %-20s | %-12s | %-15s | %8s |\n",
        idx+1,
        k.judul.c_str(),
        k.lokasi.c_str(),
        k.tanggal.c_str(),
        k.harga.c_str()
    );
    tampilkanTabelKonserRekursif(konser, idx+1, jumlah);
}

// Prosedur admin
void tambahKonser(Konser konser[], int &jumlah) {
    if (jumlah >= MAKS_KONSER) {
        tampilkanPesan("Data konser penuh.");
        return;
    }
    tampilkanPesan("\n=== Tambah Konser ===");
    cin.ignore();
    cout << "Judul Konser: ";    getline(cin, konser[jumlah].judul);
    cout << "Lokasi Konser: ";   getline(cin, konser[jumlah].lokasi);
    cout << "Tanggal Konser: ";  getline(cin, konser[jumlah].tanggal);
    cout << "Harga Tiket: ";     getline(cin, konser[jumlah].harga);
    jumlah++;
    tampilkanPesan("Konser berhasil ditambahkan.");
}

void lihatKonser(const Konser konser[], int jumlah) {
    tampilkanTabelKonserRekursif(konser, 0, jumlah);
}

void editKonser(Konser konser[], int jumlah) {
    if (!jumlah) { tampilkanPesan("Tidak ada konser untuk diedit."); return; }
    lihatKonser(konser, jumlah);
    cout << "Pilih nomor konser: "; int no; cin >> no; cin.ignore();
    if (no < 1 || no > jumlah) { tampilkanPesan("Nomor tidak valid."); return; }
    int i = no - 1;
    cout << "Edit Judul (" << konser[i].judul << "): "; getline(cin, konser[i].judul);
    cout << "Edit Lokasi (" << konser[i].lokasi << "): "; getline(cin, konser[i].lokasi);
    cout << "Edit Tanggal (" << konser[i].tanggal << "): "; getline(cin, konser[i].tanggal);
    cout << "Edit Harga (" << konser[i].harga << "): "; getline(cin, konser[i].harga);
    tampilkanPesan("Konser berhasil diubah.");
}

void hapusKonser(Konser konser[], int &jumlah) {
    if (!jumlah) { tampilkanPesan("Tidak ada konser untuk dihapus."); return; }
    lihatKonser(konser, jumlah);
    cout << "Pilih nomor konser: "; int no; cin >> no;
    if (no < 1 || no > jumlah) { tampilkanPesan("Nomor tidak valid."); return; }
    for (int i = no - 1; i < jumlah - 1; i++) konser[i] = konser[i + 1];
    jumlah--;
    tampilkanPesan("Konser berhasil dihapus.");
}

// Prosedur user
void bookingTiket(Pengguna &u, const Konser konser[], int jumlah) {
    lihatKonser(konser, jumlah);
    cout << "Pilih nomor konser: "; int no; cin >> no;
    if (no < 1 || no > jumlah) { tampilkanPesan("Nomor tidak valid."); return; }
    u.daftarBooking[u.jumlahBooking++].konser = konser[no - 1];
    tampilkanPesan("Tiket berhasil dipesan.");
}

void lihatBooking(const Pengguna &u) {
    if (!u.jumlahBooking) { tampilkanPesan("Anda belum memesan tiket."); return; }
    cout << "+----+----------------------+--------------+-----------------+----------+\n";
    cout << "| No | Judul                | Lokasi       | Tanggal         | Harga    |\n";
    cout << "+----+----------------------+--------------+-----------------+----------+\n";
    for (int i = 0; i < u.jumlahBooking; i++) {
        auto &k = u.daftarBooking[i].konser;
        printf("| %2d | %-20s | %-12s | %-15s | %8s |\n",
            i+1,
            k.judul.c_str(),
            k.lokasi.c_str(),
            k.tanggal.c_str(),
            k.harga.c_str()
        );
    }
    cout << "+----+----------------------+--------------+-----------------+----------+\n";
}

void urutJudulDescending(Konser konser[], int jumlah) {
    for (int i = 0; i < jumlah-1; i++)
        for (int j = 0; j < jumlah-i-1; j++)
            if (konser[j].judul < konser[j+1].judul)
                swap(konser[j], konser[j+1]);
    tampilkanPesan("\n[Sorting] Judul konser diurutkan Descending.");
}

void urutHargaAscending(Konser konser[], int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        int idxMin = i;
        for (int j = i+1; j < jumlah; j++)
            if (stoi(konser[j].harga) < stoi(konser[idxMin].harga))
                idxMin = j;
        swap(konser[i], konser[idxMin]);
    }
    tampilkanPesan("\n[Sorting] Harga tiket diurutkan Ascending.");
}

void urutLokasiAscending(Konser konser[], int jumlah) {
    for (int i = 1; i < jumlah; i++) {
        Konser tmp = konser[i];
        int j = i - 1;
        while (j >= 0 && konser[j].lokasi > tmp.lokasi) {
            konser[j+1] = konser[j];
            j--;
        }
        konser[j+1] = tmp;
    }
    tampilkanPesan("\n[Sorting] Lokasi konser diurutkan Ascending.");
}

// Fungsi dengan parameter address-of
void tambahSatuPengguna(int* alamatJumlahUser) {
    (*alamatJumlahUser)++;
}
// Fungsi dengan parameter dereference
void tampilkanJumlahKonser(int* ptrJumlahKonser) {
    cout << "Jumlah konser saat ini: " << *ptrJumlahKonser << "\n";
}

int main() {
    Konser konser[MAKS_KONSER] = {
        {"Midnigth Serenade","Samarinda","11-Oktober-2024","200000"},
        {"Arctic Monkey","Balikpapan","12-Oktober-2024","500000"}
    };
    int jumlahKonser = 2;

    Pengguna pengguna[MAKS_USER];
    int jumlahUser = 2;
    pengguna[0] = {"admin","admin","admin",0};
    pengguna[1] = {"Ikhsan","2409106118","user",0};

    while (true) {
        tampilkanPesan("\n=== Pemesanan Tiket Konser ===");
        tampilkanPesan("1. Register");
        tampilkanPesan("2. Login");
        tampilkanPesan("3. Exit");
        tampilkanPesan("Pilih opsi: ");
        int opsi; cin >> opsi;
        if (opsi == 1) {
            registrasi(pengguna, jumlahUser);
        }
        else if (opsi == 2) {
            int idx = login(pengguna, jumlahUser);
            if (idx < 0) break;
            if (pengguna[idx].peran == "admin") {
                while (true) {
                    tampilkanPesan("\n-- Menu Admin --");
                    tampilkanPesan("1. Tambah");
                    tampilkanPesan("2. Lihat");
                    tampilkanPesan("3. Edit");
                    tampilkanPesan("4. Hapus");
                    tampilkanPesan("5. Sorting Konser");
                    tampilkanPesan("6. Logout");
                    tampilkanPesan("Pilih: ");
                    int o; cin >> o;
                    if (o == 1) tambahKonser(konser, jumlahKonser);
                    else if (o == 2) lihatKonser(konser, jumlahKonser);
                    else if (o == 3) editKonser(konser, jumlahKonser);
                    else if (o == 4) hapusKonser(konser, jumlahKonser);
                    else if (o == 5) {
                        tampilkanPesan("\n-- Metode Sorting --");
                        tampilkanPesan("1. Judul Descending");
                        tampilkanPesan("2. Harga Ascending");
                        tampilkanPesan("3. Lokasi Ascending");
                        tampilkanPesan("Pilih metode: ");
                        int ms; cin >> ms;
                        if      (ms == 1) urutJudulDescending(konser, jumlahKonser);
                        else if (ms == 2) urutHargaAscending(konser, jumlahKonser);
                        else if (ms == 3) urutLokasiAscending(konser, jumlahKonser);
                        else tampilkanPesan("Pilihan tidak valid.");
                        lihatKonser(konser, jumlahKonser);
                    }
                    else if (o == 6) break;
                }
            } else {
                while (true) {
                    tampilkanPesan("\n-- Menu User --");
                    tampilkanPesan("1. Booking Tiket Konser");
                    tampilkanPesan("2. Lihat Tiket yang Dipesan");
                    tampilkanPesan("3. Logout");
                    tampilkanPesan("Pilih: ");
                    int o; cin >> o;
                    if      (o == 1) bookingTiket(pengguna[idx], konser, jumlahKonser);
                    else if (o == 2) lihatBooking(pengguna[idx]);
                    else if (o == 3) break;
                }
            }
        }
        else break;
    }

    // Simulasi pointer
    tambahSatuPengguna(&jumlahUser);
    tampilkanPesan("\nSimulasi: Jumlah pengguna bertambah satu.");
    tampilkanPesan("Total pengguna sekarang: ", jumlahUser);
    tampilkanPesan("\nMenampilkan jumlah konser:");
    tampilkanJumlahKonser(&jumlahKonser);

    return 0;
}