#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "radotechapp.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0); //Display Start Page to user when application initially runs
    ui->batteryIndicatorLabel->setText("Battery Status: 100");
    app.clearProfiles();

            //Sockets for all of the buttons in the program
            connect(ui->loginButton, SIGNAL(released()), this, SLOT (handleLoginButton()));
            connect(ui->createProfileButton, SIGNAL(released()), this, SLOT (handleCreateProfileButton()));
            connect(ui->submitProfileButton, SIGNAL(released()), this, SLOT (handleSubmitProfileButton()));
            connect(ui->loginSubmitButton, SIGNAL(released()), this, SLOT (handleSubmitLoginButton()));
            connect(ui->startMeasurementButton, SIGNAL(released()), this, SLOT (handleStartMeasurementButton()));
            connect(ui->displayRecButton, SIGNAL(released()), this, SLOT (handleDisplayRecomButton()));
            connect(ui->viewHistoryButton, SIGNAL(released()), this, SLOT (handleViewHistoryButton()));
            connect(ui->deleteUserButton, SIGNAL(released()), this, SLOT (handleDeleteUserButton()));
            connect(ui->switchUserButton, SIGNAL(released()), this, SLOT (handleSwitchUserButton()));
            connect(ui->togglePowerDeviceButton, SIGNAL(released()), this, SLOT (handleTogglePowerDeviceButton()));
            connect(ui->chargeDeviceButton, SIGNAL(released()), this, SLOT (handleChargeDeviceButton()));
            connect(ui->scanMPointButton, SIGNAL(released()), this, SLOT (handleMeridianPointsButton()));
            connect(ui->scanBackButton, SIGNAL(released()), this, SLOT (handleBackButton()));
            connect(ui->recomBackButton, SIGNAL(released()), this, SLOT (handleBackButton()));
            connect(ui->historyBackButton, SIGNAL(released()), this, SLOT (handleBackButton()));
            connect(ui->logoutButton, SIGNAL(released()), this, SLOT (handleLogoutButton()));
            connect(ui->toggleContactButton, SIGNAL(released()), this, SLOT (handleToggleContactButton()));
            connect(ui->submitHistoryButton, SIGNAL(released()), this, SLOT (handleSubmitHistoryButton()));
            connect(ui->updateUserButton, SIGNAL(released()), this, SLOT (handleUpdateUserButton()));
            connect(ui->submitUpdateUserButton, SIGNAL(released()), this, SLOT (handleSubmitUpdateUserButton()));
            connect(ui->submitScanResultButton, SIGNAL(released()), this, SLOT (handleSubmitScanResultsButton()));
            connect(ui->resultsBackButton, SIGNAL(released()), this, SLOT (handleBackButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleLoginButton()
{
    if(app.getNumUsers() == 0){
        ui->numUsersErrorLabel->setText("Error: no users created.");
            return;
        }

    ui->stackedWidget->setCurrentIndex(2);  //Navigate user to the Login Page

    ui->loginEmailEdit->clear();
    ui->loginPasswordEdit->clear();
}


void MainWindow::handleCreateProfileButton()
{
    //Display error message if user profile number exceeds 5
    if(app.getNumUsers() >= MAX_PROFILES){
        ui->numUsersErrorLabel->setText("Maximum number of profiles reached.");
        return;
    }

    ui->stackedWidget->setCurrentIndex(1);

    // Clear input fields
    ui->firstNameEdit->clear();       // First Name
    ui->lastNameEdit->clear();       // Last Name
    ui->weightEdit->clear();        // Weight
    ui->heightEdit->clear();       // Height
    ui->dobEdit->clear();         // Date of Birth
    ui->phoneEdit->clear();      // Phone Number
    ui->emailEdit->clear();     // Email
    ui->passwordEdit->clear(); // Password
}

void MainWindow::handleSubmitProfileButton()
{
    // Retrieve input values from the text fields
    QString firstName = ui->firstNameEdit->text();
    QString lastName = ui->lastNameEdit->text();
    QString weight = ui->weightEdit->text();
    QString height = ui->heightEdit->text();
    QString dob = ui->dobEdit->text();
    QString phoneNumber = ui->phoneEdit->text();
    QString email = ui->emailEdit->text();
    QString password = ui->passwordEdit->text();

    bool weightOk, heightOk;
    QString fullName = firstName + " " + lastName;
    double userWeight = weight.toDouble(&weightOk);
    double userHeight = height.toDouble(&heightOk);

    // Validate the user input
    if (firstName.isEmpty() || lastName.isEmpty() || weight.isEmpty() || height.isEmpty() || dob.isEmpty() || phoneNumber.isEmpty() || email.isEmpty() || password.isEmpty()) {
        ui->createProfileErrorLabel->setText("Error: you are missing key information. Please input all required information.");
        return;
     } else if (!weightOk || !heightOk){
        ui->createProfileErrorLabel->setText("Error: weight and height must be decimal types.");
        return;
    }  else if (app.emailExists(email.toStdString())) {
        ui->createProfileErrorLabel->setText("Error: This email is already registered. Please use a different email.");
        return;
    }

    app.createProfile(fullName.toStdString(), email.toStdString(), userWeight, userHeight,
                      dob.toStdString(), phoneNumber.toStdString(), password.toStdString());

    app.login(email.toStdString(), password.toStdString());
        ui->stackedWidget->setCurrentIndex(3);  //Navigate user to the Main Page

        // Clear the error message field
        ui->createProfileErrorLabel->clear();
}

void MainWindow::handleLogoutButton()
{
    int currentUser = app.getCurrentUser();

    if (currentUser != -1) {
        // Log the email of the user being logged out
        std::string email = app.getUserEmailByID(currentUser);
        std::cout << "User: " << email << " logged out." << std::endl;
    }

    ui->stackedWidget->setCurrentIndex(0);  //Navigate user to the Start Page
    app.setCurrentUser(-1);
    ui->numUsersErrorLabel->clear();
}

void MainWindow::handleChargeDeviceButton()
{
     ui->batteryIndicatorLabel_2->clear();
     app.device.chargeBattery(); // Charge the device
     ui->batteryIndicatorLabel->setText("Battery Status: 100");
}

void MainWindow::handleDisplayRecomButton()
{
    ui->stackedWidget->setCurrentIndex(8); //Navigate user to the Recomendation Page
}


void MainWindow::handleBackButton()
{
     ui->stackedWidget->setCurrentIndex(3); //Navigate user to the Main Page
}

void MainWindow::handleViewHistoryButton()
{
     ui->stackedWidget->setCurrentIndex(6); //Navigate user to the History Page

     ui->historyErrorLabel->clear();
     ui->historyIndexEdit->clear();
     ui->historyList->clear();

     for(size_t  i  =0; i < app.fetchScanList().size(); i++){
         std::string s = "Index: " + std::to_string(i)  + " "+app.fetchScanList()[i].getName()  +  " : " + app.fetchScanList()[i].getDate();
         ui->historyList->addItem(QString::fromStdString(s)) ;
     }
}

void MainWindow::handleSwitchUserButton()
{
    ui->stackedWidget->setCurrentIndex(3);  //Navigate user to the Main Page
    app.setCurrentUser(-1);
    std::cout << "Switching Users." << std::endl;
    handleLoginButton();
}

void MainWindow::handleSubmitLoginButton()
{

    //Get email and password input by user
    QString email = ui->loginEmailEdit->text();
    QString password = ui->loginPasswordEdit->text();

    //Validate all fields
    if (email.isEmpty() || password.isEmpty()) {
        ui->loginErrorLabel->setText("Error: Please fill in all fields.");
        return;
    }

    // Attempt to log in
    if (app.login(email.toStdString(), password.toStdString())) {
        ui->stackedWidget->setCurrentIndex(3);  //Navigate user to the Main Page
        ui->loginErrorLabel->clear();
    } else {
        ui->loginErrorLabel->setText("Error: Invalid email or password. Please try again.");
        return;
    }
}

void MainWindow::handleDeleteUserButton()
{
    int currentUser = app.getCurrentUser();

    // Fetch the email associated with the current user
    std::string email = app.getUserEmailByID(currentUser);

    if (app.removeProfile(currentUser)) {
        std::cout << "User with email \"" << email << "\" deleted successfully." << std::endl;
        ui->stackedWidget->setCurrentIndex(0);  //Navigate user to the Start Page
    }
}

void MainWindow::handleToggleContactButton()
{
    // Toggle the hasContact state
    app.scanner.setHasContact(); // This toggles the state

    // Check the current state and update the button appearance
    if (app.scanner.getHasContact()) {
        // Set the button color to green (ON) and update text
        ui->toggleContactButton->setStyleSheet("background-color: green; color: white;");
        ui->toggleContactButton->setText("Contact: ON");
    } else {
        // Set the button color to red (OFF) and update text
        ui->toggleContactButton->setStyleSheet("background-color: red; color: white;");
        ui->toggleContactButton->setText("Contact: OFF");
    }
}


void MainWindow::handleMeridianPointsButton()
{
    ui->postScanErrorLabel->clear();
    // If the device battery level is low notify the user
    if (app.device.getBatteryStatus() <= 25) {
        app.notifyLowBattery();
        ui->batteryIndicatorLabel->setText("Error: Device battery is dead.");
        ui->batteryIndicatorLabel_2->clear();
        return;
    }

    // Check if the battery level is low but not critically low
    else if (app.device.getBatteryStatus() == 50) {
        ui->batteryIndicatorLabel_2->setText("Warning: Low battery detected.");
    }

    app.notifyLowBattery();
    ui->batteryIndicatorLabel->setText("Battery Status: " + QString::number(app.device.getBatteryStatus()));

    app.startMeasurement();
    ui->stackedWidget->setCurrentIndex(5);  //Navigate user to the Post Scan Page

    std::cout << "Scan Complete" << std::endl;
}


void MainWindow::handleTogglePowerDeviceButton()
{
    app.device.setPowerStatus(); //This toggles the state

    // Check the current state and update the button appearance
    if (app.device.getPowerStatus()) {
        // Set the button color to green (ON) and update text
        ui->togglePowerDeviceButton->setStyleSheet("background-color: green; color: white;");
        ui->togglePowerDeviceButton->setText("Device Power: ON");
        app.device.setBluetoothStatus(true);
    } else {
        // Set the button color to red (OFF) and update text
        ui->togglePowerDeviceButton->setStyleSheet("background-color: red; color: white;");
        ui->togglePowerDeviceButton->setText("Device Power: OFF");
    }
}

void MainWindow::handleSubmitHistoryButton()
{
    if(ui->historyIndexEdit->text().isEmpty()){
        ui->historyErrorLabel->setText("Please enter a number index.");
       return;
    }

    bool indexOk;
    double s = (ui->historyIndexEdit->text().toDouble(&indexOk));

    if (indexOk == false){
        ui->historyErrorLabel->setText("Please enter a number index.");
        return;
    }

    if(s >= app.fetchScanList().size() ||  s < 0){
        ui->historyErrorLabel->setText("Please enter a valid number index.");
        return;
    }

    //Stores whether the value is good or bad
    std::string cond;
    QString condQ;
    ui->stackedWidget->setCurrentIndex(7);  //Navigate user to the Results Page
    QString q  =QString::fromStdString(app.fetchScanList()[s].getName());
    ui->resultNameLabel->setText(q);

    q= QString::number(app.fetchScanList()[s].getBP());
    ui->resultBPLabel->setText("Blood Pressure: "+q);
    q= QString::number(app.fetchScanList()[s].getHR());
    ui->resultHRLabel->setText("Heart Rate: "+q);
    q= QString::number(app.fetchScanList()[s].getTemp());
    ui->resultTempLabel->setText("Temperature: "+q);
    q= QString::number(app.fetchScanList()[s].getSleepTime());
    ui->resultSleepLabel->setText("Sleep Time: "+q);

    q = QString::fromStdString(app.fetchScanList()[s].getPhone());
    ui->resultPhoneLabel->setText("Phone #: " + q);
    q = QString::fromStdString(app.fetchScanList()[s].getDob());
    ui->resultDobLabel->setText("Date Of Birth: " + q);
    q = QString::fromStdString(app.fetchScanList()[s].getEmail());
    ui->resultEmailLabel->setText("Email: "+q);

    q = QString::fromStdString(app.fetchScanList()[s].getDate());
    ui->resultDateLabel->setText(q);
    q = QString::number(app.fetchScanList()[s].getEnergyLevel());

    if(app.fetchScanList()[s].getEnergyLevel() > 325){
        cond = "Status = Good!";
        condQ = QString::fromStdString(cond);
    }
    else if(app.fetchScanList()[s].getEnergyLevel() > 250){
        cond = "Status = Caution: Speak to a doctor about this.";
        condQ = QString::fromStdString(cond);
    }
    else{
        cond = "Status = Bad: See a doctor now!.";
        condQ = QString::fromStdString(cond);
    }

    ui->resultValue1Label->setText("Energy Level: "+q+" " +condQ);

    if(app.fetchScanList()[s].getImmuneSystem() > 350){
        cond = "Status = Good!";
        condQ = QString::fromStdString(cond);
    }
    else if(app.fetchScanList()[s].getImmuneSystem() > 250){
        cond = "Status = Caution: Speak to a doctor about this.";
        condQ = QString::fromStdString(cond);
    }
    else{
        cond = "Status = Bad: See a doctor now!.";
        condQ = QString::fromStdString(cond);
    }

    q = QString::number(app.fetchScanList()[s].getImmuneSystem());
    ui->resultValue2Label->setText("ImmuneSystem: "+q +" "+condQ);

    if(app.fetchScanList()[s].getMetabolism() > 375){
        cond = "Status = Good!";
        condQ = QString::fromStdString(cond);
    }
    else if(app.fetchScanList()[s].getMetabolism() > 250){
        cond = "Status = Caution: Speak to a doctor about this.";
        condQ = QString::fromStdString(cond);
    }
    else{
        cond = "Status = Bad: See a doctor now!.";
        condQ = QString::fromStdString(cond);
    }

    q = QString::number(app.fetchScanList()[s].getMetabolism());
    ui->resultValue3Label->setText("Metabolism: "+q +" "+condQ);

    if(app.fetchScanList()[s].getPsychoEmotionalStatus() > 400){
        cond = "Status = Good!";
        condQ = QString::fromStdString(cond);
    }
    else if(app.fetchScanList()[s].getPsychoEmotionalStatus() > 250){
        cond = "Status = Caution: Speak to a doctor about this.";
        condQ = QString::fromStdString(cond);
    }
    else{
        cond = "Status = Bad: See a doctor now!.";
        condQ = QString::fromStdString(cond);
    }

    q = QString::number(app.fetchScanList()[s].getPsychoEmotionalStatus());
    ui->resultValue4Label->setText("PsychoEmotionalStatus: "+q+ " "+condQ);

    if(app.fetchScanList()[s].getMusculoskeletalSystem() > 425){
        cond = "Status = Good!";
        condQ = QString::fromStdString(cond);
    }
    else if(app.fetchScanList()[s].getMusculoskeletalSystem() > 250){
        cond = "Status = Caution: Speak to a doctor about this.";
        condQ = QString::fromStdString(cond);
    }
    else{
        cond = "Status = Bad: See a doctor now!.";
        condQ = QString::fromStdString(cond);
    }

    q = QString::number(app.fetchScanList()[s].getMusculoskeletalSystem());
    ui->resultValue5Label->setText("MusculoSkeletalSystem: "+q+ " "+condQ);
}

void MainWindow::handleStartMeasurementButton()
{
   if(!app.device.getPowerStatus()){
    ui->DeviceErrorLabel->setText("Error: Device must be powered on.");
    return;
   } else if(!app.scanner.getHasContact()){
    ui->DeviceErrorLabel->setText("Error: Device is not touching skin.");
    return;
   } else if(app.device.getBatteryStatus() == 0){
    ui->DeviceErrorLabel->setText("Error: Device battery is dead.");
   }

   ui->DeviceErrorLabel->clear();
   ui->stackedWidget->setCurrentIndex(4);  //Navigate user to the Before Scan Page
}

void MainWindow::handleUpdateUserButton()
{
   ui->stackedWidget->setCurrentIndex(9);  //Navigate user to the Update Profile Page
}

void MainWindow::handleSubmitScanResultsButton()
{
    // Retrieve input values from the respective fields
    QString newBloodPressure = ui->bloodPressureEdit->text();
    QString newHeartRate = ui->heartRateEdit->text();
    QString newTemp = ui->tempEdit->text();
    QString newSleepTime = ui->sleepTimeEdit->text();

    // Convert input values to double
    bool bloodPressureOk, heartRateOk, tempOk, sleepTimeOk;
    double userBloodPressure = newBloodPressure.toDouble(&bloodPressureOk);
    double userHeartRate = newHeartRate.toDouble(&heartRateOk);
    double userTemp = newTemp.toDouble(&tempOk);
    double userSleepTime = newSleepTime.toDouble(&sleepTimeOk);

    // Edge case checking
    if (newBloodPressure.isEmpty() || newHeartRate.isEmpty() || newTemp.isEmpty() || newSleepTime.isEmpty()){
        ui->postScanErrorLabel->setText("Error: you are missing information. Please input all required information.");
        return;
     } else if (!bloodPressureOk || !heartRateOk || !tempOk || !sleepTimeOk){
        ui->postScanErrorLabel->setText("Error: all entries must be decimal type.");
        return;
    }
    ui->stackedWidget->setCurrentIndex(3);  //Navigate user to the Main Page

    //Save the scan result
    app.setPostScan(userBloodPressure, userHeartRate, userTemp, userSleepTime);

    //Clear input fields 
    ui->tempEdit->clear();
    ui->bloodPressureEdit->clear();
    ui->heartRateEdit->clear();
    ui->sleepTimeEdit->clear();
}

void MainWindow::handleSubmitUpdateUserButton()
{
    // Get the new weight and height from the input fields
    QString newWeight = ui->weightEditBox->text();
    QString newHeight = ui->heightEditBox->text();

    // Convert input values to double
    bool weightOk, heightOk;
    double userWeight = newWeight.toDouble(&weightOk);
    double userHeight = newHeight.toDouble(&heightOk);

    app.updateProfile(userWeight, userHeight);
    std::cout << "Profile updated successfully:\n" << "Weight: " << userWeight << "\n"<< "Height: " << userHeight << std::endl;

    ui->stackedWidget->setCurrentIndex(3);  //Navigate user to the Main Page
}
