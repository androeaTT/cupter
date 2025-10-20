#!/bin/bash

pkexec bash -c "cp $1/src/assets/gio/io.github.androeat.cupter.gschema.xml /usr/share/glib-2.0/schemas/; glib-compile-schemas /usr/share/glib-2.0/schemas/"