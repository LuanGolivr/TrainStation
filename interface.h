#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class TrainMap {

public:
    TrainMap ();
    unordered_map<string, int> vertices;
    int edges[14][14];
};


