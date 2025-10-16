//  Cupter. Desktop entries manager
//  Copyright (C) 2025  @androeaTT
//  Application.cpp 
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

#include "Application.h"
#include <CLI/CLI.hpp>
#include <string>
#include <iostream>
#include <gtkmm-4.0/gtkmm.h>
#include <gtkmm-4.0/gdkmm.h>
#include <adwaita.h>
#include <giomm.h> 

Application* Application::s_Instance;

int Application::Run (int argc, char** argv) 
{
    s_Instance = new Application();
    s_Instance->Init (argc, argv);
    
    int ret = g_application_run (G_APPLICATION (s_Instance->m_AdwApp), argc, argv);


    return ret;
}

//Class initialization
int Application::Init (int argc, char** argv) 
{
    m_AdwApp = adw_application_new ("io.github.androeat.cupter", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect (m_AdwApp, "activate", G_CALLBACK(Application::onAppActivate), NULL); 
    Glib::init();
    m_GSettings = g_settings_new("io.github.androeat.cupter");

    return 0;
} 

gboolean Application::onWindowClose(GtkWidget* widget, GdkEvent* event, gpointer user_data)
{
    auto window = GTK_WIDGET (widget);
    GSettings* settings = Application::getApplication()->m_GSettings;
    
    g_settings_set_int(settings, "window-width", gtk_widget_get_width(window));
    g_settings_set_int(settings, "window-height", gtk_widget_get_height(window));

    return FALSE;  
} 

void Application::onAppActivate (AdwApplication* app, gpointer user_data)
{
    auto builder = Gtk::Builder::create_from_resource ("/io/github/androeat/cupter/mainwindow.ui");
    Application::getApplication()->MainWindowSetup(builder);

    gtk_application_add_window( GTK_APPLICATION (Application::getApplication()->m_AdwApp), GTK_WINDOW( Application::getApplication()->m_MainWindow ));
}

//window creation and resize
void Application::MainWindowSetup(Glib::RefPtr<Gtk::Builder> builder) 
{
    GtkBuilder* c_builder = GTK_BUILDER(builder->gobj());
    GtkWidget* main_window = GTK_WIDGET(gtk_builder_get_object(c_builder, "MainWindow"));
    m_MainWindow = ADW_APPLICATION_WINDOW(main_window);

    g_signal_connect (GTK_WINDOW(m_MainWindow), "close-request", G_CALLBACK(Application::onWindowClose), NULL);

    int width = g_settings_get_int(m_GSettings, "window-width");
    int heigth = g_settings_get_int(m_GSettings, "window-height");

    gtk_window_set_default_size( GTK_WINDOW (m_MainWindow), width, heigth );
    gtk_window_present ( GTK_WINDOW (m_MainWindow) );
}

//get class singleton object
Application* Application::getApplication () 
{
    return Application::s_Instance;
}