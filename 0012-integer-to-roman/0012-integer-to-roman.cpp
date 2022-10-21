class Solution {
public:
    string intToRoman(int num) {
        if(num == 0) return "";
        string fin = "";
        if(num >= 1000){
            num -= 1000;
            fin += "M";
        }
        else if(num >= 900){
            num -= 900;
            fin += "CM";
        }
        else if(num >= 500){
            num -= 500;
            fin += "D";
        }
        else if(num >= 400){
            num -= 400;
            fin += "CD";
        }
        else if(num >= 100){
            num -= 100;
            fin += "C";
        }
        else if(num >= 90){
            num -= 90;
            fin += "XC";
        }
        else if(num >= 50){
            num -= 50;
            fin += "L";
        }
        else if(num >= 40){
            num -= 40;
            fin += "XL";
        }
        else if(num >= 10){
            num -= 10;
            fin += "X";
        }
        else if(num >= 9){
            num -= 9;
            fin += "IX";
        }
        else if(num >= 5){
            num -= 5;
            fin += "V";
        }
        else if(num >= 4){
            num -= 4;
            fin += "IV";
        }
        else if(num >= 1){
            num -= 1;
            fin += "I";
        }
        return fin + intToRoman(num);
    }
};