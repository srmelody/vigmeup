/***************************************************************************
                          vigmeup.cpp  -  description                              
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


#include <vigmeup.h>


VigmeupApp::VigmeupApp()
{
  setCaption("Vigmeup " VERSION);


  initObjects();
  readOptions();
  initMenuBar();

  initStatusBar();


  
  setMenu(vmuMenuBar);
  //setAlarmFrame->setGeometry(0,30, 244, 300);
  setView(setAlarmFrame);
  //setAlarmFrame->setGeometry(0,30, 244, 300);
  resize(244,358);
  setStatusBar(vmuStatusBar);

  //setAlarmFrame->hide();
  show();

}

VigmeupApp::~VigmeupApp()
{
  saveOptions();
  kapp->quit();
}

void VigmeupApp::enableCommand(int id_)
{
  ///////////////////////////////////////////////////////////////////
  // enable menu and toolbar functions by their ID's
  menuBar()->setItemEnabled(id_,true);
  
}

void VigmeupApp::disableCommand(int id_)
{
  ///////////////////////////////////////////////////////////////////
  // disable menu and toolbar functions by their ID's
  menuBar()->setItemEnabled(id_,false);

}


/*void VigmeupApp::initAlarmRunningFrame()
{
  alarmRunningFrame = new QFrame(this, "setAlarmFrame");
  QLabel *ac;
  ac = new QLabel(alarmRunningFrame, "ac");
  ac->setText("asdfasdfasdfawds");
  ac->setFont(QFont("helvetica",36,QFont::Normal,(int)0));
  ac->setAlignment(AlignHCenter | AlignTop);
  ac->setGeometry(104,39,36,99);
  
  ac->setPalette(QPalette(
			      QColorGroup(QColor(0,0,0), QColor(192,192,192),
					  QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					  QColor(255,0,0),QColor(255,255,255)),
			      QColorGroup(QColor(0,0,0), QColor(192,192,192),
					  QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					  QColor(160,160,160),QColor(255,255,255)),
			      QColorGroup(QColor(0,0,0), QColor(192,192,192),
					  QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					  QColor(0,0,0),QColor(255,255,255))));
  ac->setMaximumSize(11111,32767);
  
  ac->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
  

  }*/
void VigmeupApp::initObjects()

