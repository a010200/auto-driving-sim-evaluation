#include <iostream>
#include "Logger.h"

using namespace std;

Logger::Logger(string fileName){
    m_file.open(fileName);

    if(!m_file.is_open()){
        cout<<"failed to open log file: "<<fileName<<endl;
    }
}

void Logger::writeHeader(){
    m_file<<"time,"
          <<"ego_position,"
          <<"ego_speed,"
          <<"ego_acceleration,"
          <<"lead_position,"
          <<"lead_speed,"
          <<"lead_acceleration,"
          <<"distance,"
          <<"throttle,"
          <<"brake,"
          <<"ttc"<<endl;
}

void Logger::writeData(double time,
                       double egoPosition,
                       double egoVelocity,
                       double egoAcceleration,
                       double leadPosition,
                       double leadVelocity,
                       double leadAcceleration,
                       double distance,
                       double throttle,
                       double brake,
                       double ttc){
    m_file<<time<<","
          <<egoPosition<<","
          <<egoVelocity<<","
          <<egoAcceleration<<","
          <<leadPosition<<","
          <<leadVelocity<<","
          <<leadAcceleration<<","
          <<distance<<","
          <<throttle<<","
          <<brake<<","
          <<ttc<<endl;
}
void Logger::close(){
    m_file.close();
}
