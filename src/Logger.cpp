/*
 * Logger.cpp
 *
 *  Created on: Mar 29, 2021
 *      Author: keith
 */
#include <iostream>
#include <mutex>
#include "../includes/Logger.h"
using namespace std;

mutex mtx;

Logger::Logger(LOG_TYPE lt, std::string fn){
	this->lt = lt;
	this->fn = fn;
}

Logger::~Logger() {
	return;
}

void Logger::Log(string info) {
	if (this->lt == LOG_FILE) {
		mtx.lock();
		fs.open(this->fn);
		fs << info << endl;
		fs.close();
		mtx.unlock();
	}
	else {
		mtx.lock();
		cout << info << endl;
		mtx.unlock();
	}
}
