//  Cupter. Desktop entries files manager
//  Copyright (C) 2025  @androeaTT
//  Application.h
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include <adwaita.h> 
#include <gtkmm-4.0/gtkmm.h>
#include <gtkmm-4.0/gdkmm.h>

class Application
{
private:
    static Application* s_Instance;
    static void onAppActivate (AdwApplication* app, gpointer user_data);
    static gboolean onWindowClose(GtkWidget* widget, GdkEvent* event, gpointer user_data);    
    
    void MainWindowSetup (Glib::RefPtr<Gtk::Builder> builder);
    AdwApplication* m_AdwApp;
    AdwApplicationWindow* m_MainWindow;
    GSettings* m_GSettings;
public:
    static int Run (int argc, char** argv);
    static Application* getApplication();   

    int Init (int argc, char** argv);
};