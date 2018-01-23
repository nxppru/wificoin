
Debian
====================
This directory contains files used to package wificoind/wificoin-qt
for Debian-based Linux systems. If you compile wificoind/wificoin-qt yourself, there are some useful files here.

## wificoin: URI support ##


wificoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install wificoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your wificoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/wificoin128.png` to `/usr/share/pixmaps`

wificoin-qt.protocol (KDE)

