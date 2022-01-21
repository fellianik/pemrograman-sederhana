#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_MAHASISWA 100

int jumlah_mahasiswa = 0;

struct mahasiswa{
    char nama[50];
    int nilai_bahasa;
    int nilai_inggris;
    int nilai_matematika;
    int nilai_kejuruan;
    float rata_rata;
};


struct mahasiswa input_data()
{

    struct mahasiswa a_mahasiswa;

    printf("Tambah Data Mahasiswa Ke %d\n", (jumlah_mahasiswa + 1));
    printf("================================\n");
    printf("Masukkan Nama Mahasiswa : ");
    scanf("%s", &a_mahasiswa.nama);
    printf("Masukkan nilai Matematika : ");
    scanf("%d", &a_mahasiswa.nilai_matematika);
    printf("Masukkan nilai Bahasa Indonesia : ");
    scanf("%d", &a_mahasiswa.nilai_bahasa);
    printf("Masukkan nilai Bahasa Inggris : ");
    scanf("%d", &a_mahasiswa.nilai_inggris);
    printf("Masukkan nilai Kejuruan : ");
    scanf("%d", &a_mahasiswa.nilai_kejuruan);
    a_mahasiswa.rata_rata = (a_mahasiswa.nilai_matematika + a_mahasiswa.nilai_bahasa + a_mahasiswa.nilai_inggris + a_mahasiswa.nilai_kejuruan) / 4;

    return a_mahasiswa;
}

void print_data(struct mahasiswa a_mahasiswa)
{
    printf("Nama mahasiswa: %s\n", a_mahasiswa.nama);
    printf("Nilai matematika: %d\n", a_mahasiswa.nilai_matematika);
    printf("Nilai bahasa indonesia: %d\n", a_mahasiswa.nilai_bahasa);
    printf("Nilai bahasa inggris: %d\n", a_mahasiswa.nilai_inggris);
    printf("Nilai kejuruan: %d\n", a_mahasiswa.nilai_kejuruan);
    printf("Nilai rata-rata: %.2f\n", a_mahasiswa.rata_rata);
}

void nama_search(struct mahasiswa a_mahasiswa[], int jumlah){
    char nama_input[50];

    printf("================================\n");
    printf("Cari Nama Mahasiswa Baru\n");
    printf("================================\n");
    printf("Masukkan Nama Mahasiswa : ");
    scanf("%c", nama_input);

    int i = 0;
    while (i < jumlah) {
       if (strcmp(nama_input, a_mahasiswa[i].nama) == 0){
           printf("\n");
           print_data(a_mahasiswa[i]);
        }
        i = i + 1;
    }
    getch();
}

void rata_rata_search(struct mahasiswa a_mahasiswa[], int jumlah){
    float rata_rata_input;

    printf("================================\n");
    printf("Cari Nilai Rata-Rata Mahasiswa Baru\n");
    printf("================================\n");
    printf("Masukkan Nilai Rata-Rata Mahasiswa : ");
    scanf("%f", &rata_rata_input);

    int i = 0;
    while (i < jumlah) {
       if (rata_rata_input == a_mahasiswa[i].rata_rata){
           printf("\n");
           print_data(a_mahasiswa[i]);
        }
        i = i + 1;
    }
    getch();
}


int main() {
    struct mahasiswa list_mahasiswa[MAX_MAHASISWA];

    int pilihan;
    int pilihan_2;

    do {
        printf("================================\n");
        printf("Program Mahasiswa Baru IT Telkom\n");
        printf("================================\n");
        printf("1. Input Mahasiswa\n");
        printf("2. Data Mahasiswa\n");
        printf("3. Search Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Masukan Pilihan : ");
        scanf("%d", &pilihan);

        struct mahasiswa a_mahasiswa;

        if (pilihan == 1) {
            a_mahasiswa = input_data();
            list_mahasiswa[jumlah_mahasiswa] = a_mahasiswa;
            ++jumlah_mahasiswa;

        } else if (pilihan == 2) {
            printf("================================\n");
            printf("Data Mahasiswa Baru\n");
            printf("================================\n");
            int i;
            for (i = 0; i < jumlah_mahasiswa; i++) {
                printf("Mahasiswa Ke-%d\n", i+1);
                print_data(list_mahasiswa[i]);
                printf("\n\n");
            }

        } else if (pilihan == 3){
            printf("================================\n");
            printf("Jenis Cari Data Mahasiswa\n");
            printf("================================\n\n");
            printf("1. Berdasarkan Nama\n");
            printf("2. Berdasarkan Nilai rata-rata\n");
            printf("Masukan Pilihan : ");
            scanf("%d", &pilihan_2);

            if (pilihan_2 == 1){
                nama_search(list_mahasiswa, jumlah_mahasiswa);

            } else if (pilihan_2 == 2){
                rata_rata_search(list_mahasiswa, jumlah_mahasiswa);
            }
        }

    } while (pilihan != 4);

    return 0;
}