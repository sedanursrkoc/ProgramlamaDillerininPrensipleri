/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* Rastgele sayı üreten sınıf
* </p>
*/
package RASTGELEKISIURET;

public class Rastgele {
    
    private int deger;
    private int sonuc;
    private int max = 32767;

    public Rastgele(){
        deger = (int)(System.nanoTime());
    }

    public int RastgeleSayiUret(){
        deger = (deger * deger + deger) % 32767;

        if (deger < 0) //Sadece pozitif sayı üretilmek istendiği için sayı negatifse pozitife çevrilir
        {
           deger *= -1;
        }

        sonuc = deger % max;

        return sonuc; 
    }
    
}
