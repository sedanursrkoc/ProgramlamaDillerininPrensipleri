/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* RastgeleKisi tanımlamalar ve metotları oluşturduğumuz başlık dosyası
* </p>
*/
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

struct RASTGELEKISI{
	
	char *RastgeleKisiBilgileri;
	
	char* (*rastgelekisi) (struct RASTGELEKISI*);
	void (*yoket) (struct RASTGELEKISI*);
};

typedef struct RASTGELEKISI* RastgeleKisi;

RastgeleKisi RastgeleKisiOlustur();
char* RastgeleKisiDondur(const RastgeleKisi);
void RastgeleKisiYoket(RastgeleKisi);


#endif