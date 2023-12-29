class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (int i=0; i<operations.size(); i++){
            if (operations[i] == "--X") {
                result = result - 1;
            } else if (operations[i] == "X--") {
                result = result - 1;
            } else if (operations[i] == "++X") {
                result = result + 1;
            } else {
                result = result + 1;
            }
        }
        return result;
    }
};

// coming in a min

// result = 0
// operations = ["--X","X++","X++"] 
// operations.size() -> 3

// int =0; 0<3; 0++
// operations[0] -> "--X"
// operations[i] == "--X" -> true
// result = result - 1;
// result = -1

// int = 1; 1<3; 1++
// operations[1] -> "X++"
// operations[i] == "--X" -> false

// int = 2; 2<3; 2++
// operations[2] -> "X++"
// operations[i] == "--X" -> false

// int =3; 3<3, exit loop

// return result, result -> -1