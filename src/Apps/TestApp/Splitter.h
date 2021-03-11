
#ifndef SPLITTER_H
#define SPLITTER_H

#include <QSharedPointer>
#include <QRunnable>

#include "interfaces/ISplitter.h"

#include "interfaces/ILogger.h"

#include "DataContainer.h"

class Splitter : public ISplitter
{
    // очередь для хранения подстрок
    QSharedPointer<DataContainer> _pool;
    //строка для разбора
    QString _fullString;
    //разделитель
    QString _splitter;

public:
    /*!
     * \brief Splitter конструтор
     * \param pool - потокабезопасная очередь для хранения результатов
     */
    Splitter(QSharedPointer<DataContainer> pool);
    ~Splitter() override;

    /*!
     * \brief setLogger - DI логгера
     */
    void setLogger(QSharedPointer<ILogger>) override {}
    /*!
     *  \brief установка данных для обработки
     *  \param allString - строка для разбора
     *  \param splitter - разделитель
     */
    void setDataToProcess(QString allString, QString splitter) override;
    /*!
     *  \brief основной метод выполнения обработки
     */
    void run() override;

public:
    /*!
     * \brief split - функция разбиения данных
     */
    void split() override;
};

#endif // DEMODULATOR_H
