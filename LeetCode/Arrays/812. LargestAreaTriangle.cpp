// O(N^3) time (because the question allowed xD) and constant space

double areaCalculate(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double a = x1*(y2-y3);
    double b = x2*(y3-y1);
    double c = x3*(y1-y2);
    double area = abs((a+b+c)/2);
    return area;
}

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double answer = DBL_MIN;
        
        for(int i = 0; i < points.size()-2; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < points.size()-1; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                for(int k = j+1; k < points.size(); k++)
                {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    
                    double temp = areaCalculate(x1, y1, x2, y2, x3, y3); 
                    if(temp > answer)
                        answer = temp;
                }
            }
        }
        return answer;
    }
};