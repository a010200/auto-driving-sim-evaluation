#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

using namespace std;

class Logger{
public:
    Logger(string fileName);

    void writeHeader();
    void writeData(double time,
                   double egoPosition,
                   double egoVelocity,
                   double egoAcceleration,
                   double leadPosition,
                   double leadVelocity,
                   double leadAcceleration,
                   double distance);

private:
    ofstream m_file;
};

#endif
