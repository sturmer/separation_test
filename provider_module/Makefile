provider_name := provider

.PHONY: all
all: main

%.o: %.cpp
	g++ -Wall -Werror -fPIC -c $<

.PHONY: $(provider_name)
$(provider_name): provider.o resource.o
	g++ -shared -Wl,-soname,lib$@.so.1 -o lib$@.so.1.0 $^
	ln -sf lib$@.so.1.0 lib$@.so.1 
	ln -sf lib$@.so.1 lib$@.so

main.o: main.cpp
	g++ -g -Wall -Werror -c $<

main: main.o $(provider_name) 
	g++ $< -L. -l$(provider_name) -o $@ 

clean:
	rm -f *.o lib$(provider_name).so* main

love:
	@echo "...not war!"
