#include <QDebug>
#include "Splitter.h"
/*!
 * \brief Splitter::Splitter
 * \param pool - потокобезопасная очередь
 * по умолчанию qrunable setAutoDelete = true
 */
Splitter::Splitter(QSharedPointer<DataContainer> pool) :
    _pool(pool)
{
}


Splitter::~Splitter()
{
    _pool.clear();
}

/*!
 * \brief Splitter::setDataToProcess -подготовка данных для обработки
 * \param allString - строка для разбора
 * \param splitter - разделитель
 */
void Splitter::setDataToProcess(QString allString, QString splitter)
{
    _fullString = allString;
    _splitter = splitter;
}

/*!
 * \brief Splitter::run - запуск в отдельном потоке функции обработки строки
 */
void Splitter::run()
{
    split();
}

/*!
 * \brief Splitter::split - функция разбиения строк на подстроки и
 * добавления результатов в очередь
 */
void Splitter::split()
{
    auto list = _fullString.split(_splitter);

    for(auto& s : list)
        _pool->addString(s);
}

