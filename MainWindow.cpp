#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->widget, SIGNAL(updateFps(int)), this, SLOT(setNewFps(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNewFps(int fps)
{
    ui->statusBar->showMessage(QString("%1 fps").arg(fps));
}
