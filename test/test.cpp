#include <vector>
#include <map>
#include <cstdlib>
#include <iostream>

using namespace std;

void print(vector<int>& t)
{
    for(int i : t)
      std::cout << i << std::endl;
}

int main(int argc, char **argv)
{
    vector<int> t = { 0, 1, 2};
    print(t);
    return 1;
}
