//  Cupter. Desktop entries manager
//  Copyright (C) 2025  @androeaTT
//  HeaderBar.cpp 
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

#include "HeaderBar.h"
#include "MainPage.h"

HeaderBar* HeaderBar::s_Instance = nullptr;

HeaderBar::HeaderBar()
{
    m_Builder = gtk_builder_new_from_resource("/io/github/androeat/cupter/headerbar.ui");
    m_Widget = GTK_WIDGET( gtk_builder_get_object(m_Builder, "MainHeaderBar") );
    m_StSwitcher = GTK_WIDGET( gtk_builder_get_object(m_Builder, "HeaderStackSwitcher") );

    AdwViewStack* mainstack = ADW_VIEW_STACK( MainPage::getMainPage()->getMainStack() );
    adw_view_switcher_set_stack(ADW_VIEW_SWITCHER( m_StSwitcher ), mainstack);
}
HeaderBar::~HeaderBar()
{
}

GtkWidget* HeaderBar::getWidget()
{
    return m_Widget;
}

GtkWidget* HeaderBar::getStSwitcher()
{
    return m_StSwitcher;
}

HeaderBar* HeaderBar::getHeaderBar()
{
    if (!HeaderBar::s_Instance) 
    {
        HeaderBar::s_Instance = new HeaderBar();
    }

    return HeaderBar::s_Instance;
}
