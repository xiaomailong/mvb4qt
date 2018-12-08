#include "qmvbcard.h"
#include "qlittleendianprotocol.h"
#include "qmvbport.h"

QMvbCard::QMvbCard(QString name, QAbstractMvbDriver *driver, QAbstractMvbProtocol *protocol)
{
    // the register of this mvb card.
    this->mvbRegister = new QMvbRegister();
    this->mvbRegister->setName(name);

    this->driver = driver;
    this->protocol = protocol;

    this->timer = new QTimer(this);
    this->timer->setInterval(100);  // default value is 100ms
    this->connect(timer, SIGNAL(timeout()), this, SLOT(updateMvbSlot()), Qt::AutoConnection);

    this->moveToThread(&(this->thread));
}

QMvbCard::~QMvbCard()
{
    delete this->driver;
    delete this->protocol;
    delete this->timer;
    delete this->mvbRegister;
}

qint32 QMvbCard::getInterval() const
{
    return this->timer->interval();
}

void QMvbCard::setInterval(const qint32 interval)
{
    // if the interval is less than 50ms, set it 50ms.
    if (interval < 50)
    {
       this->timer->setInterval(50);
    }
    else
    {
        this->timer->setInterval(interval);
    }
}

bool QMvbCard::getBool(const qint16 number, const quint8 byte, const quint8 bit)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getBool(this->mvbRegister->getPort(number)->getData(), byte, bit);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setBool(const qint16 number, const quint8 byte, quint8 bit, const bool value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setBool(this->mvbRegister->getPort(number)->getData(), byte, bit, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

qint8 QMvbCard::getQint8(const qint16 number, const quint8 byte)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQint8(this->mvbRegister->getPort(number)->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQint8(const qint16 number, const quint8 byte, const qint8 value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQint8(this->mvbRegister->getPort(number)->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

qint16 QMvbCard::getQint16(const qint16 number, const quint8 byte)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQint16(this->mvbRegister->getPort(number)->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQint16(const qint16 number, const quint8 byte, const qint16 value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQint16(this->mvbRegister->getPort(number)->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

qint32 QMvbCard::getQint32(const qint16 number, const quint8 byte)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQint32(this->mvbRegister->getPort(number)->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQint32(const qint16 number, const quint8 byte, const qint32 value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQint32(this->mvbRegister->getPort(number)->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

quint8 QMvbCard::getQuint8(const qint16 number, const quint8 byte)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQuint8(this->mvbRegister->getPort(number)->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQuint8(const qint16 number, const quint8 byte, const quint8 value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQuint8(this->mvbRegister->getPort(number)->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

quint16 QMvbCard::getQuint16(const qint16 number, const quint8 byte)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQuint16(this->mvbRegister->getPort(number)->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQuint16(const qint16 number, const quint8 byte, const quint16 value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQuint16(this->mvbRegister->getPort(number)->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

quint32 QMvbCard::getQuint32(const qint16 number, const quint8 byte)
{
    if (this->mvbRegister->containPort(number))
    {
        QReadLocker locker(&(this->lock));

        return this->protocol->getQuint32(this->mvbRegister->getPort(number)->getData(), byte);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
        return false;
    }
}

void QMvbCard::setQuint32(const qint16 number, const quint8 byte, const quint32 value)
{
    if (this->mvbRegister->containPort(number))
    {
        QWriteLocker locker(&(this->lock));

        this->protocol->setQuint32(this->mvbRegister->getPort(number)->getData(), byte, value);
    }
    else
    {
        qDebug()<<"No port"<<number<<"in the map";
    }
}

void QMvbCard::start()
{
    this->MvbConfigure->setState(Mvb4Qt::MvbCardStart);

    this->thread.start();
    this->timer.start(this->interval);
    this->driver->start(this->mvbRegister);

    qDebug() << ""
}

void QMvbCard::stop()
{
    this->timer.stop();
    this->thread.terminate();

    this->MvbConfigure->setState(Mvb4Qt::MvbCardStop);
    this->driver->stop(this);
}

void QMvbCard::configure()
{
    this->driver->configure(this->MvbConfigure);
}

void QMvbCard::updateMvbSlot()
{
    foreach(QMvbPort *port, this->portMap.values())
    {
        if (port->getType() == Mvb4Qt::MvbSourcePort)
        {
            QReadLocker loker(&(this->lock));

            this->driver->updatePort(port);
        }
        else if (port->getType() == Mvb4Qt::MvbSinkPort)
        {
            QWriteLocker loker(&(this->lock));

            this->driver->updatePort(port);
        }
    }

    // debug mode, may add a flag to active this function later
    foreach(QMvbPort *port, this->portMap.values())
    {
        QString info;

        info.append(QString::number(port->getNumber(), 16));
        info.append(":");

        for (int i = 0; i < port->getSize(); i ++)
        {
            // info.append(QString::number(*(port->getData() + i), 16));
            info.append(QString::number(this->getQuint8(port->getNumber(), i), 16));
        }

        qDebug() << info << QThread::currentThreadId();
    }
}

QMvbRegister *QMvbCard::mvbRegister()
{
    return this->mvbRegister;
}
