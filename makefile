all: ChannelFlow.cpp
	g++ -g -Wall -o run ChannelFlow.cpp

clean:
	$(RM) run output.txt
	