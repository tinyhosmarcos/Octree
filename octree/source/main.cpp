#include <octree.h>
#include <tools.h>
using namespace std;


const size_t capacity = 5;
char sample_path[] = "../../files/sample.obj";


int main(int argc, char* args[]){
  char* obj_path = (argc == 2 ? args[1] : sample_path);
  
  pair<Point<float>, Point<float> > bounds = tools::GetLimit<float>(obj_path);
  Octree<float,capacity> tree(bounds.first, bounds.second);
  
  int pointIn = tools::OrderPoints<float, capacity>(tree, INSERT, obj_path);
  cout << pointIn << " inserted points" << endl;
  
  int pointOut = tools::OrderPoints<float, capacity>(tree, ERASE, obj_path);
  cout << pointOut << " deleted points" << endl;
}
