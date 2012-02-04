/***************************************************************************
                          resource.h  -  description                              
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


#ifndef RESSOURCE_H
#define RESSOURCE_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

///////////////////////////////////////////////////////////////////
// resource.h  -- contains macros used for commands


///////////////////////////////////////////////////////////////////
// COMMAND VALUES FOR MENUBAR AND TOOLBAR ENTRIES


///////////////////////////////////////////////////////////////////
// File-menu entries
#define ID_FILE_CHOOSE_MP3                10030


#define ID_FILE_CHOOSE_PLAYER             10060
#define ID_FILE_QUIT											10070

///////////////////////////////////////////////////////////////////
// Edit-menu entries
#define ID_ACTION_SNOOZE                 11040


///////////////////////////////////////////////////////////////////
// View-menu entries                    
   #define ID_VIEW_STATUSBAR	12010
///////////////////////////////////////////////////////////////////
// Help-menu entries
#define ID_HELP                     1002

///////////////////////////////////////////////////////////////////
// General application values
#define ID_STATUS_MSG               1001

#define IDS_DEFAULT                 "Ready."

#define IDS_APP_ABOUT               "VigMeUp Version " VERSION "\nCopyright 1997, 1998, 1999\nSean R. Melody\n\nVisit VigMeUp on the Web at:\nhttp://www.c-nix.com/vigmeup\n\nEmail all comments, suggestions\nand virtual beers to\nvigmeup@c-nix.com"






///////////////////////////////////////////////////////////////////
// MACROS FOR THE CONNECT OF YOUR SIGNALS TO CORRESPONDENT SLOTS 
// IN YOUR MAIN IMPLEMENTATION OF MENUBAR AND TOOLBAR


///////////////////////////////////////////////////////////////////
// MENU CONNECTS
#define CONNECT_CMD(submenu)           connect(submenu, SIGNAL(activated(int)), SLOT(commandCallback(int)));connect(submenu,SIGNAL(highlighted(int)), SLOT(statusCallback(int)))


///////////////////////////////////////////////////////////////////
// TOOLBAR CONNECT  
#define CONNECT_TOOLBAR(ToolBar)        connect(ToolBar, SIGNAL(clicked(int)), SLOT(commandCallback(int)));connect(ToolBar, SIGNAL(highlighted(int,bool)), SLOT(statusCallback(int)))

///////////////////////////////////////////////////////////////////
// Create cases for entries and connect them with their functions
#define ON_CMD(id, cmd_class_function)   case id:cmd_class_function ;break;

///////////////////////////////////////////////////////////////////
// Create cases for entries and connect them to change statusBar entry
#define ON_STATUS_MSG(id, message)     case id:  slotStatusHelpMsg(message);break;

#endif // RESOURCE_H















