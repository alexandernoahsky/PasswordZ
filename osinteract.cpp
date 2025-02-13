#include "osinteract.h"


OsInteract::OsInteract() {}

void OsInteract::copyToClipboard(const QString &string)
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(string);
}
