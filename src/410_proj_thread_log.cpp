//============================================================================
// Name        : 410_proj_thread_log.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <thread>
#include <iostream>
#include <vector>
#include "../includes/constants.h"
#include "../includes/Logger.h"

using namespace std;

//NOTE: you should have no mutexes in this file
//TODO linker errors?  Did you include the pthread library?   And set the proper dialect?
//TODO declare globals
Logger fileLog(LOG_FILE,FILENAME);
Logger consoleLog(LOG_CONSOLE,FILENAME);
/***
 * TODO log info to both file and console. You can do this with 2 Logger objects. 
 * 		Note:  These logger objects cannot be local variables, they must be shared 
 * 		amongst the threads. (why?)
 * TODO this function should run until main (or another thread) asks it to quit
 * @param info  to log
 * returns void
 */
void fun(string info){
     fileLog.Log(info);
     consoleLog.Log(info);
}

int main() {
	vector<thread*> listOfThreads;
	for(int i = 0; i < thread::hardware_concurrency(); i++){
		listOfThreads.push_back(new thread(fun, "new thread" + to_string(i)));
	}
	//TODO save these threads in a vector

	//TODO let threads run a bit (5 seconds)
	this_thread::sleep_for(chrono::milliseconds(5000));
	
	//TODO ask them all to stop
	for(int i = 0; i < listOfThreads.size(); i++) {
		listOfThreads.at(i)->join();
	}
	//TODO wait for all threads to finish
	
	return 0;
}
