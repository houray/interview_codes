class Solution {

public:

    string intToRoman(int num) {

        int d = num % 10;

        int a = (num / 1000) % 10;

        int b = (num / 100) % 10;

        int c = (num / 10) % 10;

        string result;

        for (int i = a; i > 0; --i) {

            result.append("M");

        }

        if (b % 5 == 4) {

            result.append("C");

            if (b > 5)

                result.append("M");

            else

                result.append("D");

        } else {

            if (b / 5)

                result.append("D");

            for (int i = b % 5; i > 0; --i) {

                result.append("C");

            }

        }

        if (c % 5 == 4) {

            result.append("X");

            if (c > 5)

                result.append("C");

            else

                result.append("L");

        } else {

            if (c / 5)

                result.append("L");

            for (int i = c % 5; i > 0; --i) {

                result.append("X");

            }

        }

        if (d % 5 == 4) {

            result.append("I");

            if (d > 5)

                result.append("X");

            else

                result.append("V");

        } else {

            if (d / 5)

                result.append("V");

            for (int i =d % 5; i > 0; --i) {

                result.append("I");

            }

        }

        return result;

    }

};
