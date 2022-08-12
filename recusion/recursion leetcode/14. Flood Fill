class Solution {
public:
    void flood (int x, int y, vector<vector<int>>&image, int oldColor, int newColor)
    {
        if(x<0 || y<0 || x==image.size() || y==image[0].size() || image[x][y] != oldColor)
        {
            return;
        }
        
        image[x][y] = newColor;
        flood(x-1,y,image,oldColor,newColor);
        flood(x+1,y,image,oldColor, newColor);
        flood(x,y-1,image,oldColor,newColor);
        flood(x,y+1,image,oldColor,newColor);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image;
        flood(sr,sc,image,oldColor,color);
        return image;
    }
};
