
Debian
====================
This directory contains files used to package dailycryptod/dailycrypto-qt
for Debian-based Linux systems. If you compile dailycryptod/dailycrypto-qt yourself, there are some useful files here.

## dailycrypto: URI support ##


dailycrypto-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install dailycrypto-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your dailycrypto-qt binary to `/usr/bin`
and the `../../share/pixmaps/dailycrypto128.png` to `/usr/share/pixmaps`

dailycrypto-qt.protocol (KDE)

