// TUTOR : Zengovari Balazs

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

bool isExist(const std::string fileName);
std::vector<std::vector<std::string>> readFile(const std::string datab);
std::string getPropsFile(const std::string path);
int getPoints(const std::string path);

int main(int argc, char** argv){

  std::vector<std::vector<std::string>> database =  readFile(argv[1]);

  std::string kapcsolo = argv[2];

  std::map<std::string, int> pontok;
  std::multimap<int, std::string> forditva;
  std::multimap<std::string, std::string> hallgatoFeladat;
  bool in = false;

  int i = 0;

  for(i = 0; i < database.size(); i++){
    pontok[database[i][0]] = 0;
    for(auto const& feladat: hallgatoFeladat){
      if(feladat.first == database[i][0] && feladat.second == database[i][1])
        in = true;
    }
    if(!in)
    hallgatoFeladat.insert(std::pair<std::string, std::string>(database[i][0], database[i][1]));

    in = false;
  }

  for(auto const& feladat: hallgatoFeladat){
    pontok[feladat.first] += getPoints(feladat.second);
  }

  for(auto const& value: pontok){
    forditva.insert(std::pair<int, std::string>(value.second, value.first));
  }

  i = 0;
  int top = 20;

  if(kapcsolo == "--pont"){
    if(argv[3]){
      top = std::stoi(argv[3]);
    }

    for(auto value = forditva.rbegin(); value != forditva.rend(); ++value){
      std::cout << i + 1 << ": " << value->second << ": " << value->first << std::endl;
      if(i == top - 1)
        break;
      i++;
    }
  }
}

int getPoints(const std::string path) {
  if(!(path.find("Esport") != std::string::npos)){
    int pont = 0, i;
    char ch;
    std::string fileName = getPropsFile(path), temp, temp2;
    std::vector<std::string> vTemp;
    if(isExist(fileName)){
      std::ifstream data(fileName);
      while(data.get(ch)){
        if(ch == '\n'){
          std::stringstream ss(temp);
          while(getline(ss, temp2, ' ')){
            vTemp.push_back(temp2);
          }
          i = vTemp.size() - 1;
          while(vTemp[i] == "" || vTemp[i] == "	"){
            i--;
          }

          pont += std::stoi(vTemp[i]);

          vTemp.clear();
          temp = "";
        }
         else {
          if(ch != '\"')
            temp += ch;
        }
      }
    }
    return pont;
  }
  return 0;
}

std::string getPropsFile(const std::string path){
  std::string props, temp;
  std::stringstream ss(path);
  std::vector<std::string> v;
  while(getline(ss, temp, '/')){
    v.push_back(temp);
  }
  props = path + "/" + v[v.size() - 1] + ".props";

  return props;
}

std::vector<std::vector<std::string>> readFile(const std::string datab){
  std::ifstream data(datab);
  std::string temp;
  std::vector<std::vector<std::string>> database;
  std::vector<std::string> vTemp, vTemp2;
  while(std::getline(data, temp)){
  	  	boost::split(vTemp2, temp, boost::is_any_of(","));
  	  	for(auto value: vTemp2){
  	  		vTemp.push_back(value.substr(1, value.length() - 2));
  	  	}

       	database.push_back(vTemp);
       	vTemp.clear();
     }

  	return database;
 }


bool isExist(const std::string fileName){
  std::ifstream infile(fileName);
  return infile.good();
}
