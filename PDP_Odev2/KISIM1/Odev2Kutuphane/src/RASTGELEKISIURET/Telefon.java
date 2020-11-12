/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* Telefon numarası oluşturan sınıf
* </p>
*/
package RASTGELEKISIURET;

public class Telefon {
    
    private int[] AlanKodlari = {501, 505, 506, 507, 551, 552, 553, 554, 555, 559,530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 561, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549};
    private int[] TelefonNumarasi = new int[9];
    private String Telefon = "";
    
    Rastgele rastgele = new Rastgele();
    
    public Telefon(){
        
        TelefonNumarasi[0] = 0;
        TelefonNumarasi[1] = AlanKodlari[rastgele.RastgeleSayiUret() % 30];
        
        for (int i = 2; i < 9; i++) { //Telefon numarasının ilk basamağı ve alan kodu kısmı hariç diğer basamaklara rastgele sayı atanması
            TelefonNumarasi[i] = rastgele.RastgeleSayiUret() % 9 ;
        }
    }
    
    public String TelefonOlustur(){
    
        for (int i = 0; i < 9; i++) { //Telefon numarası için ürettiğimiz sayıları string bir ifadeye atamak için döngü
            Telefon += TelefonNumarasi[i];
        }
        
        return Telefon; 
    }
}
