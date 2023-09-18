all: compile link

compile:
	g++ -Isrc/include -c *.cpp 

link:
	g++ *.o -o sfml-app -Lsrc/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 

clean:
	rm -rf *.o sfml-app