class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int flag = 0;
        string s = "";
        while (i > -1 && j > -1) { cout << flag <<endl;
            int sum = a[i] - '0' + b[j] - '0' + flag;
            flag = sum > 1;
            if (sum % 2 == 1) {
                s = "1" + s;
            } else {
                s = "0" + s;
            }
            --i;
            --j;
        }
        while(i > -1) {
            int sum = a[i] - '0' + flag;
            flag = sum > 1;
            if (sum % 2 == 1) {
                s = "1" + s;
            } else {
                s = "0" + s;
            }
            --i;
        }
        while (j > -1) {
            int sum = b[j] - '0' + flag;
            flag = sum > 1;
            if (sum % 2 == 1) {
                s = "1" + s;
            } else {
                s = "0" + s;
            }
            --j;
        }
        if (flag)
            s = "1" + s; 
        return s;
    }
};