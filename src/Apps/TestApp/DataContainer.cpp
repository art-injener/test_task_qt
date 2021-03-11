#include "DataContainer.h"
#include <QVector>

/*!
 * \brief DataContainer::addString - добавление строки
 * \param str - подстрока для добавления
 */
void DataContainer::addString(QString str)
{
    QMutexLocker lock(&_mutex);
    _queue.enqueue(str);
}

/*!
 * \brief DataContainer::getAll - получение всех
 * \return массив подстрок
 */
QVector<QString> DataContainer::getAll()
{
     QMutexLocker lock(&_mutex);
     QVector<QString> v = _queue.toVector();
     _queue.clear();
     return v;
}
