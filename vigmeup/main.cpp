/***************************************************************************
                          main.cpp  -  description                              
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


#include "vigmeup.h" 
 
int main(int argc, char* argv[]) { 
  KApplication app(argc,argv,"vigmeup");  
 
  if (app.isRestored())
    { 
      RESTORE(VigmeupApp);
    }
  else 
    {
      VigmeupApp* vigmeup = new VigmeupApp;
      vigmeup->show();
    }  
  return app.exec();
}  
 
