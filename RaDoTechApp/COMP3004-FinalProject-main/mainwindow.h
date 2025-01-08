#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include "radotechapp.h"
#include "profile.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    RaDoTechApp app;

private:
    Ui::MainWindow *ui;


private slots:
    // Handlers for various button click events
    void handleLoginButton();
    void handleCreateProfileButton();
    void handleSubmitProfileButton();
    void handleSubmitLoginButton();
    void handleStartMeasurementButton();
    void handleDisplayRecomButton();
    void handleViewHistoryButton(); // View user's scan history
    void handleDeleteUserButton();
    void handleSwitchUserButton();
    void handleTogglePowerDeviceButton();
    void handleChargeDeviceButton();
    void handleToggleContactButton();
    void handleMeridianPointsButton();
    void handleLogoutButton();
    void handleSubmitHistoryButton();
    void handleBackButton();
    void handleUpdateUserButton();
    void handleSubmitUpdateUserButton();
    void handleSubmitScanResultsButton();
};

#endif // MAINWINDOW_H
