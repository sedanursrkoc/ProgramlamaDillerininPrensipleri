/**
*
* @author Sedanur Sarıkoç(sedanur.sarikoc@ogr.sakarya.edu.tr), Merve Sarı(merve.sari3@ogr.sakarya.edu.tr)
* @since 13.04.2020
* <p>
* RASTGELEKISIURET kütüphanesini test eden program
* (Rastgele kişi üreterek bunları kişiler dosyasına yazar ve bu dosyadaki kişilere ait kimlik no ve IMEI no kontrolünü yapar)
* </p>
*/
package odev2test;

import java.io.*;
import java.util.Scanner;
import RASTGELEKISIURET.RastgeleKisi;
import RASTGELEKISIURET.KimlikNo;
import RASTGELEKISIURET.IMEINo;

public class RASTGELEKISIURET_TEST {

    
    public static void main(String[] args) throws IOException {
        
        int sec = 1;
        do{ //Çıkış işlemi seçilene kadar programın devam etmesi için koşullu döngü
                Scanner reader = new Scanner(System.in);

        System.out.println("[1] Rastgele Kişi Üret");
        System.out.println("[2] Üretilmiş Dosya Kontrol Et");
        System.out.println("[3] Cikis");
        System.out.print("Secim:");
        sec = reader.nextInt();
        
        

        switch(sec){ //Menüden seçilen işleme göre gerekli işlemlerin gerçekleştirilmesi  
            case 1:

                FileWriter kisiler = new FileWriter("Kisiler.txt");

                System.out.print("Kaç adet kişi üretilecek?: ");

                int KisiSayi = reader.nextInt();

                for (int i = 0; i < KisiSayi; i++) { //Rastgele kişi oluşturarak kişilerin bilgilerini dosyaya yazdırma
                     RastgeleKisi rastgeleKisi = new RastgeleKisi();
                     kisiler.write(rastgeleKisi.RastgeleKisiOlustur() + "\n");
                }

                kisiler.close();
            break;
            case 2:
                
                try{
                    
                    File myObj = new File("Kisiler.txt");
                    Scanner myReader = new Scanner(myObj);
                    Scanner myReader2 = new Scanner(myObj);
                    String data = "";
                    String[] Kelime = new String[5];
                    int temp = 0;
                    int kisiSayi = 0;
                    
                    KimlikNo kimlikNo = new KimlikNo();
                    IMEINo imeiNo = new IMEINo();
                    
                    do{ //Kisiler.txt dosyasının satırlarının okunarak satır sayısının hesaplanması ve kişi sayısının oluşturulması
                        data = myReader2.nextLine();

                        kisiSayi++;
                    }while(myReader2.hasNextLine());
                    
                    
                    String[] KimlikNolari = new String[kisiSayi];
                    String[] IMEINolari = new String[kisiSayi];
 
                    do{ //Kisiler.txt dosyasının satırlarının boşluğa göre kelimelere ayrılarak herbir satırdaki kimlik ve IMEI numaralarının ilgili dizilere atanması
                        data = myReader.nextLine();
                        
                        
                        Kelime = data.split(" ");
                        KimlikNolari[temp] = Kelime[0];
                        IMEINolari[temp] = Kelime[Kelime.length - 1];

                        temp++;
                    }while(myReader.hasNextLine()); 
                   
                    int gecerliKimlik = 0 ;
                    int gecerliIMEI = 0 ;
                    int gecersizKimlik = 0 ;
                    int gecersizIMEI = 0 ;
                    
                    for (int i = 0; i < temp; i++) { //Kimlik numaralarının doğrulama yapılması kaç tanesinin geçerli olup olmadığının bulunması
                        
                        if (kimlikNo.KimlikNoDogrula(KimlikNolari[i]) == "Gecerli") {
                            gecerliKimlik++;
                        }
                        else
                            gecersizKimlik++;
                    }
                    System.out.println("T.C. Kimlik Kontrol \n" + gecerliKimlik + "\t Gecerli \n" + gecersizKimlik + "\t Gecersiz \n");
                    
                    for (int i = 0; i < temp; i++) { //IMEI numaralarının doğrulama yapılarak kaç tanesinin geçerli olup olmadığının bulunması
                        
                        if (imeiNo.IMEIKontrol(IMEINolari[i]) == "Gecerli") {
                            gecerliIMEI++;
                        }
                        else
                            gecersizIMEI++;
                    }
                    System.out.println("IMEI  Kontrol \n" + gecerliIMEI + "\t Gecerli \n" + gecersizIMEI + "\t Gecersiz \n");
                    
                }
                catch(Exception e){ 
                    e.printStackTrace();
                }
            break;
            case 3:
                break;
            default:
                System.out.println("Yanlis tercih!");
            break;
        }

        }while(sec != 3);
    }
    
}
