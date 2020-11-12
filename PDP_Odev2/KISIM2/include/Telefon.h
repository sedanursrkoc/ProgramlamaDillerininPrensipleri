/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Telefon tanımlamalar ve metotları oluşturduğumuz başlık dosyası
* </p>
*/
#ifndef TELEFON_H
#define TELEFON_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

struct TELEFON{
	
	int *TelefonNumarasi;
	char *TelefonC;
	
	char* (*telefon) (struct TELEFON*);
	void (*yoket) (struct TELEFON*);
};

typedef struct TELEFON* Telefon;

Telefon TelefonOlustur();
char* TelefonUret(const Telefon);
void TelefonYoket(Telefon);


#endif

