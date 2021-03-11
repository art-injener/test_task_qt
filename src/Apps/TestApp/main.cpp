#include "DataWorker.h"

#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // парсер аргументов командной строки
    QCoreApplication::setApplicationName("TestTaskApp");
    QCoreApplication::setApplicationVersion("1.0");

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("main",
                                                                 "TestTaskApp"));

    parser.addPositionalArgument("dir",
                                 QCoreApplication::translate("main",
                                                             "dir for scan"));
    parser.addPositionalArgument("fileName",
                                 QCoreApplication::translate("main",
                                                             "file name for write"));
    parser.process(a);
    const QStringList args = parser.positionalArguments();

    // формирование строки и имени файла для обработки
    QDir currentDir;
    QString fileName = "split.txt";

    if(!args.isEmpty() && args.size() == 2)
    {
        if (!currentDir.cd(args.at(0)))
        {
            qDebug()<< "can't cd to : "<< args.at(0)<< " switch to ./data path";
            currentDir.cd("../../../data");
        }
        fileName = args.at(1);
    }
    else
    {
        currentDir.cd("../../../data");
        qDebug()<<"use default path : " <<  currentDir.path();
    }

    qDebug()<< "start scan dir "<< currentDir.path() << " write result to "<< fileName;

    //запуск обработки
    DataWorker dataWorker(currentDir.path(), fileName);
    dataWorker.exec();

    return a.exec();
}
