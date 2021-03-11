# Инструкция по сборке:

  0. Окружение:
  
    ubuntu 20.04
    Qt  5.12.8. Для сборки требуется эта версия или же более позняя. 
    Clone from git master branch : git clone https://github.com/art-injener/test_task_qt.git
    
  1. Установка требуемых библиотек :
  
    sudo apt install qt5-default  // или устновить нужную версию с сайта https://www.qt.io/download-qt-installer
    sudo apt install qtcreator 
  4. Перейти в папку test_task_qt/scripts/debug или test_task_qt/scripts/release и выполнить скрипт builder.sh

  5. Для запуска приложений необходимо использовать скрипты startTestApp.sh. Вызов скрипта без параметров выполнит обработку файла в папке /data. Пример вызова с параметрами:
    ./startTestApp.sh /home/user/dir_for_scan fileNameForResult.txt

  6. При запуске через qtCreator ОБЯЗАТЕЛЬНО необходимо отключить теневую сборку.