{
  
  setAlarmFrame = new QFrame(this, "setAlarmFrame");
  //setAlarmFrame->setMinimumSize(244,300);
 

  QBoxLayout *topLayout = new QVBoxLayout(setAlarmFrame);
  //QBoxLayout *alarmButtonsLayout = new QHBoxLayout();
  QBoxLayout *timeLayout = new QHBoxLayout();
  QBoxLayout *timeControlLayout = new QHBoxLayout();
  QBoxLayout *snoozeLayout = new QHBoxLayout();
  QBoxLayout *snoozeLengthLayout = new QVBoxLayout();
  
  //KContainerLayout 
  //KContainerLayout *topLayout = new KContainerLayout(this, "topLayout", KContainerLayout::Vertical);
  
  
  //resize(244,358);
  //setMaximumSize(244,358);
  //setStyle(WindowsStyle);
  
  colonLabel = new QLabel(setAlarmFrame, "colonLabel");
  colonLabel->setText(":");
  colonLabel->setFont(QFont("helvetica",36,QFont::Normal,(int)0));
  colonLabel->setAlignment(AlignHCenter | AlignTop);
  colonLabel->setGeometry(104,39,36,99);
  
  colonLabel->setPalette(QPalette(
			      QColorGroup(QColor(0,0,0), QColor(192,192,192),
					  QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					  QColor(255,0,0),QColor(255,255,255)),
			      QColorGroup(QColor(0,0,0), QColor(192,192,192),
					  QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					  QColor(160,160,160),QColor(255,255,255)),
			      QColorGroup(QColor(0,0,0), QColor(192,192,192),
					  QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					  QColor(0,0,0),QColor(255,255,255))));
  colonLabel->setMaximumSize(11111,32767);
  
  colonLabel->setFrameStyle(QFrame::WinPanel | QFrame::Sunken);
  
  mainTimer = new QTimer(this, "mainTimer");
  mainTimer->start(2000,FALSE);
  
  fileTextBox = new QLineEdit(setAlarmFrame, "fileTextBox");
  fileTextBox->setText("No Mp3 File Selected.");
  fileTextBox->setGeometry(0,199,246,31);
	
	
  snoozeScrollBar = new QScrollBar(setAlarmFrame, "snoozeScrollBar");
  snoozeScrollBar->setValue(10);
  snoozeScrollBar->setOrientation(QScrollBar::Horizontal);
  snoozeScrollBar->setGeometry(120,290,97,25);
	
	
  snoozeLengthLabel = new QLabel(setAlarmFrame, "snoozeLengthLabel");
  snoozeLengthLabel->setText("Snooze Length\n(Minutes)");
  snoozeLengthLabel->setAlignment(AlignCenter);//AlignLeft | AlignTop);
  snoozeLengthLabel->setGeometry(102,322,139,20);
	
	
  snoozeButton = new QPushButton(setAlarmFrame, "snoozeButton");
  snoozeButton->setText("Snooze Bar");
  snoozeButton->setFont(QFont("helvetica", 18, QFont::Bold, (int)0));
  snoozeButton->setGeometry(0,30,244,42);
	

  snoozeButton->setPalette(QPalette(
			       QColorGroup(QColor(0,0,0), QColor(0,0,255),
					   QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					   QColor(0,0,0),QColor(255,255,255)),
			       QColorGroup(QColor(0,0,0), QColor(192,192,192),
					   QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					   QColor(160,160,160),QColor(255,255,255)),
			       QColorGroup(QColor(0,0,0), QColor(192,192,192),
					   QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					   QColor(0,0,0),QColor(255,255,255))));

  snoozeButton->setEnabled(false);
  
  //snoozeButton->setFixedSize(0,0);//Visible(false);
  //snoozeButton->hide();
  /*  setAlarmButton = new QPushButton(setAlarmFrame, "setAlarmButton");
  setAlarmButton->setText("Set Alarm");
  setAlarmButton->setFont(QFont("helvetica", 18, QFont::Bold, (int)0));	
  setAlarmButton->setPalette(QPalette(
			       QColorGroup(QColor(0,0,0), QColor(0,0,255),
					   QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					   QColor(0,0,0),QColor(255,255,255)),
			       QColorGroup(QColor(0,0,0), QColor(192,192,192),
					   QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					   QColor(160,160,160),QColor(255,255,255)),
			       QColorGroup(QColor(0,0,0), QColor(192,192,192),
					   QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					   QColor(0,0,0),QColor(255,255,255))));

  
  setAlarmButton->setEnabled(false);

  startAlarmButton = new QPushButton(setAlarmFrame, "startAlarmButton");
  startAlarmButton->setText("Start Alarm");
  startAlarmButton->setFont(QFont("helvetica", 18, QFont::Bold, (int)0));	
  startAlarmButton->setPalette(QPalette(
			       QColorGroup(QColor(0,0,0), QColor(0,0,255),
					   QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					   QColor(0,0,0),QColor(255,255,255)),
			       QColorGroup(QColor(0,0,0), QColor(192,192,192),
					   QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					   QColor(160,160,160),QColor(255,255,255)),
			       QColorGroup(QColor(0,0,0), QColor(192,192,192),
					   QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					   QColor(0,0,0),QColor(255,255,255))));

  
  startAlarmButton->setEnabled(false);
  */  
  chooseMp3Button = new QPushButton(setAlarmFrame, "chooseMp3Button");
  chooseMp3Button->setText("Choose Mp3 File...");
  chooseMp3Button->setGeometry(0,174,244,26);

	
  choosePlayerButton = new QPushButton(setAlarmFrame, "choosePlayerButton");
  choosePlayerButton->setText("Choose Mp3 Player...");
  choosePlayerButton->setGeometry(0,231,244,24);

	
  playerTextBox = new QLineEdit(setAlarmFrame, "playerTextBox");
  playerTextBox->setText("No Player Selected.");
  playerTextBox->setGeometry(0,255,244,29);

	
  snoozeLcd = new QLCDNumber(setAlarmFrame, "snoozeLcd");
  snoozeLcd->setNumDigits(2);
  snoozeLcd->display(10);
  snoozeLcd->setGeometry(0,285,97,53);

	
  minuteLcd = new QLCDNumber(setAlarmFrame, "minuteLcd");
  minuteLcd->setNumDigits(2);
  minuteLcd->display(30);
  minuteLcd->setSegmentStyle(QLCDNumber::Filled);
  minuteLcd->setGeometry(140,72,104,66);
  minuteLcd->setPalette(QPalette(
			    QColorGroup(QColor(255,0,0), QColor(192,192,192),
					QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					QColor(0,0,0),QColor(255,255,255)),
			    QColorGroup(QColor(0,0,0), QColor(192,192,192),
					QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					QColor(160,160,160),QColor(255,255,255)),
			    QColorGroup(QColor(0,0,0), QColor(192,192,192),
					QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					QColor(0,0,0),QColor(255,255,255))));

	
  hourLcd = new QLCDNumber(setAlarmFrame, "hourLcd");
  hourLcd->setNumDigits(2);
  hourLcd->display(1);
  hourLcd->setSegmentStyle(QLCDNumber::Filled);
  hourLcd->setGeometry(0,73,104,66);
  hourLcd->setPalette(QPalette(
			    QColorGroup(QColor(255,0,0), QColor(192,192,192),
					QColor(255,255,255),QColor(96,96,96),QColor(160,160,160),
					QColor(0,0,0),QColor(255,255,255)),
			    QColorGroup(QColor(0,0,0), QColor(192,192,192),
					QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					QColor(160,160,160),QColor(255,255,255)),
			    QColorGroup(QColor(0,0,0), QColor(192,192,192),
					QColor(245,245,245), QColor(68,68,68), QColor(160,160,160),
					QColor(0,0,0),QColor(255,255,255))));

	
  hourScrollBar = new QScrollBar(setAlarmFrame, "hourScrollBar");
  hourScrollBar->setValue(1);
  hourScrollBar->setRange(0,23);
  hourScrollBar->setOrientation(QScrollBar::Horizontal);
  hourScrollBar->setGeometry(0,139,104,35);

	
  minuteScrollBar = new QScrollBar(setAlarmFrame, "minuteScrollBar");
  minuteScrollBar->setValue(30);
  minuteScrollBar->setRange(0,59);
  minuteScrollBar->setOrientation(QScrollBar::Horizontal);
  minuteScrollBar->setGeometry(140,138,104,35);

  //topLayout->setMenuBar(menuBar());
  //topLayout->addWidget(menuBar());
  //topLayout->packStart(menuBar());
  //qmenuBar = new QMenuBar();

  //topLayout->setMenuBar(qmenuBar);
  //vmuMenuBar = new KMenuBar(this);
  //topLayout->addWidget(vmuMenuBar);

  //topLayout->addStretch(1);
  

  //topLayout->addLayout(alarmButtonsLayout, 1);
  //alarmButtonsLayout->addWidget(startAlarmButton);
  //alarmButtonsLayout->addWidget(setAlarmButton);

  //topLayout->addWidget(setAlarmButton, 2);
  topLayout->addWidget(snoozeButton, 2);
  topLayout->addLayout(timeLayout,2);


  


  //KContainerLayout *timeLayout = new KContainerLayout(topLayout,"timeLayout", KContainerLayout::Horizontal);
  
  timeLayout->addWidget(hourLcd,2);
  timeLayout->addWidget(colonLabel,1);
  timeLayout->addWidget(minuteLcd,2);
  
  topLayout->addLayout(timeControlLayout,1);

  
  /* KContainerLayout *timeControlLayout = new KContainerLayout(topLayout,"timeControlLayout", KContainerLayout::Horizontal);  
   */
  
  timeControlLayout->addWidget(hourScrollBar);
  timeControlLayout->addWidget(minuteScrollBar);

  topLayout->addWidget(chooseMp3Button,1);
  topLayout->addWidget(fileTextBox,1);
  topLayout->addWidget(choosePlayerButton,1);
  topLayout->addWidget(playerTextBox,1);


  topLayout->addLayout(snoozeLayout,2);  
  
  /*  KContainerLayout *snoozeLayout = new KContainerLayout(topLayout,"snoozeLayout", KContainerLayout::Horizontal); */
  
  snoozeLayout->addWidget(snoozeLcd);
  snoozeLayout->addLayout(snoozeLengthLayout);

  snoozeLengthLayout->addWidget(snoozeScrollBar);
  snoozeLengthLayout->addSpacing(4);
  snoozeLengthLayout->addWidget(snoozeLengthLabel);
  snoozeLengthLayout->addSpacing(4);
  //topLayout->activate();

  

  

  QObject::connect(minuteScrollBar,SIGNAL(valueChanged(int)),
		   minuteLcd,SLOT(display(int)));
  QObject::connect(hourScrollBar,SIGNAL(valueChanged(int)),
		   hourLcd,SLOT(display(int)));
  QObject::connect(choosePlayerButton,SIGNAL(clicked()),
		   this,SLOT(choosePlayer()));
  QObject::connect(chooseMp3Button,SIGNAL(clicked()),
		   this,SLOT(chooseMp3()));
  QObject::connect(snoozeButton,SIGNAL(clicked()),
		   this,SLOT(snoozeIt()));
  QObject::connect(snoozeScrollBar,SIGNAL(valueChanged(int)),
		   snoozeLcd,SLOT(display(int)));
  QObject::connect(mainTimer,SIGNAL(timeout()),
		   this,SLOT(checkTime()));
  /* QObject::connect(setAlarmButton,SIGNAL(clicked()),
		   this,SLOT(setAlarm()));
  QObject::connect(startAlarmButton,SIGNAL(clicked()),
		   this,SLOT(startAlarm));
  */
  /* initializers */
  alarmRunning=false;
  childPID=0;

  //topLayout->activate();
  

  

}


