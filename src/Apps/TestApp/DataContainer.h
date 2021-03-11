#ifndef DATACONTAINER_H
#define DATACONTAINER_H

#include <QMutexLocker>
#include <QQueue>

class DataContainer
{
    //очередь для хранения разделенных строк
    QQueue<QString> _queue;

    //мьютекс для синхронизации доступа
    QMutex _mutex;

public:
    DataContainer() = default;
    virtual ~DataContainer() = default;
    /*!
     * \brief addString - добавление элемента
     * \param str - значение подстроки
     */
    void addString(QString str);
    /*!
     * \brief getAll - получение всех подстрок
     * \return массив подстрок
     */
    QVector<QString> getAll();
};

#endif // DATACONTAINER_H
