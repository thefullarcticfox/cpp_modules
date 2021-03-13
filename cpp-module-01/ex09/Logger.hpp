#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <string>
# include <sstream>
# include <ctime>

class Logger {
private:
	std::string		filename;
	std::ofstream	logfile;
	std::string		makeLogEntry(std::string msg);
	void			logToConsole(std::string msg);
	void			logToFile(std::string msg);
public:
	Logger(std::string file);
	~Logger();
	void			log(std::string const &dest, std::string const &message);
};

#endif
