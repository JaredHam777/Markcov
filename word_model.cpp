//
// Created by JaredHam777 on 4/9/2019.
//

#include "word_model.h"
#include <iostream>

void word_model::getWords() {

    string word="";
    for(int i=0; i<_data.size(); i++)
    {
        char c = _data[i];
        if(c == ' ' && !word.empty()){
            words.push_back(word);
            word="";
        } else  {
            word+=c;
        }
    }
    if(!word.empty()){words.push_back(word);}
}



void word_model::generateMap()
{
    getWords();
    for(int i=0; i<words.size(); i++)
    {
        vector<string> gram={};
        for(int j=0; j<_order; j++)
        {
            gram.push_back(words[(i+j)%words.size()]);
        }
        if(wordMap.count(gram)>0)
        {
            wordMap[gram].push_back(words[(i+_order)%words.size()]);
        } else {
            wordMap.insert(pair<vector<string>, vector<string>>(gram, {words[(i+_order)%words.size()]}));
        }
    }


}


string word_model::generate(int sz) {
    getWords();
    generateMap();

    int start = rand() % (words.size() - _order);
    vector<string> seed;
    for(int i=0; i<_order; i++)
    {
        seed.push_back(words[(start+i)%words.size()]);
    }


    string answer="";

    //cout<<"initial seed: "<<seed<<endl;

    for(int i=0; i<sz; i++)
    {
        int size = wordMap[seed].size();
        string str = wordMap[seed][rand()%size];
        answer += str + ' ';
       // seed = seed.substr(1)+c;

        vector<string> temp;

        for(int j=0; j<seed.size()-1; j++)
        {
            temp.push_back(seed[j+1]);
        }
        temp.push_back(str);
        seed = temp;

        //cout<<"seed "<<i<<": "<<seed<<endl;
    }
    return answer;

}