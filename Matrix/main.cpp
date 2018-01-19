//
//  main.cpp
//  Matrix
//
//  Created by Leonard Thiele on 15.12.16.
//

#include <iostream>
#include "Matrix.cpp"

using namespace std;

int main(int argc, const char * argv[]) {

// *** INITIALIZATION ***
    
    int depth[3] = {3, 3, 3};
    
    Matrix<int, 3> testArray(depth);
    
    testArray.initialize(0);
    
// *** END INITIALIZATION ***
    
    int index[] = {0, 0, 0};
    
    testArray.setValue(index, 42);
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                
                int pos[3] = {i, j, k};
                testArray.setValue(pos, ((i * 100) + (j * 10) + k));
            }
        }
    }
    testArray.print(false);
    
    return 0;
}
