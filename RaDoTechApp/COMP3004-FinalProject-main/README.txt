Group 16: COMP3004 Final Project

## Group Members:
   - Student: Ryan Johnson,
   - Student: Mridul Mehta,
   - Student: Kien Pham,
   - Student: Hamza Rizwan,

## Project Description:

    This project implemented with QT and C++ simulates a RaDoTech Health monitoring device. 
    This device measures points around the body and generates functional health of vital organs 
    and overall body health. 

## Project Files:

   Headers: 
           - defs.h, 
           - devicescanner.h
           - mainwindow.h
           - profile.h
           - radotechapp.h 
           - radotechdevice.h
           - scanresult.h

   Source: 
          - main.cpp
          - mainwindow.cpp
          - profile.cpp
          - radotechapp.cpp 
          - radotechdevice.cpp
          - scanresult.cpp

## Build File: 
          - comp3004final.pro

## Documentation: 

   - `README.txt`
   - `RaDoTechApp.pdf` -  contains Use Cases, UML Class, Sequence, and State Machine diagrams 
                          along with Tracebility Matrix and textual description of design implementation.

## Video Demonstration: 

   - `demo.mp4`

## Group Contribution: 

   Ryan Johnson: 
         - Worked on UML class diagram, sequence diagrams and documentation with the group.   
         - Implemented handleLogoutButton(), handleChargeDeviceButton(), handleBackButton(), handleSwitchUserButton(), handleSubmitLoginButton(), handleDeleteUserButton(), 
           handleToggleContactButton() & UI, handleTogglePowerDeviceButton & UI, handleMeridianPointsButton(), handleDisplayRecomButton & placeholder UI, createProfile(), 
           removeProfile(), login(), notifyLowBattery(), drainBattery(), and chargeBattery(). Received suggestions and help from the group along the way. 
         - Aided with getters and setters. 
         - Worked on battery, RaDoTech device, and profile edge cases throughout the program.
         - Worked out ways to reduce code redundancy and improve simplicity.
         - Worked on debugging with group members.    


   Mridul Mehta:

          - Worked on sequence diagrams through textual description and diagrams 
          - Worked on Traceability Matrix 
          - Worked on implementing and debugging the functions in RaDoTechApp such as:
            removeProfile(), login(), emailExists(), getUserEmailByID(), updateProfile()
          - Worked on implementing and debugging the functions in MainWindow such as:
            setting up button signal slots connections for the UI interations, such as 
            handleLoginButton(), handleDeleteUserButton(), handleTogglePowerDeviceButton(),
            handleSubmitProfileButton, handleLogoutButton() and using ui->stackedWidget->setCurrentIndex()
            for switching between UI screens.
          - Partially worked on the UI functionally such as working with buttons, button labels, text field,
            text field labels for user interaction.
          - Maintaining the readability of code throughout the project. 

   Kien Pham:
         -Wrote the use cases, and worked on the UML sequence diagrams, UML class diagrams 
          as well as the documentation of the code with group members.
         -Worked on the traceability matrix with group members.
         -Worked on implementing and debugging functions such as login(), 
         updateProfile(), getUserEmailByID(), setPostScan() and others with group members.
         - Worked on implementing and debugging functions in the MainWindow such as: handleLoginButton(), 
           handleCreateProfileButton(), handleSubmitProfileButton(), handleSubmitScanResultsButton() and 
           handleSubmitUpdateUserButton().
         -Worked on the mainwindow.ui such such creating buttons, text fields, button labels with group   
           members.
         -Worked on implementing the getters and setters for the the various classes.
         -Worked on the state machine diagrams.


   
   Hamza Rizwan:
   - Worked on UML Use Case Diagram, class diagrams and documentation of code 
   - Worked on traceability matrix
   - Worked on designing UI for the program 
   - Implemented various functions within the classes and mainwindow
   - Worked on state machine diagram
   - Worked on debugging errors in class definitions and in the mainwindow
   - Worked on explanation of design
