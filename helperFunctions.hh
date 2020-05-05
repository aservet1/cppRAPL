#ifndef HELPER_FUNCTIONS_HH
#define HELPER_FUNCTIONS_HH

#include<iostream>

static std::vector<std::string>
split(std::string line, char delim){
  std::vector<std::string> result;
  while (line.length() != 0){
    std::string token;
    if (line.find(delim) == std::string::npos){
      token = line;
      line.erase(0, line.length());
    }
    else{
      token = line.substr(0, line.find(delim));
      line.erase(0, line.find(delim)+1);
    }
    result.push_back(token);
  }
  return result;
}

template <typename E>
void
printVector(std::vector<E> vec, std::ofstream& outfile){
  //std::ostream& out = std::cout;
  outfile.precision(15);
  auto it = vec.cbegin();
  for(; it != vec.cend(); it++){
    outfile << std::fixed << *it << " ";
  }
  outfile << std::endl;
}

template <typename E>
void
makeCopy(E *copyto, E *copyfrom, int size){
  for(int i = 0; i < size; i++){
    copyto[i] = copyfrom[i];
  }
  return;
}

#endif
