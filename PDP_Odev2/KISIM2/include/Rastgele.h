/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Rastgele tanımlamalar ve metotları oluşturduğumuz başlık dosyası
* </p>
*/
#ifndef RASTGELE_H
#define RASTGELE_H

#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include "unistd.h"

struct RASTGELE{
	int deger;
    int sonuc;
    int max;
	struct timeval time;
	
	int (*rastgele) (struct RASTGELE*);
	void (*yoket) (struct RASTGELE*);
};

typedef struct RASTGELE* Rastgele;

Rastgele RastgeleOlustur();
int RastgeleSayiUret(const Rastgele);
void RastgeleYoket(Rastgele);


#endif