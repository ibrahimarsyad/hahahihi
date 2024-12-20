#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class menghitung_diskon {
private:
    double harga_satuan; //Harga satuan barang
    int jumlah_barang; //Jumlah barang yang dibeli
    
	//Fungsi untuk validasi harga satuan harus berupa bilangan dan positif
    double input_harga_satuan() {
        double harga;
        while (true) {
            try {
                cout << "Masukkan harga satuan barang Rp";
                cin >> harga; //Input dari pengguna
                if (cin.fail()) {
                    cin.clear(); //Membersihkan status error pada cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Menghapus input yang salah
                    throw invalid_argument("Harga satuan harus berupa angka.");
                }
                if (harga <= 0) {
                    throw invalid_argument("Harga satuan harus berupa bilangan positif.");
                }
                return harga; //Input valid, keluar dari loop
            } 
			catch (const invalid_argument &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
    }

    //Fungsi untuk validasi jumlah barang
    int input_jumlah_barang() {
        int jumlah;
        while (true) {
            try {
                cout << "Masukkan jumlah barang: ";
                cin >> jumlah; //Input dari pengguna
                if (cin.fail()) {
                    cin.clear(); // Bersihkan status error pada cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Menghapus input yang salah
                    throw invalid_argument("Jumlah barang harus berupa angka.");
                }
                if (jumlah <= 0) {
                    throw invalid_argument("Jumlah barang harus berupa bilangan positif.");
                }
                return jumlah; //Input valid, keluar dari loop
            } 
			catch (const invalid_argument &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
    }

    //Fungsi untuk menghitung total harga setelah diskon
    double hitung_total_harga() {
        double total_harga = harga_satuan * jumlah_barang;
        double diskon = 0.0; //Kondisi awal atau saat belum ada diskon
        if (jumlah_barang > 10) {
            diskon = 0.20; //Kondisi saat jumlah barang lebih dari 10 dan mendapatkan diskon 20%
        } 
		else if (jumlah_barang >= 5) {
            diskon = 0.10; //Kondisi saat jumlah barang lebih dari sama dengan 5 dan mendapatkan diskon 10%
        }
        return total_harga * (1 - diskon); //Menghitung harga setelah diskon
    }

public:
    // Konstruktor untuk memulai program
    menghitung_diskon() {
        cout << "Program Penghitung Diskon E-Commerce\n";
        harga_satuan = input_harga_satuan();
        jumlah_barang = input_jumlah_barang();
    }

    // Fungsi untuk menjalankan perhitungan dan menampilkan hasil perhitungan
    void tampilkan_hasil() {
        double total_harga = hitung_total_harga();
        cout << fixed << setprecision(2);//Menampilkan angka desimal dua digit di belakang koma
        cout << "Total harga setelah diskon: Rp" << total_harga << endl;
    }
};

int main() {
    // Membuat objek menghitung_diskon
    menghitung_diskon hitung;
    hitung.tampilkan_hasil();

    return 0;
}