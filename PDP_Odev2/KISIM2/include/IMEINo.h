/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* IMEINo tanımlamalar ve metotları oluşturduğumuz başlık dosyası
* </p>
*/
#ifndef IMEINO_H
#define IMEINO_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

struct IMEINO{
	
	int* IMEINoDizi;
    int tekToplam;
    int ciftToplam;
    char *IMEINoC;
	
	char* (*imei) (struct IMEINO*);
	char* (*dogrula) (char*);
	void (*yoket) (struct IMEINO*);
};

typedef struct IMEINO* IMEINo;

IMEINo IMEINoOlustur();
char* IMEINoUret(const IMEINo);
char* IMEINoDogrula(char* IMEINo);
void IMEINoYoket(IMEINo);


#endif