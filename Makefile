dosimeter:
	g++ -o dosimeter -Wall src/main.cpp src/mainFrame.cpp  -Iinclude `wx-config --libs --cxxflags`
