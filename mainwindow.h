#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <LeagueManager.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_seasonCombox_currentIndexChanged(int index);

    void on_clubCombox_currentIndexChanged(int index);

    void on_BrowseBtn_clicked();

private:
    Ui::MainWindow *ui;

    LeagueManager* manager;

    int currSeason;

    std::list<ClubRecord>::iterator iterate2Index(int );
};

#endif // MAINWINDOW_H
