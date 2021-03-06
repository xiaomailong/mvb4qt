#include <QDebug>
#include "qmvbport.h"

QMvbPort::QMvbPort(const qint16 number, const quint16 size,
                    const Mvb4Qt::MvbPortType type, const quint16 cycle, QString group)
{
    this->number = number;
    this->size = size;
    this->type = type;
    this->cycle = cycle;
    this->group = group;

    if (this->type == Mvb4Qt::MvbSourcePort)
    {
        this->refresh = cycle;
    }

    this->clear();
}

qint16 QMvbPort::getNumber() const
{
    return this->number;
}

Mvb4Qt::MvbPortType QMvbPort::getType() const
{
    return this->type;
}

qint16 QMvbPort::getSize() const
{
    return this->size;
}

quint16 QMvbPort::getCycle() const
{
    return this->cycle;
}

quint16 QMvbPort::getRefresh() const
{
    return this->refresh;
}

void QMvbPort::setRefresh(const quint16 refresh)
{
    this->refresh = refresh;
}

quint8* QMvbPort::getData() const
{
    return const_cast<quint8*>(this->data);
}

void QMvbPort::clear()
{
    for (qint16 i = 0; i < sizeof(this->data); i ++)
    {
        this->data[i] = 0;
    }
}

QString QMvbPort::getGroup() const
{
    return group;
}

bool QMvbPort::isTimeout() const
{
    if (this->refresh > this->cycle)
    {
        return true;
    }
    else
    {
        return false;
    }
}
