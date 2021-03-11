#ifndef DATAWORKER_H
#define DATAWORKER_H

#include <atomic>

#include "interfaces/IWorker.h"
#include "interfaces/ISplitter.h"
#include "DataContainer.h"

/*!
 * \brief The DataWorker class
 * Реализация интерфейса получения и обработки данных
 * \author Данильченко Артём
 */
class DataWorker : public IWorker
{
    Q_OBJECT
    //контейнер для хранения подстрок
    QSharedPointer<DataContainer> _container;
    //класс обработчик данных
    QSharedPointer<ISplitter> _splitter;

protected:
    //директория для сканирования
    QString _files;
    //имя файла для записи
    QString _fileNameToWrite;
    /*!
     * \brief processData  обработка данных
     * \return результат операции
     */
    bool processData(const QString &filename);

public:

    DataWorker(const QString & filesPath, const QString &fileNameToWrite);

    ~DataWorker() override;
    /*!
     * \brief setLogger - внедрение зависимости модуля логгирования
     */
    void setLogger(ILogger*) override {}

    /*!
     * \brief abortExec - прекращение выполения цикла обработки данных
     */
    void abortExec() override {}
    /*!
     * \brief setTimeout заглушка
     */
    void setTimeout(uint64_t) override {}

public slots:
    /*!
    * \brief exec запуск цикла получения и обработки данных
    */
    void exec() override;
};

#endif // DATAWORKER_H
