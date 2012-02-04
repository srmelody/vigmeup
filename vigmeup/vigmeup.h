/***************************************************************************
                          vigmeup.h  -  description                              
                             -------------------                                         
    begin                : Sun Jun 13 03:59:48 CDT 1999
                                           
    copyright            : (C) 1999 by Sean Melody                         
    email                : vigmeup@c-nix.com                                     
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   * 
 *                                                                         *
 ***************************************************************************/


#ifndef VIGMEUP_H
#define VIGMEUP_H 
 

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

//system includes
#include <sys/types.h>
#include <signal.h>    
#include <unistd.h>
#include <iostream.h>  
#include <errno.h>
// include files for QT
#include <qprinter.h>
#include <qpainter.h>

//old includes
#include <qdialog.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qtimer.h>
#include <qlined.h>
#include <qscrbar.h>
#include <qpushbt.h>
#include <qtooltip.h>
#include <qlcdnum.h>
#include <kapp.h>
#include <qstring.h>
#include <qfiledlg.h>
#include <kmenubar.h>
#include <qpopmenu.h>
#include <qkeycode.h>
#include <kapp.h>

// include files for KDE
#include <kapp.h> 
#include <ktmainwindow.h> 
#include <kaccel.h>
#include <kiconloader.h>
#include <kmsgbox.h>

#include <kfiledialog.h>
// application specific includes

#include "resource.h"


// C system lib
#include <stdlib.h>

//Layout manager
#include <qlayout.h>
#include <kcontainer.h>
/**
  * This Class is the base class for your application. It sets up the main
  * window and reads the config file as well as providing a menubar, toolbar
  * and statusbar. For the main view, an instance of class VigmeupView is
  * created which creates your view.
  */
class VigmeupApp : public KTMainWindow 
{
  Q_OBJECT

    public:
  /** construtor */
  VigmeupApp(); 
  /** destructor */
  ~VigmeupApp();

  /** initMenuBar creates the menu_bar and inserts the menuitems */
  void initMenuBar();
  /** this creates the toolbars. Change the toobar look and add new toolbars in this
   * function */
  //  void initToolBar();
  /** setup the statusbar */
  void initStatusBar();
  /** setup the mainview*/
  //void initView();
  /** sets up the objects in the main window */
  void initObjects();
  /** save the app-specific options on slotAppExit or by an Options dialog */
  void saveOptions();
  /** read the app-specific options on init() or by an Options dialog */
  void readOptions();
  /** enable menuentries/toolbar items */
  void enableCommand(int id_);
  /** disable menuentries/toolbar items */
  void disableCommand(int id_);
  /** overloaded for Message box on last window exit */
  bool queryExit();

  //void initAlarmRunningFrame();
  bool alarmOff();
  void toggleAlarm ();
  void setAlarmRunning(bool b);
  bool alarmRunning;
  bool alarmOn();
  void playMp3(const char *mp3File, const char *mp3Player);
  QString mp3Player;
  QString lastPlayerDir;
  //QString mp3File;
  int snoozeLength;
  int childPID;
	
 
  public slots:
    /** switch argument for slot selection by menu or toolbar ID */
    void commandCallback(int id_);
  /** switch argument for Statusbar help entries on slot selection */
  void statusCallback(int id_);

  /** exits the application */
  void slotFileQuit();

  /** toggle the statusbar*/
  void slotViewStatusBar();
  /** change the status message to text */
  void slotStatusMsg(const char *text);
  /** change the status message of the whole statusbar temporary */
  void slotStatusHelpMsg(const char *text);

  void checkTime ();
  void chooseMp3();
  void snoozeIt();
  void choosePlayer();
  void setAlarm();
  void startAlarm();
  //QMenuBar *menuBar();
 private:


  /* main elements */
  QFrame *setAlarmFrame;

  KMenuBar *vmuMenuBar;
  KStatusBar *vmuStatusBar;

  QScrollBar *hourScrollBar;
  QScrollBar *minuteScrollBar;
  QScrollBar *snoozeScrollBar;
  QLCDNumber *hourLcd;
  QLCDNumber *minuteLcd;
  QLCDNumber *snoozeLcd;

  
  QLineEdit *playerTextBox;
  QPushButton *choosePlayerButton;
  QPushButton *chooseMp3Button;//button3;
  QPushButton *snoozeButton;//button1;
  QLabel *snoozeLengthLabel;//label3;

    QLineEdit *fileTextBox;//text1;
  QTimer *mainTimer;
  QLabel *colonLabel;

  /** file_menu contains all items of the menubar entry "File" */
  QPopupMenu *file_menu;
  /** action_menu contains all items of the menubar entry "Action" */
  QPopupMenu *action_menu;

  /** help_menu contains all items of the menubar entry "Help" */
  QPopupMenu *help_menu;
  /** flag if toolbar is visible or not. Used for kconfig and checking the
   * view-menu entry view toolbar. bViewStatusbar does the same for the
   * statusbar.
   */
  bool bViewToolbar;
  bool bViewStatusbar;

  /** used for KConfig to store and restore menubar position. Same with
   * tool_bar_pos. If more menubars or toolbars are created, you should add
   * positions as well and implement them in saveOptions() and readOptions().
   */
  KMenuBar::menuPosition menu_bar_pos;
  //KToolBar::BarPosition tool_bar_pos;
 protected:
 signals:
  //void changeHourLcd(int n);
  //void changeMinuteLcd2(int n);


};   
 
#endif // VIGMEUP_H
 
 
 
 
 
 
 
 























