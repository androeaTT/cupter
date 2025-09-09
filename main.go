//	  App for quick adding games shortcuts to menu and steam
//    Copyright (C) 2025  androeaTT
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.




package main

import (
	"github.com/diamondburned/gotk4-adwaita/pkg/adw"
	// "github.com/diamondburned/gotk4/pkg/gdk/v4"
	"github.com/diamondburned/gotk4/pkg/gio/v2"
	// "github.com/diamondburned/gotk4/pkg/glib/v2"
	// "github.com/diamondburned/gotk4/pkg/gtk/v4"
)

func main() {
	app := adw.NewApplication("com.androeat.cupter", gio.ApplicationGetDefault().Flags())


	app.ConnectActivate(func() {
		
	})
}