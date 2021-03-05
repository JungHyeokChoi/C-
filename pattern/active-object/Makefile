testSleepCommand : Command.h ActiveObjectEngine.h ActiveObjectEngine.cpp SleepCommand.h SleepCommand.cpp TestSleepCommand.cpp 
	g++ ActiveObjectEngine.cpp SleepCommand.cpp TestSleepCommand.cpp -o testSleepCommand -lcppunit

delayedTyper : Command.h ActiveObjectEngine.h ActiveObjectEngine.cpp SleepCommand.h SleepCommand.cpp DelayedTyper.cpp
	g++ ActiveObjectEngine.cpp SleepCommand.cpp DelayedTyper.cpp -o delayedTyper

all : testSleepCommand delayedTyper

clean : 
	rm testSleepCommand delayedTyper
