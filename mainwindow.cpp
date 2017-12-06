#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Logger.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    currSeason = 0;

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_seasonCombox_currentIndexChanged(int index)
{
    if (index == -1)
        return;

    this->currSeason = index;

    ui->clubCombox->clear();

    ui->seasonTxt->setText(QString::fromStdString(manager->getLeague()->getSeason(index)
                                                  .getClubManager()->writeToString()));

    std::list<ClubRecord> clubRecord = manager->getLeague()->getSeason(index)
            .getClubManager()->getClubsList();

    int startIdx = 0;
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
    if (index == -1)
        return;

    std::list<ClubRecord>::iterator ite = iterate2Index(index);

    if (ite->getPlayerManager() != NULL)
        ui->clubTxt->setText(QString::fromStdString(ite->getPlayerManager()->writeToString()));
    else
        ui->clubTxt->setText("");
}

std::list<ClubRecord>::iterator MainWindow::iterate2Index(int idx) {
    std::list<ClubRecord> clubRecord = manager->getLeague()->getSeason(this->currSeason)
            .getClubManager()->getClubsList();

    int index = 0;
    std::list<ClubRecord>::iterator ite = clubRecord.begin();
    for (ite; ite != clubRecord.end(); ite++) {
        if (ite->getName()[0] == '*')
            continue;

        if (index == idx)
            break;
        index++;
    }
    return ite;
}

void MainWindow::on_BrowseBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName();
    ui->PathLineEdit->setText(filename);

    Logger::logStr = "";
    ui->seasonCombox->clear();
    ui->clubCombox->clear();

    ui->seasonTxt->setText("");
    ui->clubTxt->setText("");

    try {

         manager = new LeagueManager();
         manager->readData(filename.toStdString());
         manager->writeClub2File("CLUBS.txt");
         manager->writePlayer2File();

         for (int idxSeason = 0; idxSeason < manager->getLeague()->getSeasonNum(); idxSeason++) {
          ui->seasonCombox->addItem(QVariant(idxSeason + 1).toString());
         }
        ui->PrcTxt->setText(QString::fromStdString(Logger::logStr));

    } catch (int ex) {
        ui->PrcTxt->setText(QString::fromStdString(Logger::logStr));
    }


}