void VigmeupApp::initMenuBar()
{

  //qmenuBar = new QMenuBar();
  ///////////////////////////////////////////////////////////////////
  // MENUBAR  

  ///////////////////////////////////////////////////////////////////
  // menuBar entry file_menu
  file_menu = new QPopupMenu();
  //file_menu->insertItem(Icon("mini/vigmeupapp.xpm"), i18n("New &Window"), ID_FILE_NEW_WINDOW );
  // file_menu->insertSeparator();
  // file_menu->insertItem(Icon("filenew.xpm"), i18n("&New"), ID_FILE_NEW );
  file_menu->insertItem(Icon("fileopen.xpm"), i18n("Choose Audio &File..."), ID_FILE_CHOOSE_MP3 );
  // file_menu->insertSeparator();
  //  file_menu->insertItem(Icon("filefloppy.xpm") ,i18n("&Save"), ID_FILE_SAVE );
  file_menu->insertItem(Icon("fileopen.xpm"), i18n("Choose Audio &Player..."), ID_FILE_CHOOSE_PLAYER );
  /*  file_menu->insertItem(i18n("&Close"), ID_FILE_CLOSE );
      file_menu->insertSeparator();
      file_menu->insertItem(Icon("fileprint.xpm"), i18n("&Print"), ID_FILE_PRINT );
      file_menu->insertSeparator();
      file_menu->insertItem(i18n("C&lose Widow"), ID_FILE_CLOSE_WINDOW);
  */
  file_menu->insertSeparator();
  file_menu->insertItem(i18n("E&xit"), ID_FILE_QUIT );

  // file_menu key accelerators

  file_menu->setAccel(CTRL+Key_F, ID_FILE_CHOOSE_MP3);
  file_menu->setAccel(CTRL+Key_P, ID_FILE_CHOOSE_PLAYER);


  ///////////////////////////////////////////////////////////////////
  // menuBar entry action_menu
  action_menu = new QPopupMenu();
  action_menu->insertItem(i18n("&Snooze"), ID_ACTION_SNOOZE );
  
  //  action_menu->insertItem(Icon("editcopy.xpm"), i18n("&Copy"), ID_EDIT_COPY );
  // action_menu->insertItem(Icon("editpaste.xpm"), i18n("&Paste"), ID_EDIT_PASTE );
 
  //action_menu key accelerators
  action_menu->setAccel(CTRL+Key_S, ID_ACTION_SNOOZE);

 

  ///////////////////////////////////////////////////////////////////
  // EDIT YOUR APPLICATION SPECIFIC MENUENTRIES HERE
  

  ///////////////////////////////////////////////////////////////////
  // menuBar entry help_menu
  help_menu = new QPopupMenu();
  help_menu = kapp->getHelpMenu(true, i18n(IDS_APP_ABOUT));


  ///////////////////////////////////////////////////////////////////
  // MENUBAR CONFIGURATION
  // set menuBar() the current menuBar and the position due to config file
  //qmenuBar = new QMenuBar();

  vmuMenuBar = new KMenuBar(this);
  //vmuMenuBar->setMenuBarPos(KMenuBar::Top);
  //menuBar()->insertItem(i18n("&File"), file_menu);
  //menuBar()->insertItem(i18n("&Action"), action_menu);
  vmuMenuBar->insertItem(i18n("&File"), file_menu);
  vmuMenuBar->insertItem(i18n("&Action"), action_menu);
  //disableCommand(ID_ACTION_SNOOZE);  
  //menuBar()->insertItem(i18n("&View"), view_menu);

  ///////////////////////////////////////////////////////////////////
  // INSERT YOUR APPLICATION SPECIFIC MENUENTRIES HERE


  //menuBar()->insertSeparator();
  //menuBar()->insertItem(i18n("&Help"), help_menu);
  vmuMenuBar->insertSeparator();
  vmuMenuBar->insertItem(i18n("&Help"), help_menu);


  ///////////////////////////////////////////////////////////////////
  // CONNECT THE SUBMENU SLOTS WITH SIGNALS

  CONNECT_CMD(file_menu);
  CONNECT_CMD(action_menu);
  // CONNECT_CMD(view_menu);

  //menuBar() = qmenuBar;
  //KMenuBar *kmenu = new KMenuBar(qmenuBar);
  //this->setMenu((KMenuBar *)qmenuBar);
}
/*void VigmeupApp::initToolBar()
{

  ///////////////////////////////////////////////////////////////////
  // TOOLBAR
  // set toolBar() the current toolBar and the position due to config file
  toolBar()->insertButton(Icon("filenew.xpm"), ID_FILE_NEW, true, i18n("New File"));
  toolBar()->insertButton(Icon("fileopen.xpm"), ID_FILE_CHOOSE_MP3, true, i18n("Open File"));
  toolBar()->insertButton(Icon("filefloppy.xpm"), ID_FILE_SAVE, true, i18n("Save File"));
  toolBar()->insertButton(Icon("fileprint.xpm"), ID_FILE_PRINT, true, i18n("Print"));
  toolBar()->insertSeparator();
  toolBar()->insertButton(Icon("editcut.xpm"), ID_ACTION_SNOOZE, true, i18n("Cut"));
  toolBar()->insertButton(Icon("editcopy.xpm"), ID_EDIT_COPY, true, i18n("Copy"));
  toolBar()->insertButton(Icon("editpaste.xpm"), ID_EDIT_PASTE, true, i18n("Paste"));
  toolBar()->insertSeparator();
  toolBar()->insertButton(Icon("help.xpm"), ID_HELP, SIGNAL(pressed()), kapp, SLOT(appHelpActivated()), true, i18n("Help"));

  ///////////////////////////////////////////////////////////////////
  // INSERT YOUR APPLICATION SPECIFIC TOOLBARS HERE -e.g. tool_bar_1:
  // add functionality for new created toolbars in:
  // enableCommand, disableCommand, in the menuBar() and an additional function slotViewToolbar_1
  // for that also create a bViewToolbar_1 and a KConfig entry (see Constructor).
  // Also update resource values and commands 


  ///////////////////////////////////////////////////////////////////
  // CONNECT THE TOOLBAR SLOTS WITH SIGNALS - add new created toolbars
  CONNECT_TOOLBAR(toolBar());

} */

