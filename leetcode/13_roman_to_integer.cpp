class Solution {

public:

    int romanToInt(string s) {

        int index = 0;

        int result = 0;

        while (index < s.size()) {

            switch (s[index]) {

                case 'M':

                result += 1000;

                ++index;

                break;

                case 'D':

                result += 500;

                ++index;

                break;

                case 'C':

                if (s[index + 1] == 'M') {

                    result += 900;

                    index += 2;

                    break;

                }

                if (s[index + 1] == 'D') {

                    result += 400;

                    index += 2;

                    break;

                }

                result += 100;

                ++index;

                break;

                

                case 'L':

                result += 50;

                ++index;

                break;

                case 'X':

                if (s[index + 1] == 'C') {

                    result += 90;

                    index += 2;

                    break;

                }

                if (s[index + 1] == 'L') {

                    result += 40;

                    index += 2;

                    break;

                }

                result += 10;

                ++index;

                break;

                

                case 'V':

                result += 5;

                ++index;

                break;

                case 'I':

                if (s[index + 1] == 'X') {

                    result += 9;

                    index += 2;

                    break;

                }

                if (s[index + 1] == 'V') {

                    result += 4;

                    index += 2;

                    break;

                }

                result += 1;

                ++index;

                break;

            }

        }

        return result;

    }

};
