//  Cupter. Desktop entries manager
//  Copyright (C) 2025  @androeaTT
//  HeaderBar.h 
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

class MainPage;

class HeaderBar
{
private:
    static HeaderBar* s_Instance;

    GtkBuilder* m_Builder;
    GtkWidget* m_Widget;
    GtkWidget* m_StSwitcher;
public:
    static HeaderBar* getHeaderBar();

    HeaderBar();
    ~HeaderBar();

    GtkWidget* getWidget();
    GtkWidget* getStSwitcher();
};