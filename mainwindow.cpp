#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    ui->topTextBox->appendPlainText(m_passwordGen->GetGeneratePassword());
}


void MainWindow::on_passLengthEdit_textEdited(const QString &arg1)
{
    m_passwordGen->SetPasswordLength(ui->passLengthEdit->displayText());
}



void MainWindow::on_clipboardCopyButton_clicked()
{

    if (m_passwordGen->GetRetrievePassword() != "")
    {
        m_osInteract->copyToClipboard(m_passwordGen->GetRetrievePassword());
    }
}


void MainWindow::on_excludeCharactersLineEditBox_textEdited(const QString &arg1)
{
    m_passwordGen->DissallowedCharacters(ui->excludeCharactersLineEditBox->displayText());
}



void MainWindow::on_allowUppercaseCheckbox_toggled(bool checked)
{
    m_passwordGen->AllowUppercase(checked);
}

