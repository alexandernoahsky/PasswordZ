#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "passwordgen.h"
#include "osinteract.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();

    void on_passLengthEdit_textEdited(const QString &arg1);

    void on_specialCharsAllowedCheckbox_toggled(bool checked);

    void on_clipboardCopyButton_clicked();

    void on_excludeCharactersLineEditBox_textEdited(const QString &arg1);

    void on_allowUppercaseCheckbox_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    //smart pointer objects
    std::unique_ptr<PasswordGen> m_passwordGen = std::make_unique<PasswordGen>();
    std::unique_ptr<OsInteract> m_osInteract = std::make_unique<OsInteract>();
};
#endif // MAINWINDOW_H