void VigmeupApp::initStatusBar()
{
  ///////////////////////////////////////////////////////////////////
  //STATUSBAR
  //statusBar()->insertItem(IDS_DEFAULT, ID_STATUS_MSG );
  //statusBar()->setInsertOrder(KStatusBar::RightToLeft);
  vmuStatusBar = new KStatusBar(this);
  vmuStatusBar->insertItem(IDS_DEFAULT, ID_STATUS_MSG );
  vmuStatusBar->setInsertOrder(KStatusBar::RightToLeft);
  //setStatusBar(vmuStatusBar);
}

/*void VigmeupApp::initView()
{ 
  doc = new VigmeupDoc(this);

  ////////////////////////////////////////////////////////////////////
  // set the main widget here
  KApplication *app=KApplication::getKApplication();
  view = new VigmeupView(app,doc,this);
  setView(view);

} */

bool VigmeupApp::queryExit()
{
  /*int exit=KMsgBox::yesNo(this, i18n("Exit"), i18n("Really Quit ?"));

  if(exit==1)
    return true;
  else
  return false;*/
  return true;
}

void VigmeupApp::saveOptions()
{
  KConfig *config = kapp->getConfig();

  config->setGroup("GENERAL");
  config->writeEntry("mp3file", fileTextBox->text());
  config->writeEntry("mp3Player", playerTextBox->text());
  config->writeEntry("snoozeLength", snoozeScrollBar->value());
  config->writeEntry("LastHour", hourScrollBar->value());
  config->writeEntry("LastMinute", minuteScrollBar->value());

  config->setGroup("APPEARANCE");
  config->writeEntry("ShowToolbar",toolBar()->isVisible());
  config->writeEntry("ShowStatusbar",statusBar()->isVisible());
  config->writeEntry("MenuBarPos", (int)menuBar()->menuBarPos());
  config->writeEntry("ToolBar_Pos", (int)toolBar()->barPos());

}

