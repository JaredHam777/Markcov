//
// Created by JaredHam777 on 4/9/2019.
//

#include <cstdlib>
#include <vector>
#include "map_model.h"
#include <iostream>

using namespace std;

void map_model::generateMap()
{

  for(int i=0; i<_data.size(); i++)
  {

      string gram="";
      for(int j=0; j<_order; j++)
      {
          gram += _data[(i+j)%_data.size()];
      }
      if(letterMap.count(gram)>0)
      {
          letterMap[gram].push_back(_data[(i+_order)%_data.size()]);
      } else {
          letterMap.insert(pair<string, vector<char>>(gram, {_data[(i+_order)%_data.size()]}));
      }
  }


}


string map_model::generate(int sz) {
    generateMap();

    int start = rand() % (_data.length() - _order);
    string seed = _data.substr(start, _order);

    string answer="";



    for(int i=0; i<sz; i++)
    {
        char c = letterMap[seed][rand()%letterMap[seed].size()];
        answer += c;
        seed = seed.substr(1)+c;

    }
    return answer;

}

