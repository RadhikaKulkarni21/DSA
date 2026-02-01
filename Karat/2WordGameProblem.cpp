/*
The "Scrabble" or Word Game Problem 
This category tests string manipulation and frequency counting.
*/

#include "R:\C++\Project1\lcHeader.h"

/*Part 1: Given a list of words and a string of available characters, 
find the first word in the list that can be fully formed using those characters.*/


string firstFormableWord(vector<string> words, string chars){
    vector<int> freq (26,0);

    //'a'	0	freq[0] = 1
    //'p'	15	freq[15] = 1
    for(char c: chars){
        freq[c - 'a']++;
    }
    //this stores all the frequency we have of all the characters

    for(string word: words){
        vector<int> needed(26,0);
        //Now we check if the chars are in the words
        bool ok = true;
        for(char c : word){
            needed[c - 'a'];
            if(needed[c - 'a'] > freq[c - 'a']){
                //if we pass the number of chars
                //simply skip that one character and move to next one
                ok = false;
                break;
            }
        }
        if(ok) return word;
    }
    return "";
}


/*
Part 2: Given a grid of letters and a word, 
find if the word exists in the grid (usually only moving right or down).
*/

bool dfs(vector<vector<char>> grid, int row, int col, int ind, string word){
    if(ind == word.size()) return true;

    //out of bounds
    int m = grid.size(), n = grid[0].size();
    if(row >= m || col >= n || grid[row][col] != word[ind]) return false;

    return (dfs(grid, row, col + 1,ind + 1, word) || dfs(grid, row + 1, col,ind + 1, word));
}

bool existsInGrid(vector<vector<char>>& grid, string word){
    int m = grid.size(), n = grid[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(dfs(grid, i, j, 0, word)) return true;
        }
    }
    return false;
}

/*
Part 3: Similar to Part 2, but you must find multiple words,
and each letter in the grid can only be used once across all words
*/
bool dfsWord(vector<vector<char>>& grid, vector<vector<bool>>& used,
             int r, int c, string& word, int idx){
    if(idx = word.size()) return true;

    int m = grid.size(), n = grid[0].size();

    if(r < 0 || c < 0 || r >= m || c >= n) return false;
    if(used[r][c] || grid[r][c] != word[idx]) return false;
    
    used[r][c] = true;
    //ultimately trying to find true, finding a valid word
    bool found = dfsWord(grid, used, r + 1, c, word, idx) ||
    dfsWord(grid, used, r - 1, c, word, idx) ||
    dfsWord(grid, used, r, c + 1, word, idx) ||
    dfsWord(grid, used, r, c - 1, word, idx);
    
    //invalid cell for current word, move to another word and set this false
    if(!found) used[r][c] = false;
    return found;
}

bool canFormAllWords(vector<vector<char>>& grid, vector<string>& words, int wordIdx,
                     vector<vector<bool>>& used){
    if(wordIdx == words.size()) return true;

    int m = grid.size(), n = grid[0].size();
    
    string& word = words[wordIdx];

    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if(dfsWord(grid, used, i, j, word, 0)){
                if(canFormAllWords(grid, words, wordIdx + 1, used)){
                    return true;
                }
            // backtrack whole word
            //This loop resets the entire used grid to false,
            //undoing a failed word placement so other possibilities can be tried.
                for(auto& row: used){
                    fill(row.begin(), row.end(), false);
                }
            }
        }
    }
    return false;
}

