
Debian
====================
This directory contains files used to package eycod/eyco-qt
for Debian-based Linux systems. If you compile eycod/eyco-qt yourself, there are some useful files here.

## eyco: URI support ##


eyco-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install eyco-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your eycoqt binary to `/usr/bin`
and the `../../share/pixmaps/eyco128.png` to `/usr/share/pixmaps`

eyco-qt.protocol (KDE)

