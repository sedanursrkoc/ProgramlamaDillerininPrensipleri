/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* KimlikNo tanımlamalar ve metotları oluşturduğumuz başlık dosyası
* </p>
*/
#ifndef KIMLIKNO_H
#define KIMLIKNO_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

struct KIMLIKNO{
	
	int* KimlikNoDizi;
    int tekToplam;
    int ciftToplam;
    char *KimlikNoC;
	
	char* (*kimlik) (struct KIMLIKNO*);
	char* (*dogrula) (char*);
	void (*yoket) (struct KIMLIKNO*);
};

typedef struct KIMLIKNO* KimlikNo;

KimlikNo KimlikNoOlustur();
char* KimlikNoUret(const KimlikNo);
char* KimlikNoDogrula(char* KimlikNo);
void KimlikNoYoket(KimlikNo);


#endif