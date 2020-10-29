#include <LiquidCrystal_I2C.h>



#include "DHT.h"
#include <iarduino_RTC.h>






iarduino_RTC time(RTC_DS1307);      // what is it???

#define DHTPIN 8
#define DHTTYPE DHT22
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
DHT dht(DHTPIN, DHTTYPE);   // what is it???
const int buttonupPin = 9 ;
const int buttonsetPin = 10 ;
const int buttondownPin = 11  ;

boolean buttonpress;

LiquidCrystal_I2C lcd(0x27, 16, 2);
// узнать что такое старшие и младшие биты у lcd
int buttonupState = 0;
int buttondownState = 0;
int buttonsetState = 0;

char v ;

unsigned long timenow;
void setup()
{
  pinMode(buttonupPin , INPUT_PULLUP);
  pinMode(buttondownPin, INPUT_PULLUP);
  pinMode(buttonsetPin, INPUT_PULLUP);
  delay(300);
  Serial.begin(9600);  // определение скорости порта
  time.begin();
 
  lcd.begin();
  dht.begin();
  lcd.backlight();
//  time.settime(0,1,15,25,10,2020,0);
}
void loop() {
  int h = dht.readHumidity();    //  float это переменная с плавающей точкой
  int t = dht.readTemperature();
//if (v==0)
// {
  lcd.setCursor(0, 0);
  lcd.print(time.gettime("d-m"));
  lcd.setCursor(8, 0);
  lcd.print(time.gettime( "H:i:s"));
  Serial.println(time.gettime( "H:i:s"));
  lcd.setCursor(1, 1);
  lcd.print("T:");
  lcd.print(t);
  lcd.print("C");
  lcd.setCursor(8, 1);
  lcd.print("H:");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(5,0);
  lcd.print("   ");
   lcd.setCursor(6,1);
  lcd.print("  ");
   lcd.setCursor(13,1);
  lcd.print("    ");



// }
     

//  
//  
//  
//    if (!digitalRead(buttonsetPin))
//    {
//      buttonpress=true;
//      delay(1);
//    }
//    if(digitalRead(buttonsetPin) && buttonpress){
//      v = v + 1 ;
//      if (v>5)
//      v=0 ;
//      buttonpress=false;
//    }
//    
//    if (!digitalRead(buttonupPin))
//      switch (v) {
//        case (1):
//
//          Serial.println("butUP");
//          time.gettime();
//         // if ((time.minutes + 1) > 59)
//            //time.settime(-1, 0, -1, -1, -1, -1);
//        //  else 
//        time.settime(-1, time.minutes + 1, -1, -1, -1, -1);
//          break;
//        case (2):
//        
//         
//          time.gettime();
//          if ((time.Hours + 1) > 23)
//            time.settime(-1, -1, 0, -1, -1, -1);
//          else time.settime(-1, -1, time.Hours + 1,  -1, -1, -1);
//          break;
//        case (3):
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//         
//          time.gettime();
//          if ((time.day + 1) > 31)
//            time.settime(-1, -1, -1, 0, -1, -1);
//          else time.settime(-1, -1, -1, time.day + 1,  -1, -1);
//          break;
//        case (4):
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//         
//          time.gettime();
//          if ((time.month + 1) > 12)
//            time.settime(-1, -1, -1, -1, 1, -1);
//          else time.settime(-1, -1, -1, -1, time.month + 1,   -1);
//          break;
//        case (5):
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//          
//          time.gettime();
//          if ((time.year + 1) > 70)
//            time.settime(-1, -1, -1, -1, -1 , 10);
//          else time.settime(-1, -1, -1, -1, -1, time.year + 1 );
//          break;
//        
//      }
//      if (!digitalRead(buttondownPin))
//      switch (v) {
//        case (1):
//
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//          
//          time.gettime();
//          if ((time.minutes - 1) < 0)
//            time.settime(-1, 59, -1, -1, -1, -1);
//          else time.settime(-1, time.minutes - 1, -1, -1, -1, -1);
//          break;
//        case (2):
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//          //1   мигают сек
//          //  2   мигают мин
//          //  3   мигают час
//          //  4   мигают дни
//          //  5   мигают мес
//          //  6   мигает год
//          //  7   мигают дни недели
//          //  8   мигает полдень
//          time.gettime();
//          if ((time.Hours - 1)<0)
//            time.settime(-1, -1, 23, -1, -1, -1);
//          else time.settime(-1, -1, time.Hours - 1,  -1, -1, -1);
//          break;
//        case (3): // если v == 3 
//          time.gettime();
//          if ((time.day - 1) < 1)
//            
//            time.settime(-1, -1, -1, 31, -1, -1);
//          else time.settime(-1, -1, -1, time.day - 1,  -1, -1);
//          break;
//        case (4):
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//          time.gettime();
//          if ((time.month - 1) < 1)
//            time.settime(-1, -1, -1, -1, 12, -1);
//          else time.settime(-1, -1, -1, -1, time.month - 1,   -1);
//          break;
//        case (5):
//          //  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//         
//          time.gettime();
//          if ((time.year - 1) <10)
//            time.settime(-1, -1, -1, -1, -1 , 70);
//          else time.settime(-1, -1, -1, -1, -1, time.year - 1 );
//          break;
//        
//      }
// 
//  switch (v) { 
//    case (1):
//    time.blinktime(2);
//       lcd.setCursor(0,1);
//  lcd.print(" ");
//     lcd.setCursor(0,0);
//  lcd.print(" ");
//    lcd.setCursor(9,0);
//  lcd.print("       ");
//    lcd.setCursor(9,1);
//  lcd.print("  ");
//      lcd.setCursor(1,0);
//      lcd.print(time.gettime("H:i:s"));
//      lcd.setCursor(1,1);
//      lcd.print(time.gettime("d-m-y"));
//    lcd.setCursor(11,1);
//    lcd.print("MIN");
//    break;
//    case (2):
//    time.blinktime(3);
//         lcd.setCursor(0,1);
//  lcd.print(" ");
//     lcd.setCursor(0,0);
//  lcd.print(" ");
//    lcd.setCursor(9,0);
//  lcd.print("       ");
//    lcd.setCursor(9,1);
//  lcd.print("  ");
//      lcd.setCursor(1,0);
//      lcd.print(time.gettime("H:i:s"));
//      lcd.setCursor(1,1);
//      lcd.print(time.gettime("d-m-y"));
//    lcd.setCursor(11,1);
//    lcd.print("HOUR");
//    break;
//    case (3):
//    time.blinktime(4);
//           lcd.setCursor(0,1);
//  lcd.print(" ");
//     lcd.setCursor(0,0);
//  lcd.print(" ");
//    lcd.setCursor(9,0);
//  lcd.print("       ");
//    lcd.setCursor(9,1);
//  lcd.print("  ");
//      lcd.setCursor(1,0);
//      lcd.print(time.gettime("H:i:s"));
//      lcd.setCursor(1,1);
//      lcd.print(time.gettime("d-m-y"));
//    lcd.setCursor(11,1);
//    lcd.print("DATE");
//    break;
//    case (4):
//    time.blinktime(5);
//          lcd.setCursor(0,1);
//  lcd.print(" ");
//     lcd.setCursor(0,0);
//  lcd.print(" ");
//    lcd.setCursor(9,0);
//  lcd.print("       ");
//    lcd.setCursor(9,1);
//  lcd.print("  ");
//      lcd.setCursor(1,0);
//      lcd.print(time.gettime("H:i:s"));
//      lcd.setCursor(1,1);
//      lcd.print(time.gettime("d-m-y"));
//    lcd.setCursor(11,1);
//    lcd.print("MONTH");
//    break;
//    case (5):
//    time.blinktime(6);
//          lcd.setCursor(0,1);
//  lcd.print(" ");
//     lcd.setCursor(0,0);
//  lcd.print(" ");
//    lcd.setCursor(9,0);
//  lcd.print("       ");
//    lcd.setCursor(9,1);
//  lcd.print("  ");
//    lcd.setCursor(15,1);
//  lcd.print(" ");
//      lcd.setCursor(1,0);
//      lcd.print(time.gettime("H:i:s"));
//      lcd.setCursor(1,1);
//      lcd.print(time.gettime("d-m-y"));
//    lcd.setCursor(11,1);
//    lcd.print("YEAR");
//    break;
//  }
//  // time.period(1);
   
  }