void VigmeupApp::readOptions()
{
  ///////////////////////////////////////////////////////////////////
  // read the config file entries
  KConfig *config = kapp->getConfig();

  config->setGroup("GENERAL");
  fileTextBox->setText(config->readEntry("mp3file", "No Mp3 File Selected."));
  snoozeLength=config->readNumEntry("snoozeLength", 10);
  snoozeScrollBar->setValue(snoozeLength);
  mp3Player=config->readEntry("mp3Player", "No Player Selected.");
  playerTextBox->setText(mp3Player);
  hourScrollBar->setValue(config->readNumEntry("LastHour", 1));
  minuteScrollBar->setValue(config->readNumEntry("LastMinute", 30));	
  config->setGroup("APPEARANCE");
  bViewToolbar = config->readBoolEntry("ShowToolbar", true);
  bViewStatusbar = config->readBoolEntry("ShowStatusbar", true);
  //menu_bar_pos = (KMenuBar::menuPosition)config->readNumEntry("MenuBarPos", KMenuBar::Top); 
  //  tool_bar_pos = (KToolBar::BarPosition)config->readNumEntry("ToolBar_Pos", KToolBar::Top);

}


/////////////////////////////////////////////////////////////////////
// SLOT IMPLEMENTATION
/////////////////////////////////////////////////////////////////////

