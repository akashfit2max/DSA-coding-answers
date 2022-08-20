class Solution {
public:
    bool compare(vector<int> &selected, string currString){
        // checking if currentString contains duplicates or not
        vector<int> selfCheck(26,0);
        for(int i=0; i<currString.size();i++){
            
            if(selfCheck[currString[i]-'a'] == 1) return false;
            
            selfCheck[currString[i]-'a'] = 1;
            
        }
        
        // after the above loop is over and program does not return false,
        // means currString does not contain any duplicates.
        
        // not its time to check if the characters present it the currString,
        // we have picked any character (present it the currString) in the past.
        
        // vector<int> selected, is used for character we have picked up in the past.
        for(int i=0; i<currString.size(); i++){
            // if character is already picked int the past, return false
            if(selected[currString[i]-'a']==1)return false;
        }
        // return true, because the currStrinh contains unique charactes
        // that we had not picked up in the past.
        // and currString itself conatins unique characters
        return true;
    }
    
    int help(int i, vector<string> &arr, vector<int> &selected, int length){
        //base case
        if(i==arr.size()){
            return length;
        }
        
        
        
        string currString = arr[i];
        // if ( compare(selected, currString) ) is false, means there is an overlap,
        // may be, overlap in the currString and the past(string we had picj=ked up in past)
        // or currString itself contains duplicates.
        
        // So we only have to skip this current string.
        if(compare(selected, currString)==false){
            return help(i+1, arr, selected, length);
        }
        else{
            // if there is no overlap, we have two choices
            // first is to pick this currString, second is to not pick this currString.
            // store both the answers and return maximum among both of them.
            
            //pick
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 1;
            }
            length+=currString.size();
            int op1 = help(i+1, arr, selected, length);
            
            // not pick
            for(int j=0;j<currString.size();j++){
                selected[currString[j]-'a'] = 0;
            }
            length-=currString.size();
            int op2 = help(i+1, arr, selected, length);
            
            return max(op1, op2);
            
        }
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> selected(26, 0);
        return help(0,arr,selected,0);
        
        
    }
};
