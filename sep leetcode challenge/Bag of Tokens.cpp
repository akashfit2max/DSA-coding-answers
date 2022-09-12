class Solution {
public:
    // Time Complexity: O(NlogN) (O(NlogN) for sorting & O(N) for two pointers.)
    // Space Complexity: O(logN)
    // where N is the number of tokens
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // play the i-th token face up -> loose token[i] power -> choose least one
        // play the i-th token face down -> gain token[i] power -> choose the largest one
        // hence, first sort the tokens
        sort(tokens.begin(),tokens.end());
        // l pointer - least power
        // r pointer - most power
        int curr_score=0, max_score=0;
        int l=0, r=tokens.size()-1;
        while(l<=r)
        {
            // there can be 3 cases
            if(tokens[l] <= power)
            {
                // if the token[i] power is less than current power face up and loose token[l] power
                power -= tokens[l];
                // add one score
                curr_score += 1;
                // curr score can become max_score 
                max_score = max(max_score,curr_score);
                // move to next token
                l++;
            }
            else if (curr_score >= 1) {
                // if the curr score is atleast one face down and gain token[r] power
                power += tokens[r];
                // loose 1 point
                curr_score -= 1;
                // move to next token
                r--;
                
            }
            else
            {
                break;
            }
        }
        return max_score;
    }
};