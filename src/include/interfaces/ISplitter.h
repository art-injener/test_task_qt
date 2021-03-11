
#ifndef ISPLITTER_H
#define ISPLITTER_H

#include <QVector>
#include <QRunnable>
#include <QByteArray>
#include <QSharedPointer>

class ILogger;

/*!
    \brief Интерфейсный класс для обработчиков
    Наследуется от QRunnable, может быть запущен в отдельном потоке

    \author Данильченко Артем
*/
class ISplitter :  public QRunnable
{
public:
    virtual ~ISplitter(){}
    /*!
     *  \brief внедрение зависимости модуля логгирования
     */
    virtual void setLogger(QSharedPointer<ILogger> log) = 0;
    /*!
     * \brief setDataToProcess - подготовка данных для обработки
     * \param allString - исходная строка
     * \param splitter - разделитель
     */
    virtual void setDataToProcess(QString allString, QString splitter) = 0;
    virtual void split() = 0;
};

#endif // IDEMODULATOR_H
