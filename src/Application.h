#pragma once

#define GUI_TYPE 0
#define ADD_SHORTCUT_TYPE 1
#define CUSTOM_TYPE 2

#include <adwaita.h> 
#include <gtkmm-4.0/gtkmm.h>
#include <gtkmm-4.0/gdkmm.h>

class Application
{
private:
    static Application* s_Instance;
    static int s_RunType;
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