#pragma once
#include <iostream>

#include "cmdParser.hpp"

class Logger {
	public:
		void log(Verbosity level, const char* location, const char* what);
		template<typename... Args>
		void logf(Verbosity level, const char* location, const char* format, Args... args);
		Logger(Verbosity verbosity);
		void setVerbosity(Verbosity verbosity);
	private:
		Verbosity m_verbosity;
};
extern Logger logger;

#include "logf.cpp"
