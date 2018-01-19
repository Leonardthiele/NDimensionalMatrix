## Class structure which provides a projection from a N-Dimensional Matrix on a One-Dimensional Array.

### Projection Example: (Dimension: 3; Depth: {3,3,3};)

Three layers of the cube:
```
|000|100|200|   |001|101|201|   |002|102|202|
|010|110|210|   |011|111|211|   |012|112|212|
|020|120|220|   |021|121|221|   |022|122|222|
```
Translate to 
```
[000,001,002,010,011,012,020,021,022,100,101,...,222]
```
Values will be read or write trough the
given methods get() and set().
They require an integer array with exactly the
amount of values as the dimension. (eg: A = {0,0,0})

The values from the position-array A
will be transformed with:
```
    d-1
 i = ∑ Ai*dp^(d-(i+1))
    i=0
 ```

*Ai:    Position-array at i; dp:    Dimension depth; d:     Dimension*

#### Example in main.cpp
Initializes and fills the 3x3x3 matrix. The print() method prints the final array.
