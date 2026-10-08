class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();

        for (int i = 0; i < n; ) {
            int j = i;

            // Find the end of the current word
            while (j < n && title[j] != ' ') {
                j++;
            }

            int len = j - i;

            // Convert the word to lowercase
            for (int k = i; k < j; k++) {
                title[k] = tolower(title[k]);
            }

            // If length >= 3, capitalize first letter
            if (len >= 3) {
                title[i] = toupper(title[i]);
            }

            // Move to next word
            i = j + 1;
        }

        return title;
    }
};