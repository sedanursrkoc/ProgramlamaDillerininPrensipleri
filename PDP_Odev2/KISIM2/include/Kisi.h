/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Kisi tanımlamalar ve metotları oluşturduğumuz başlık dosyası
* </p>
*/
#ifndef KISI_H
#define KISI_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "KimlikNo.h"
#include "Telefon.h"
#include "IMEINo.h"

struct KISI{
	KimlikNo kimlikNesne;
	Telefon telefonNesne;
	IMEINo imeiNesne;
	
	FILE *dosya; 
	char *kisiIsim;
	char *KimlikNoString;
	char *TelefonString;
	char *IMEINoString;
	
	
	char* (*kimlik) (struct KISI*);
	char* (*isim) (struct KISI*);
	int (*yas) (struct KISI*);
	char* (*telefon) (struct KISI*);
	char* (*imei) (struct KISI*);
	void (*yoket) (struct KISI*);
};

typedef struct KISI* Kisi;

Kisi KisiOlustur();
char* KimlikNoDondur(const Kisi);
char* IsimDondur(const Kisi);
int YasDondur();
char* TelefonDondur(const Kisi);
char* IMEINoDondur(const Kisi);
void KisiYoket(Kisi);


#endif