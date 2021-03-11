#include <QThreadPool>
#include <QDebug>
#include <QDir>

#include "DataWorker.h"
#include "Splitter.h"
#include "DataContainer.h"

/*!
 * \brief DataWorker::DataWorker обработчик данных
 * \param filesPath - директория для сканирования
 * \param fileNameToWrite - файл для записи
 */

DataWorker::DataWorker(const QString &filesPath, const QString &fileNameToWrite) :
    _files(filesPath),
    _fileNameToWrite(fileNameToWrite)
{
    _container =  QSharedPointer<DataContainer> (new DataContainer());
}

DataWorker::~DataWorker()
{
    _container.clear();
}

/*!
 * \brief DataWorker::exec
 * основной метод обработки данных
 * Производится сканирование директории.
 * Для каждой строки и разделителя из файла запускается
 * отдельный поток, который производит разбиение на подстроки.
 * Полученные подстроки записываются в потокобезопасную очередь.
 * По окончании обработки файла,значения из очереди записываются в файл
 */
void DataWorker::exec()
{
    //подготовка файловых путей для обработки
    QDir currentDir(_files);
    QStringList listFiles = currentDir.entryList(QStringList() << "*.txt" << "*.TXT",QDir::Files);

    QString fullFileNameToWrite = currentDir.absolutePath()+"/"+_fileNameToWrite;

    QFile file(fullFileNameToWrite);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"error open file" << file.errorString()<<fullFileNameToWrite;
        return;
    }

    QTextStream out(&file);

    //цикл обработки файлов
    foreach(QString filename, listFiles)
    {
        if (filename == _fileNameToWrite)
            continue;

        qDebug()<<"start process file with name = "<<filename;

        processData(currentDir.absoluteFilePath(filename));

        QVector<QString> vectorStrings = _container->getAll();

        out << "[ " << filename << " ]" << "\n";
        for(auto & s: vectorStrings){
            out << s << "\n";
        }

    }

    qDebug()<<"all files processed. Write to " << fullFileNameToWrite;
    file.flush();
    file.close();
}

bool DataWorker::processData(const QString& filename)
{

    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"error open file" << file.errorString()<<filename;
        return false;
    }

    QTextStream in(&file);
    QString baseString = in.readLine();
    while (!in.atEnd()) {
        QString line = in.readLine();

        //класс будет автоматически удален, после завершения потока
        Splitter* splitter = new Splitter(_container);
        splitter->setDataToProcess(baseString,line);
        QThreadPool::globalInstance()->start(splitter);
    }

    //ожидание завершения всех потоков
    QThreadPool::globalInstance()->waitForDone();

    file.close();
    return true;
}
