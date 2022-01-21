#include <stdio.h>
#include <stdlib.h>

void bungaTetap (int pinjam, int bunga, int tahun, int *total){
	*total = (((pinjam * bunga / 100)/12) * tahun * 12);
}

void hitungAngsuran (int pinjam, int bunga, int tahun, int *total, long int *angsuran){
	int cicilanPokok;
	cicilanPokok = pinjam / (tahun * 12);
	
	int bunga_Bulan;
	bunga_Bulan = ((pinjam * bunga / 100)/12);
	
	*angsuran = cicilanPokok + bunga_Bulan;
}

int main(){
	/*
	Total Bunga = Jumlah pinjaman x (Suku bunga per tahun / 12) x Lama meminjam dalam bulan.
	Angsuran = 
	pinjaman / lama minjam (bulan)
	+
	bunga = (pinjaman x suku bunga/100) / 12
	
	*/
	
	long int pinjam;
	int bunga;
	int tahun;
	int total;
	long int angsuran;
	
	printf("============================\n");
	printf("	Program Bunga Tetap		\n");
	printf("============================\n");
	printf("Masukkan Uang Di pinjam : ");
	scanf("%ld", &pinjam);
	
	printf("Masukkan suku bunga Per-tahun : ");
	scanf("%d", &bunga);
	
	printf("Masukkan Kurun Waktu Berapa Tahun : ");
	scanf("%d", &tahun);
	
	bungaTetap(pinjam, bunga, tahun, &total);
	printf("\nHasil Total Bunga : %d\n", total);
	
	hitungAngsuran(pinjam, bunga, tahun, &total, &angsuran);
	printf("Angsuran Harus Dibayar tiap Bulan Sebesar : Rp. %ld", angsuran);
	
}
