#ifndef OSINTERACT_H
#define OSINTERACT_H
#include <QClipboard>
#include <QGuiApplication>
#include <QString>

class OsInteract
{
public:
    OsInteract();
    void copyToClipboard(const QString &string);

private:
    QString m_copiedString;
};

#endif // OSINTERACT_H
