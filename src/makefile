#WX_INCLUDE = /c/Darek/app/wxWidgets/include/
WX_INCLUDE = /usr/include/wx-2.8/
INCLUDE = -I$(WX_INCLUDE) -I../gfx
OPTS = `wx-config --cxxflags --libs` 

TARGET = serconf

OBJS = $(sort \
		 main.o \
		 serialConfigurator.o \
		 MainWindow.o \
		 signal.o \
		 MessageGUI.o \
)




all: $(TARGET)

$(TARGET): $(OBJS)
	g++ -o $(TARGET) $(OBJS) $(INCLUDE) $(OPTS)


rebuild: clean all


%.o: %.cpp
	g++ -MD -c -o $@ $(INCLUDE) $< $(OPTS)
	@cp $*.d $*.P; \
		sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $*.d >> $*.P; \
		rm -f $*.d

include $(SRCS:.c=.P)

clean:
	rm -rf *.P *.o $(TARGET)

.PHONY: clean rebuild

