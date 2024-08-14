Tam Otomatik Kuluçka Makinesi

Proje Açıklaması
Bu proje, bir kuluçka makinesinin otomatik olarak sıcaklık ve nem değerlerini izleyip kontrol eden bir sistemdir. Arduino tabanlı sistem, bir RTC (Gerçek Zamanlı Saat) modülü, bir DHT11 sensörü, bir LCD ekran, bir GSM modülü ve çeşitli kontrol cihazları kullanarak, kuluçka ortamını optimize eder ve düzenli olarak bilgi gönderir. Sistem, belirli koşullara göre fan, ampul ve nozulları kontrol eder ve sıcaklık ve nem bilgilerini SMS ile gönderir.

Donanım Gereksinimleri

Arduino Uno veya benzeri bir kart

virtuabotixRTC Modülü

DHT11 Nem ve Sıcaklık Sensörü

GSM Modülü (SIM900 veya benzeri)

LCD Ekran (I2C destekli)

Fan

Ampul

Nozul (Buharlaşma Kontrolü için)

Motor (Opsiyonel)

Yazılım Gereksinimleri

Arduino IDE: Arduino kartını programlamak için kullanılacaktır.

virtuabotixRTC Kütüphanesi: RTC modülünü kontrol etmek için.

SoftwareSerial Kütüphanesi: GSM modülü ile iletişim kurmak için.

dht11 Kütüphanesi: DHT11 sensöründen veri almak için.

LiquidCrystal_I2C Kütüphanesi: LCD ekran ile iletişim kurmak için.

Kurulum

Donanım Bağlantıları:

RTC Modülünü Arduino'nun 8, 7 ve 6 pinlerine bağlayın.

DHT11 Sensörünü Arduino'nun 9 numaralı pinine bağlayın.

GSM Modülünü Arduino'nun 3 ve 2 numaralı pinlerine bağlayın.

LCD Ekranı Arduino'nun I2C pinlerine bağlayın.

Fan, ampul, nozul ve motoru uygun dijital pinlere bağlayın (10, 11, 12, 13).

Yazılım Yükleme:

Arduino IDE'yi açın.

Kodu Arduino kartınıza yükleyin.

Gerekli kütüphaneleri Arduino IDE'ye ekleyin (virtuabotixRTC, SoftwareSerial, dht11, LiquidCrystal_I2C).

Kod Açıklaması

Başlangıç Ayarları

RTC ve Sensör Kurulumu:

RTC modülü, kuluçka makinesi zamanını ve tarihi ayarlamak için kullanılır.

DHT11 sensörü, ortam sıcaklığı ve nem değerlerini ölçmek için kullanılır.

LCD Ekran:

LCD ekran, kuluçka makinesinin mevcut durumunu görüntüler.

Ana Fonksiyonlar

setup():

Seri iletişimi başlatır.

Pin modlarını ayarlar.

RTC ve LCD ekranı başlatır.

LCD ekranında başlangıç mesajını gösterir.

updateSerial():

Seri portları arasında veri aktarımı sağlar.

mesaj():

SMS gönderme fonksiyonu. DHT11 sensöründen alınan sıcaklık ve nem verilerini GSM modülü aracılığıyla belirlenen telefon numarasına gönderir.

loop():

Zaman ve sensör verilerini günceller.

Sıcaklık ve nem değerlerine göre cihazları kontrol eder (fan, ampul, nozullar).

Her 30 saniyede bir LCD ekranı günceller.

Dakika başına SMS gönderir.

Cihaz Kontrolleri

Sıcaklık Kontrolü:

Sıcaklık 30°C'nin altındaysa ampul açılır, fan kapanır.

Sıcaklık 32°C'nin üstündeyse fan açılır, ampul kapanır.

Nem Kontrolü:

Nem 60%'ın üstündeyse fan açılır, nozul kapanır.

Nem 55%'in altındaysa nozul açılır.

GSM Modülü:

Her dakika başında ve her 30 saniyede bir SMS gönderilir, sıcaklık ve nem bilgilerini içerir.

İletişim

Sorularınız veya geri bildirimleriniz için benimle iletişime geçebilirsiniz:

E-posta: alitokmak3535@gmail.com

GitHub: AlITOKMAK35 - https://github.com/AlITOKMAK35 -

