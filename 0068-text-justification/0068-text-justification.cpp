class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> currWords; // Store the current line's words
        int currLen = 0; // Track the current length of words in currWords

        for (int i = 0; i < words.size(); i++) {
            // Check if adding the next word exceeds maxWidth
            if (currLen + currWords.size() + words[i].size() > maxWidth) {
                // Calculate the number of spaces needed
                int spaces = maxWidth - currLen;
                int numWords = currWords.size();
                
                // If there is more than one word, distribute spaces
                string line = "";
                if (numWords == 1) {
                    // If there's only one word, left-align it
                    line += currWords[0];
                    line += string(spaces, ' '); // Pad with spaces to the right
                } else {
                    // Calculate base spaces and extra spaces
                    int spaceBetweenWords = spaces / (numWords - 1);
                    int extraSpaces = spaces % (numWords - 1);

                    // Build the justified line
                    for (int j = 0; j < numWords; j++) {
                        line += currWords[j];
                        // Add spaces between words
                        if (j < numWords - 1) {
                            line += 
                            string(spaceBetweenWords + (j < extraSpaces ? 1 : 0), ' ');
                        }
                    }
                }
                ans.push_back(line); // Add the constructed line to the result
                currWords.clear(); // Clear current words for the next line
                currLen = 0; // Reset current length
            }

            // Add the current word to the current line
            currWords.push_back(words[i]);
            currLen += words[i].size();
        }

        // Handle the last line
        string lastLine = "";
        for (int i = 0; i < currWords.size(); i++) {
            lastLine += currWords[i];
            if (i != currWords.size() - 1) {
                lastLine += " "; // Add space between words in the last line
            }
        }
        // Pad the last line with spaces if needed
        while (lastLine.size() < maxWidth) {
            lastLine += " ";
        }
        ans.push_back(lastLine); // Add the last line to the result
        
        return ans;
    }
};
