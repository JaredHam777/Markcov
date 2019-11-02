//
// Created by JaredHam777 on 4/9/2019.
//

#ifndef UNTITLED10_WORD_MODEL_H
#define UNTITLED10_WORD_MODEL_H

#include "model.h"
#include <map>
#include <iterator>
#include <vector>

using namespace std;

class word_model : public markov_model {
public:

    void getWords();
    void generateMap();

    // give the model the example text and the model order; the model
    // should do any preprocessing in this call
    virtual void initialize(string text, int order) {
        // copy first order characters to back to simulate wrap-around
        _data = text + text.substr(0, order);
        _order = order;

    }

    // produce a text in the style of the example
    virtual string generate(int size);

protected:
    string _data;
    vector<string> words;
    int _order;
    std::map<vector<string>, vector<string>> wordMap;

};

#endif //UNTITLED10_WORD_MODEL_H
