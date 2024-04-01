#include <fstream>
#include <string>
#include <vector>
using namespace std;

class reader {
  public:
    reader(string filename){
      this->filename = filename;
      txt2str(filename);
    }
    string getString(){ return lines; };
  private:
    string filename;
    string lines;
    void txt2str(string filename){
      ifstream file(filename);
      string line;
      while(getline(file, line)){
        this->lines += line;
      }
      file.close();
    }
};