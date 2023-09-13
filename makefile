# ----------------------------
# Makefile Options
# ----------------------------

NAME = CrossyRD
ICON = icon.png
DESCRIPTION = "Crossy Road"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

SRC = src/main.cpp src/game.h

# ----------------------------

include $(shell cedev-config --makefile)