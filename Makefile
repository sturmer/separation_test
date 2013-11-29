%.o: %.cpp
	g++ -c -g -Wall -Werror $<

all: interface.o new_main.o
	g++ -L./provider_module/ interface.o new_main.o \
		-lprovider -o new_provider -ldl

libprovider:
	cd provider_module && $(MAKE) provider

clean:
	cd provider_module && $(MAKE) clean
	rm new_provider *.o
