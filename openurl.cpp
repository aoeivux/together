#include "openurl.h"
#include "ui_openurl.h"
#include <QFileDialog>
openURL::openURL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openURL)
{
    ui->setupUi(this);
}

openURL::~openURL()
{
    delete ui;
}

void openURL::on_openURLbuttonBox_accepted()
{
    QString url = ui->urlInput->text();
    emit urlSet(url);
}

void openURL::on_selectFileButton_clicked()
{
    QString runPath = QCoreApplication::applicationDirPath();//获取项目的根路径
    QUrl file_name = QFileDialog::getOpenFileUrl(this,QStringLiteral("选择路径"),runPath,"Text Files(*.mp4 *.flv)",nullptr,QFileDialog::DontUseCustomDirectoryIcons);
    ui->urlInput->setText(file_name.path());
}