/*void VigmeupApp::slotFileNewWindow()
{
  slotStatusMsg(i18n("Opening a new Application window..."));
  (new VigmeupApp)->show();
  slotStatusMsg(IDS_DEFAULT);
}

void VigmeupApp::slotFileNew()
{
  slotStatusMsg(i18n("Creating new file..."));

  slotStatusMsg(IDS_DEFAULT);
}

void VigmeupApp::slotFileOpen()
{
  slotStatusMsg(i18n("Opening file..."));

  slotStatusMsg(IDS_DEFAULT);
}


void VigmeupApp::slotFileSave()
{
  slotStatusMsg(i18n("Saving file..."));

  slotStatusMsg(IDS_DEFAULT);
}

void VigmeupApp::slotFileSaveAs()
{
  slotStatusMsg(i18n("Saving file under new filename..."));

  slotStatusMsg(IDS_DEFAULT);
}

void VigmeupApp::slotFileClose()
{
  slotStatusMsg(i18n("Closing file..."));

  slotStatusMsg(IDS_DEFAULT);
}


void VigmeupApp::slotFileCloseWindow()
{
  close();
}
*/
void VigmeupApp::slotFileQuit()
{ 

  ///////////////////////////////////////////////////////////////////
  // exits the Application
  if(this->queryExit())
    {
      saveOptions();
      KTMainWindow::deleteAll();
      kapp->quit();
    }
  else
    slotStatusMsg(IDS_DEFAULT);
  return;
}

