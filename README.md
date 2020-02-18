# Gra w życie
Program działający na płytce STM32F746G-DISCO, będący wizualizacją działania automatu komórkowego 
“Game of Life”. 

## Jak uruchomić?
Aby uruchomić program, należy przygotować następujący sprzęt/oprogramowanie: 
- płytkę STM32F746G-DISCO,
- kabel USB A-miniB do zapewnienia zasilania płytce oraz możliwości jej ewentualnego zaprogramowania, 
- program STM32 ST-Link Utility, który zostanie wykorzystany do przeprowadzenia programowania pamięci Flash mikrokontrolera.

Należy płytkę za pomocą kabla USB połączyć z komputerem. Następnie uruchomić program STM32 ST-Link Utility. Następnie kolejno wybrać w menu opcję Target -> Connect, a następnie w razie powodzenia opcję Target -> Program. W okienku, które się pojawi, należy wpisać ścieżkę do pliku binarnego f7project.bin, znajdującego się w podkatalogu build (lub użyć opcji Browse). Kolejnym krokiem jest wciśnięcie przycisku Start. Po zaprogramowaniu płytki, można wybrać opcję Target -> Disconnect (CTRL+D).

## Autorzy
Mikołaj Sikora, Veranika Yakouchyts

