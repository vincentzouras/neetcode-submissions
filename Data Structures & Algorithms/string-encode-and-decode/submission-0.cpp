class Solution {
public:

    /*
    Put char count of string and a delimiter in case multiple digit char count

    ["Hello", "World"]
    "5#Hello5#World"

    ["##830f!##", "12345"]
    "9###830f!##5#12345"
    */

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for (string str : strs) {
            int length = str.size();
            encoded_string += to_string(length) + '#';
            for (char c : str) {
                encoded_string += c;
            }
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        int i = 0;

        while (i < s.size()) {
            string s_length = "";

            while (s[i] != '#') {
                s_length += s[i];
                i++;
            }
            i++; // skip delimiter

            string decoded_str = ""; 
            int stop_index = i + stoi(s_length);
            while (i < stop_index) {
                decoded_str += s[i];
                i++;
            }

            decoded_strings.push_back(decoded_str);
        }

        return decoded_strings;
    }
};
