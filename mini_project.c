#include <stdio.h>
#include <string.h>

#define MAX_SISWA 100
#define JUMLAH_MATA_PELAJARAN 3

// Struktur data untuk menyimpan informasi siswa
struct Siswa {
    char nama[50];
    float nilai[JUMLAH_MATA_PELAJARAN];
    float rataRata;
    char status[10];
};

int main() {
    struct Siswa siswa[MAX_SISWA];
    int jumlahSiswa, i, j;

    printf("=== Program Manajemen Nilai Siswa ===\n");
    printf("Masukkan jumlah siswa: ");
    scanf("%d", &jumlahSiswa);
    getchar(); // membersihkan buffer newline

    for (i = 0; i < jumlahSiswa; i++) {
        printf("\nSiswa ke-%d\n", i + 1);
        printf("Nama: ");
        fgets(siswa[i].nama, sizeof(siswa[i].nama), stdin);
        // Menghapus newline dari fgets
        siswa[i].nama[strcspn(siswa[i].nama, "\n")] = 0;

        float total = 0;
        for (j = 0; j < JUMLAH_MATA_PELAJARAN; j++) {
            printf("Nilai mata pelajaran %d: ", j + 1);
            scanf("%f", &siswa[i].nilai[j]);
            total += siswa[i].nilai[j];
        }
        getchar(); // bersihkan buffer

        siswa[i].rataRata = total / JUMLAH_MATA_PELAJARAN;
        if (siswa[i].rataRata >= 60) {
            strcpy(siswa[i].status, "LULUS");
        } else {
            strcpy(siswa[i].status, "GAGAL");
        }
    }

    // Menampilkan hasil
    printf("\n=== Hasil Nilai Siswa ===\n");
    for (i = 0; i < jumlahSiswa; i++) {
        printf("Nama: %s\n", siswa[i].nama);
        printf("Rata-rata: %.2f\n", siswa[i].rataRata);
        printf("Status: %s\n", siswa[i].status);
        printf("---------------------------\n");
    }

    return 0;
}