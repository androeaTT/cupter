//  Cupter. Desktop entries files manager
//  Copyright (C) 2025  @androeaTT
//  MainPage.cpp
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

#include "MainPage.h"
#include "HeaderBar.h"

MainPage* MainPage::s_Instance = nullptr;

MainPage::MainPage()
{
    m_Builder = gtk_builder_new_from_resource("/io/github/androeat/cupter/mainPage.ui");
    m_Widget = GTK_WIDGET( gtk_builder_get_object(m_Builder, "MainPage") );
    m_MainStack = GTK_WIDGET( gtk_builder_get_object(m_Builder, "MainStack") );
    
    MainPage::s_Instance = this;

    GtkBox* mainPageBox = GTK_BOX( gtk_builder_get_object(m_Builder, "MainPageBox") );
    m_HeaderBar = HeaderBar::getHeaderBar();
    gtk_box_prepend(mainPageBox, m_HeaderBar->getWidget());
    

}

MainPage::~MainPage()
{
}

GtkWidget* MainPage::getWidget()
{
    return m_Widget;
}

MainPage* MainPage::getMainPage()
{
    if (!MainPage::s_Instance)
    {
        MainPage::s_Instance = new MainPage();
    }
    return MainPage::s_Instance;
}

GtkWidget* MainPage::getMainStack() 
{
    return m_MainStack;
}