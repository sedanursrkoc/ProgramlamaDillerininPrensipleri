/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 20.04.2020
* <p>
* Rastgele sayı üreten kaynak dosyası
* </p>
*/
#include "Rastgele.h"
#include "stdio.h"
#include "time.h"
#include "unistd.h"

Rastgele RastgeleOlustur(){
    Rastgele this;
    this = (Rastgele)malloc(sizeof(struct RASTGELE));
    this->max = 32767;
 
    do{ //Güncel zamanı alarak değer ataması yapılıp önceki değerden farklı olana kadar zaman ataması yapılması
		gettimeofday(&this->time, NULL);
		this->deger = this->time.tv_usec;
		gettimeofday(&this->time, NULL);
	}while(this->deger == this->time.tv_usec);

    this->rastgele = &RastgeleSayiUret;
    this->yoket = &RastgeleYoket;

    return this;
}

int RastgeleSayiUret(const Rastgele this){
    this->deger = (this->deger * this->deger + this->deger) % 32767;

    if (this->deger < 0) //Sadece pozitif sayı üretilmek istendiği için sayı negatifse pozitife çevrilir
    {
        this->deger *= -1;
    }
    this->sonuc = this->deger % this->max;

    return this->sonuc; 
}

void RastgeleYoket(Rastgele this){
    if(this == NULL) return;
    free(this);
}


