#ifndef IWORKER_H
#define IWORKER_H

#include <QObject>
#include <QSharedPointer>
#include "ILogger.h"
/*!
 * \brief The IWorker class
 *  Интерфейс класса получения и обработки данных
 * \author Данильченко Артём
 */

class IWorker: public QObject
{
   Q_OBJECT

public:
    virtual ~IWorker(){}
    /*!
     * \brief setLogger - внедрение зависимости модуля логгирования
     */
    virtual void setLogger(ILogger*) = 0;
    /*!
     * \brief abortExec - прекращение выполения цикла обработки данных
     */
    virtual void abortExec() = 0;
    /*!
     * \brief setTimeout задание периода съема и обработки данных
     * \param msleep - время в мс
     */
    virtual void setTimeout(uint64_t msleep) = 0;

public slots:
    /*!
    * \brief exec запуск цикла получения и обработки данных
    */
   virtual void exec() = 0;

signals:
    /*!
     * \brief finished сигнал выхода из цикла обработки данных
     */
    void finished();

};
#endif // IWORKER_H