void VigmeupApp::slotViewStatusBar()
{
  ///////////////////////////////////////////////////////////////////
  //turn Statusbar on or off
  //bViewStatusobar=!bViewStatusbar;
  //menuBar()->setItemChecked(ID_VIEW_STATUSBAR, bViewStatusbar);
  enableStatusBar();
  slotStatusMsg(IDS_DEFAULT);
}


void VigmeupApp::slotStatusMsg(const char *text)
{
  ///////////////////////////////////////////////////////////////////
  // change status message permanently
  statusBar()->clear();
  statusBar()->changeItem(text, ID_STATUS_MSG );

}


void VigmeupApp::slotStatusHelpMsg(const char *text)
{
  ///////////////////////////////////////////////////////////////////
  // change status message of whole statusbar temporary (text, msec)
  statusBar()->message(text, 2000);
}



void VigmeupApp::commandCallback(int id_){
  switch (id_){
    ON_CMD(ID_FILE_CHOOSE_MP3,                chooseMp3())
      ON_CMD(ID_FILE_CHOOSE_PLAYER,             choosePlayer())
      ON_CMD(ID_ACTION_SNOOZE,                 snoozeIt())
      ON_CMD(ID_FILE_QUIT,									slotFileQuit())
      }
}

void VigmeupApp::statusCallback(int id_){
  switch (id_){
    ON_STATUS_MSG(ID_FILE_CHOOSE_MP3,         i18n("Chooses Mp3 to Play"))
      ON_STATUS_MSG(ID_FILE_CHOOSE_PLAYER,      i18n("Choose Mp3 Player"))
      ON_STATUS_MSG(ID_ACTION_SNOOZE,          i18n("Snoozes the Alarm"))
      ON_STATUS_MSG(ID_FILE_QUIT,	i18n("Quit VigMeUp"))
      }
}



void
VigmeupApp::checkTime()
{
  if (!alarmOn()) {
    QTime qCurrent;
    QTime qDesired;
    qCurrent.start();
    qDesired.setHMS(hourLcd->intValue(), minuteLcd->intValue(), 0,0);
    //qCurrent.setHMS(QTime::currentTime().hour(), QTime::currentTime().minute(),0,0);
    if (qCurrent.hour() == qDesired.hour())
      { 
	if (qCurrent.minute() == qDesired.minute())
	  { 
	    playMp3(fileTextBox->text(), playerTextBox->text());
	    toggleAlarm();
	  }
      }
  }
  /*else {
    if (!hasFocus()) {
    setFocus();
    }
    }*/
}

bool
VigmeupApp::alarmOff()
{
  return !alarmOn();
}

void
VigmeupApp::toggleAlarm()
{
  if (alarmOff()) {
    
    snoozeButton->setEnabled(true);
    //enableCommand(ID_ACTION_SNOOZE);
    //snoozeButton->show();
    alarmRunning = true;
  }
  else 	
    {
      snoozeButton->setEnabled(false);
      //disableCommand(ID_ACTION_SNOOZE);
      //snoozeButton->hide();
      alarmRunning = false;
    }
  
}

bool
VigmeupApp::alarmOn()
{
  return alarmRunning;
}

