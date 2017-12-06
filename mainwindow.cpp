#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Logger.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    currSeason = 0;
    openFileName = "";
    saveDirectoryName = "";

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_seasonCombox_currentIndexChanged(int index)
{
    //in case clear the combo box will call this function
    if (index == -1)
        return;

    this->currSeason = index;

    ui->clubCombox->clear();

    ui->seasonTxt->setText(QString::fromStdString(manager->getLeague()->getSeason(index)
                                                  .getClubManager()->writeToString()));

    std::list<ClubRecord> clubRecord = manager->getLeague()->getSeason(index)
            .getClubManager()->getClubsList();


    int startIdx = 0; //Begin club showing in combo box
    for (std::list<ClubRecord>::iterator ite = clubRecord.begin(); ite != clubRecord.end(); ite++) {
        if (ite->getName()[0] == '*') {
            startIdx++;
            continue;
        }
        ui->clubCombox->addItem(QString::fromStdString(ite->getName()));
    }
    std::list<ClubRecord>::iterator ite = iterate2Index(startIdx);
    ui->clubTxt->setText(QString::fromStdString(ite->getPlayerManager()->writeToString()));
}

void MainWindow::on_clubCombox_currentIndexChanged(int index)
{
    //in case clear the combo box will call this function
    if (index == -1)
        return;

    std::list<ClubRecord>::iterator clubIterator = iterate2Index(index);
    ui->clubTxt->setText(QString::fromStdString(clubIterator->getPlayerManager()->writeToString()));
}

std::list<ClubRecord>::iterator MainWindow::iterate2Index(int idx) {
    std::list<ClubRecord> clubRecord = manager->getLeague()->getSeason(this->currSeason)
            .getClubManager()->getClubsList();

    int currIdx = 0;
    //Iterate to index by pass deleted record
    std::list<ClubRecord>::iterator clubIterator = clubRecord.begin();
    for (clubIterator; clubIterator != clubRecord.end(); clubIterator++) {
        if (clubIterator->getName()[0] == '*')
            continue;

        if (currIdx == idx)
            break;
        currIdx++;
    }
    return clubIterator;
}

void MainWindow::on_openBrowseBtn_clicked()
{
    openFileName = QFileDialog::getOpenFileName();
    ui->PathLineEdit->setText(openFileName);

    clearContent();
}

void MainWindow::on_saveBrowseBtn_clicked()
{
    saveDirectoryName = QFileDialog::getExistingDirectory();
    ui->saveEditTxt->setText(saveDirectoryName);

    clearContent();
}

void MainWindow::on_startBtn_clicked()
{
    if (openFileName.size() == 0) {
        QMessageBox::critical(this, "Error", "You need to select file to open", QMessageBox::Ok);
        return;
    }

    clearContent();
    try {

        manager = new LeagueManager();
        if (saveDirectoryName.size() > 0)
            manager->setOutputPath(saveDirectoryName.toStdString() + "/");
        manager->readData(openFileName.toStdString());
        manager->writeClub2File();
        manager->writePlayer2File();

        for (int idxSeason = 0; idxSeason < manager->getLeague()->getSeasonNum(); idxSeason++) {
            ui->seasonCombox->addItem(QVariant(idxSeason + 1).toString());
        }
        ui->PrcTxt->setText(QString::fromStdString(Logger::logStr));

    } catch (int ex) {
        ui->PrcTxt->setText(QString::fromStdString(Logger::logStr));
    }

}

void MainWindow::on_closeBtn_clicked()
{
    QApplication::quit();
}

void MainWindow::clearContent()
{
    Logger::logStr = "";
    ui->PrcTxt->setText("");
    ui->seasonCombox->clear();
    ui->clubCombox->clear();

    ui->seasonTxt->setText("");
    ui->clubTxt->setText("");
}