//    ОПИСАНИЯ ПАРАМЕТРОВ ФУНКЦИЙ:
//
//  Подключение библиотеки:
//  #include <iarduino_RTC.h>
//  iarduino_RTC time(название модуля [, вывод SS/RST [, вывод CLK [, вывод DAT]]]);
//      если модуль работает на шине I2C или SPI, то достаточно указать 1 параметр, например: iarduino_RTC time(RTC_DS3231);
//      если модуль работает на шине SPI, а аппаратный вывод SS занят, то номер назначенного вывода SS для модуля указывается вторым параметром, например: iarduino_RTC time(RTC_DS1305,22);
//      если модуль работает на трехпроводной шине, то указываются номера всех выводов, например: iarduino_RTC time(RTC_DS1302, 1, 2, 3); // RST, CLK, DAT
//
//  Для работы с модулями, в библиотеке реализованы 5 функции:
//      инициировать модуль  begin();
//      указать время        settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]);
//      получить время       gettime("строка с параметрами");
//      мигать времем        blinktime(0-не_мигать / 1-мигают_сек / 2-мигают_мин / 3-мигают_час / 4-мигают_дни / 5-мигают_мес / 6-мигает_год / 7-мигают_дни_недели / 8-мигает_полдень)
//      разгрузить шину      period (минуты);
//
//  Функция begin():
//      функция инициирует модуль: проверяет регистры модуля, запускает генератор модуля и т.д.
//
//  Функция settime(секунды [, минуты [, часы [, день [, месяц [, год [, день недели]]]]]]):
//      записывает время в модуль
//      год указывается без учёта века, в формате 0-99
//      часы указываются в 24-часовом формате, от 0 до 23
//      день недели указывается в виде числа от 0-воскресенье до 6-суббота
//      если предыдущий параметр надо оставить без изменений, то можно указать отрицательное или заведомо большее значение
//      пример: settime(-1, 10); установит 10 минут, а секунды, часы и дату, оставит без изменений
//      пример: settime(0, 5, 13); установит 13 часов, 5 минут, 0 секунд, а дату оставит без изменений
//      пример: settime(-1, -1, -1, 1, 10, 15); установит дату 01.10.2015 , а время и день недели оставит без изменений
//
//  Функция gettime("строка с параметрами"):
//      функция получает и выводит строку заменяя описанные ниже символы на текущее время
//      пример: gettime("d-m-Y, H:i:s, D"); ответит строкой "01-10-2015, 14:00:05, Thu"
//      пример: gettime("s");               ответит строкой "05"
//      указанные символы идентичны символам для функции date() в PHP
//  s   секунды                       от      00    до       59  (два знака)
//  i   минуты                        от      00    до       59  (два знака)
//  h   часы в 12-часовом формате     от      01    до       12  (два знака)
//  H   часы в 24-часовом формате     от      00    до       23  (два знака)
//  d   день месяца                   от      01    до       31  (два знака)
//  w   день недели                   от       0    до        6  (один знак: 0-воскресенье, 6-суббота)
//  D   день недели наименование      от     Mon    до      Sun  (три знака: Mon Tue Wed Thu Fri Sat Sun)
//  m   месяц                         от      01    до       12  (два знака)
//  M   месяц наименование            от     Jan    до      Dec  (три знака: Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec)
//  Y   год                           от    2000    до     2099  (четыре знака)
//  y   год                           от      00    до       99  (два знака)
//  a   полдень                               am   или       pm  (два знака, в нижнем регистре)
//  A   полдень                               AM   или       PM  (два знака, в верхнем регистре)
//      строка не должна превышать 50 символов
//
//  если требуется получить время в виде цифр, то можно вызвать функцию gettime() без параметра, после чего получить время из переменных
//      seconds  секунды     0-59
//      minutes  минуты      0-59
//      hours    часы        1-12
//      Hours    часы        0-23
//      midday   полдень     0-1 (0-am, 1-pm)
//      day      день месяца 1-31
//      weekday  день недели 0-6 (0-воскресенье, 6-суббота)
//      month    месяц       1-12
//      year     год         0-99
//
//  Функция blinktime(параметр):
//      указывает функции gettime мигать одним из параметров времени (заменять параметр пробелами)
//      функция может быть полезна, для отображения на дисплее, устанавливаемого параметра времени
//      функция получает один параметр в виде числа от 0 до 8
//  0   не мигать
//  1   мигают сек
//  2   мигают мин
//  3   мигают час
//  4   мигают дни
//  5   мигают мес
//  6   мигает год
//  7   мигают дни недели
//  8   мигает полдень
//
//  Функция period(минуты):
//      устанавливает минимальный период обращения к модулю в минутах (от 0 до 255)
//      функция может быть полезна, если шина сильно нагружена, на ней имеются несколько устройств
//      period(10); период 10 минут, означает что каждые 10 минут к модулю может быть отправлен только 1 запрос на получение времени
//      ответом на все остальные запросы будет результат последнего полученного от модуля времени + время прошедшее с этого запроса