void
VigmeupApp::playMp3(const char *mp3File, const char *mp3Player)
{
	

  //Mp3s are cool
  //I wonder if system calls break Windows boxes from using this.
  //Oh well.
	
  QString qmp3File(mp3File);
  //QString temp2("/usr/X11/bin/x11amp ");
  QString andString(" &");
  //QString temp;
	
  //Here is some neat stuff, July 30, 1998 still no phone...
  //Fixes some of the /dev/dsp bugs (hopefully) by ruthlessly
  //killing previous instances of this new global variable, mp3Player
  //SRM
  QString qmp3Player(mp3Player);
  QString killString ="killall " + qmp3Player;
  system(killString);
  
  //Trying to hack in " support jun 21 1998 SRM
  //(And it was successful, jun21 SRM)
	
  QString playString =qmp3Player + " \"" + qmp3File + "\"" + andString;
	
  //temp=mp3File;
  //temp+=" &";
  //fileTextBox->setText(temp);
  //(char *) temp;
  //This won't be here soon...SRM JUL 30 1998
	

  system(playString);
 
  /*  if (hasFocus()) {
    cout <<"Thinks it has focus" << endl;
  }
  else {
    cout << "Doesn't have focus" << endl;
    }*/
  //setFocus();

  slotStatusMsg("Playing, hit Snooze Bar to Snooze");

  
}

void
VigmeupApp::chooseMp3()
{
  //fileTextBox->setText(QFileDialog::getOpenFileName(0, "*.mp3"));
  fileTextBox->setText(KFileDialog::getOpenFileName(0,"*.mp2 *.mp3"));
}

void
VigmeupApp::snoozeIt()
{
  //Check to see if the alarm is actually on.
  if (alarmOn()) {
    //Give us some new numbers!
    snoozeLength=snoozeLcd->intValue();
    int n=snoozeLength;
    int newHourLcd=hourLcd->intValue();
    int newMinuteLcd=minuteLcd->intValue();
    while (snoozeLength>0) {
      if (snoozeLength >= 60) {
	if (newHourLcd == 23) {
	  newHourLcd=0;
	} //if
	else {
	  newHourLcd+=1;
	} //else
	snoozeLength-=60;
      } //if
      else if ((newMinuteLcd + snoozeLength) >= 60)  {	
	if (newHourLcd == 23) {
	  newHourLcd=0;
	} //if
	else {
	  newHourLcd+=1;
	} //else
	newMinuteLcd+=(snoozeLength-60);
	snoozeLength=0;
      } //if
      else {
	newMinuteLcd+=snoozeLength;
	snoozeLength=0;
      } //else
    } //while
    
    //Use signals to change the actual Lcd values.
    //emit(changeHourLcd(newHourLcd));
    //emit(changeMinuteLcd(newMinuteLcd));
    hourScrollBar->setValue(newHourLcd);
    minuteScrollBar->setValue(newMinuteLcd);

    system("killall " + mp3Player);
    toggleAlarm();
    snoozeLength=n;
    slotStatusMsg("Ready");

  }

}

void
VigmeupApp::choosePlayer()
{
	
  playerTextBox->setText(KFileDialog::getOpenFileName());
  mp3Player=playerTextBox->text();
	
}

/**
   This should:
   1. Unlock the choosing buttons/menu items
   2. stop the timer
   3. update the status bar
   4. disable its own button and the snooze bar
*/
void VigmeupApp::setAlarm()
{

  /*  setAlarmRunning(false);
  snoozeButton->setEnabled(false);
 
  setAlarmButton->setEnabled(false);
  startAlarmButton->setEnabled(true);
  */
}


/** This function should:
    1. Lock the choosing buttons/menu items
    2. Start the alarm timer
    3. Disable its own button
    4. update the status bar
*/
void VigmeupApp::startAlarm()
{
  /*  mp3Player = playerTextBox->text();
mp3File = fileTextBox->text();
  setAlarmRunning(true);
  snoozeButton->setEnabled(false);
  setAlarmButton->setEnabled(false);
  startAlarmButton->setEnabled(true); 
  */
}

void VigmeupApp::setAlarmRunning(bool b){

  alarmRunning = b;
}
























