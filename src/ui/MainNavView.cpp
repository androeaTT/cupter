//  Cupter. Desktop entries files manager
//  Copyright (C) 2025  @androeaTT
//  MainNavView.cpp
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

#include "MainNavView.h"

MainNavView* MainNavView::s_Instance = nullptr;

MainNavView::MainNavView()
{
    m_Widget = GTK_WIDGET( adw_navigation_view_new() );
    m_MainPage = new MainPage();
    adw_navigation_view_add(
        ADW_NAVIGATION_VIEW( m_Widget ), 
        ADW_NAVIGATION_PAGE( m_MainPage->getWidget() )
    );
}

MainNavView::~MainNavView()
{
}

GtkWidget* MainNavView::getWidget()
{
    return m_Widget;
}

MainNavView* MainNavView::getMainNavView()
{
    if (!MainNavView::s_Instance) 
    {
        MainNavView::s_Instance = new MainNavView();
    }
    return MainNavView::s_Instance;
}