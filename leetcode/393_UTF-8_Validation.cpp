class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nBytes = 0;

        for (int i = 0, n = data.size(); i < n; ++i) {
            if (nBytes) {
                if (!myValidateByte(myIntToChar(data[i]))) return false;
            } else {
                nBytes = myGetNBytes(myIntToChar(data[i]));
                if (nBytes == 0) return false;
            }
            --nBytes;
        }

        return nBytes == 0;
    }

private:
    char myIntToChar(int i) {
        return static_cast<char>(i);
    }

    int myGetNBytes(char c) {
        if ((c & 0x80) == 0x00) return 1;
        if ((c & 0xE0) == 0xC0) return 2;
        if ((c & 0xF0) == 0xE0) return 3;
        if ((c & 0xF8) == 0xF0) return 4;
        return 0; // invalid length
    }

    bool myValidateByte(char c) {
        return (c & 0xC0) == 0x80;
    }
};
