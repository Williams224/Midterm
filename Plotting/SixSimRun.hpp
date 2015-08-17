#ifndef SIXSIMRUN_HPP
#define SIXSIMRUN_HPP
#include"ComparableObject.hpp"

class SixSimRun : public ComparableObject{
public:
  SixSimRun(std::string _DataFileName, std::string _Name);
  ~SixSimRun();
};






#endif
