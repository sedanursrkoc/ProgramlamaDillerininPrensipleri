/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* Kişi bilgilerini derleyerek rastgele kişi oluşturan sınıf
* </p>
*/
package RASTGELEKISIURET;


public class RastgeleKisi {
    
    private String RastgeleKisi = "";
    
    Kisi kisi = new Kisi();
    
    public RastgeleKisi(){
        
        RastgeleKisi += kisi.KimlikNoDondur(); 
        RastgeleKisi += " ";
        
        RastgeleKisi += kisi.IsimDondur();
        RastgeleKisi += " ";
        
        RastgeleKisi += kisi.YasDondur();
        RastgeleKisi += " ";
        
        RastgeleKisi += kisi.TelefonDondur();
        RastgeleKisi += " (";
        
        RastgeleKisi += kisi.IMEINoDondur();
        RastgeleKisi += ")";
        
    }
    
    public String RastgeleKisiOlustur(){

        return RastgeleKisi;
    }
}
