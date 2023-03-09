# so_long

  Ecol42 projelerinden biri olan so_long da bizden 2d bir oyun yapmamız isteniyor. Oyunda karakterimizin toplanabilir tüm nesneleri topladıktan sonra
oyunu çıkış noktasından terk edebilmelidir.

<img width="768" alt="Screen Shot 2023-03-09 at 12 57 30" src="https://user-images.githubusercontent.com/115617420/223987356-cd2143ad-f123-4008-8b34-d0ce856f8c92.png">

Uymamız Gereken Kurallar:
- Minilibix kütüphanesini kullanmalıyız
- Haritada olması gereken bileşenler:
  - oyuncu ( P )
  - boş alan ( 0 )
  - duvarlar ( 1 )
  - toplanabilir nesne ( C )
  - cıkış noktası ( E )
- Harita duvarlarla çevrili olmalı ve oyuncu duvarda hareket edemez
- oyuncu tüm toplanabilir nesneleri toplamadan oyunu çıkış noktasından terk edemez
- Her hareketten sonra güncel hareket sayısı ekrana bastırılmalıdır
- Eğer map tamamlanamaz durumdaysa oyunu başlatamaz( çıkış yolu duvarlarla kaplıysa veya toplanabilir nesnelerin hepsi toplanamaz durumdaysa)
  
Geçerli bir harita örneği:
“`
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
“`

Oyunu Nasıl Çalıştırabilirim
  "make" yaptıktan sonra "./so_long maps.map1.ber" ile oyunu çalıştırabilirsin 
