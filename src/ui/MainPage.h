//  Cupter. Desktop entries files manager
//  Copyright (C) 2025  @androeaTT
//  MainPage.h
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

#include <gtkmm-4.0/gtkmm.h>
#include <adwaita.h>

class HeaderBar;

class MainPage
{
private:
    static MainPage* s_Instance;

    GtkWidget* m_Widget;
    GtkBuilder* m_Builder;
    GtkWidget* m_MainStack;
    HeaderBar* m_HeaderBar;
public:
    static MainPage* getMainPage();

    MainPage();
    ~MainPage();
    GtkWidget* getWidget();
    GtkWidget* getMainStack();
};