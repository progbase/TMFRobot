<b><font size="6"><p>TheZvezdnaya - TMF Robot(<i>The Most Friendly Robot</i>)</font></b></p>
Рік випуску: 2017<br>
Версія: 1.0.1<br>
Розробник: TheZvezdnaya<br>
Платформа: Windows<br>

<b><font size="6"><p>Складання схеми Arduino:</font></b></p>
Якщо Ви перший раз працюєте з Arduino, наша команда радить наступний <a href="https://www.youtube.com/watch?v=bO_jN0Lpz3Q">гайд</a> для новачків.<br>
Для підключення LCD(<i>Liquid-Crystal Display</i>)-модуля потрібно виконати наступні кроки:<br>
  1. Закріпити екран на breadboard.<br>
  2. Провід типу RX підключити до піна №1 плати Arduino.<br>
  3. Провід типу TX підключити до піна №2 плати Arduino.<br>
  4. Провід DB4 підключити до піна №11 плати Arduino.<br>
  5. Провід GND підключити до піна GND плати Arduino.<br>
  6. Підключити провід +5V до піна типу VIN.<br>
<p>Детальніше про підключення та використання LCD-модуля можна дінатись <a href="https://www.arduino.cc/en/Tutorial/LiquidCrystalDisplay">тут</a>.<br>
Одним із основних джерел інформації був <a href="http://zelectro.cc/LCD1602">сайт</a>.<br>
Детальний гайд знаходиться <a href = "http://www.instructables.com/id/Connecting-an-LCD-to-the-Arduino/">тут.</a></p>
<b><font size="6"><p>Завантаження коду на плату Arduino UNO:</font></b></p>
Для завантаження коду необхідно:<br>
  1. Мати в наявності текстовий редактор Arduino IDE (<b>important:</b>>=2.4).<br>
  2. Відкрити <a href="https://github.com/Dmitriy-Blahodatnyi/TheZvezdnaya/blob/master/docs/facedetect.ino">файл</a> у Arduino IDE.<br>
  3. Підключити плату до комп'ютера за допомогою USB-кабеля.<br>
  4. Завантажити код на плату за допомогою клавіші "Upload" або комбінації клавіш "Ctrl+U".<br>
<p>Детальніше про <a href="https://www.arduino.cc/en/main/software">Arduino IDE</a>.</p>
<b><font size="6"><p>Запуск програми для слідкування за лицем:</font></b></p>
  1. Необхідно встановити<a href="http://www.codeblocks.org/downloads/26"> Code Blocks IDE (Windows Edition)</a>.<br>
  2. Запустити <a href="https://github.com/Dmitriy-Blahodatnyi/TheZvezdnaya/tree/master/docs">даний код</a> в редакторі.<br><br>
<b><font size="6"><p>Використання програми:</font></b></p>
  При коректному встановленні коду на ArduinoUNO та запуску програми розпізнавання обличчя виконуємо наступні кроки:<br>
  1. Вмикнути робота та навести його камеру на своє лице.<br>
  2. Водити лицем.<br>
  <p><a href="https://drive.google.com/file/d/0B-IV8S1DMKF-dW1lc01tczBsVWM/view">Відео</a></p>
