//
//  Matrix.cpp
//  Matrix
//
//  Created by Leonard Thiele.
//

#include "Matrix.hpp"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

// Class structure which provides a projection from a N-Dimensional Matrix on a One-Dimensional Array.
//
// Projection Example: (Dimension: 3; Depth: {3,3,3};)
//
//         Layer 0         Layer 1         Layer 2          Array:
//
//       ___________     ___________     ___________        i:
//      |000|100|200|   |001|101|201|   |002|102|202|       0: |000|
//      |010|110|210|   |011|111|211|   |012|112|212|   =>  1: |001|
//      |020|120|220|   |021|121|221|   |022|122|222|       2: |002|
//                                                          3: |010|
//                                                          4: |011|
//                                                          5: |012|
//                                                          6: |020|
//                                                          7: |021|
//                                                          8: |022|
//                                                          9: |100|
//       Values will be read or write trough the            10:|101|
//       given methods get() and set().                     11:|102|
//       They require an integer array with exactly the     12:|110|
//       amount of values as the dimension.                 13:|111|
//       (eg: A = {0,0,0})                                  14:|112|
//                                                          15:|120|
//       The values from the position-array A               16:|121|
//       will be transformed with this equasion:            17:|122|
//                                                          18:|200|
//          d-1                                             19:|201|
//       i = ∑ Ai*dp^(d-(i+1))                              20:|202|
//          i=0                                             21:|210|
//                                                          22:|211|
//       Ai:    Position-array at i                         23:|212|
//       dp:    Dimension depth                             24:|220|
//       d:     Dimension                                   25:|221|
//                                                          26:|222|

template <typename T, unsigned int N>
class Matrix {
    
    T* nMatrix;
    int* depth;
    unsigned int size = 1;
    
public:
    
// The constructor initializes the main array.
// It requires a depth-array which has exactly N elements.
    
    Matrix(int depth[]){
        
        this->depth = &depth[0];

        for(int i = 0; i < N; i++){
            
            size *= depth[i];
        }
        
        nMatrix = new T[size];
    }
    
    ~Matrix(){ delete[] nMatrix; }
    
    
// The initialize-function will set every element from the
// main array to the given Value.
    
    void initialize(T initValue){

        for(int i = 0; i < size; i++){
            
            nMatrix[i] = initValue;
        }
    }
    
    
// The get-function returns a value to a given position-array.
    
    T getValue(int index[]){

        return nMatrix[translateIndex(index)];
    }
    
// The set-function sets a given position to a given value.
    
    void setValue(int index[], T value){
        
        nMatrix[translateIndex(index)] = value;
    }
    
// The translate-function will calculate the correct index to a given
// position-array.

    int translateIndex(int index[]){
        
        unsigned int pos = 0;
        for(int i = 0; i < N; i++){
            
            pos += (index[i] * pow(depth[i], N - (i + 1)));
        }
        return pos;
    }

// To print the whole array.
// Boolean blocks can be set to true, to format the output in blocks.
    
    void print(bool blocks){
        
        int count = 0;
        for(int i = 0; i < size; i++){

            if(nMatrix[count] < 10){
                cout << "00" << nMatrix[count] << " ";
                count++;
            } else if (nMatrix[count] < 100){
                cout << "0" << nMatrix[count] << " ";
                count++;
            } else {
                cout << nMatrix[count] << " ";
                count++;
            }
            
            if(blocks){
                
                if((((i + 1) % depth[0]) == 0)){
                    cout << "" << endl;
                }
            } else {
                
                cout << "" << endl;
            }
            
        }
    }

};
