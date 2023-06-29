SYSCONF_LINK = g++
CPPFLAGS     =
LDFLAGS      =
LIBS         = -lm

DESTDIR = ./
TARGET  = main

CONVERTABLE := $(wildcard *.tga)

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

#convert to png
convert:
	convert $(CONVERTABLE).tga $(CONVERTABLE).png

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)
	-rm -f *.tga
