# ----------------------------
# Makefile Options
# ----------------------------

NAME = CrossyRD
ICON = icon.png
DESCRIPTION = "Crossy Road"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)