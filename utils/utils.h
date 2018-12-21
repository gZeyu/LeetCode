#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

template <typename T>
vector<vector<T>> getMatrixfromJson(json &j)
{
    vector<vector<T>> matrix;
    for (json &array : j)
    {
        vector<T> vec;
        for (json &elem : array)
        {
            vec.push_back(elem);
        }
        matrix.push_back(vec);
    }
    return matrix;
};

template <typename T>
vector<T> getVectorfromJson(json &j)
{
    vector<T> vec;
    for (json &elem : j)
    {
        vec.push_back(elem);
    }
    return vec;
};

template <typename T>
void prettyPrintMatrix(vector<vector<T>> &matrix)
{
    string msg;
    msg += "[\n";
    for (auto iter = matrix.cbegin(); iter != matrix.cend(); ++iter)
    {
        json j(*iter);
        msg += "    " + j.dump() + ",\n";
    }
    msg.erase(msg.end() - 2);
    msg += "]";
    cout << msg << endl;
}

template <typename T>
void prettyPrintVector(vector<T> &vec)
{
    json j(vec);
    cout << j.dump() << endl;
}

#endif // UTILS_H