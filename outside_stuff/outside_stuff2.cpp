#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point{
    float x;
    float y;

    bool operator == (const Point &p)
    {
        if (x == p.x && y == p.y){
            return true;
        }
        return false;
    }
};

float distBetweenPoints(const Point& p1, const Point& p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

struct PointsDistance{
    PointsDistance(const Point& p1, const Point& p2){
        point1 = &p1;
        point2 = &p2;
        dist = distBetweenPoints(p1, p2);
    }
    const Point* point1;
    const Point* point2;
    float dist;
};

bool pointComparerX(const Point& p1, const Point& p2) { 
    return (p1.x < p2.x); 
}

bool pointComparerY(const Point& p1, const Point& p2) { 
    return (p1.y < p2.y); 
}

PointsDistance minPointDist(const PointsDistance& p1, const PointsDistance& p2) { 
    return (p1.dist < p2.dist) ? p1 : p2; 
}

PointsDistance findSmalDisPair(Point pointsXSort[], Point pointsYSort[], int sizeX, int sizeY){
    //Base case
    if (sizeX == 2){
        return PointsDistance(pointsXSort[0], pointsXSort[1]);
    }
    else if (sizeX == 3){ //this code would still work if size = 2 but above implementation is faster for size = 2
        PointsDistance curSmallest(pointsXSort[0], pointsXSort[1]);
        for (int i = 0; i < sizeX - 1; i++){
            for (int j = i + 1; j <= i + 7 && j < sizeX; j++){ //limit to next seven neighbors or size
                PointsDistance newDist(pointsXSort[i],pointsXSort[j]);
                curSmallest = minPointDist(curSmallest, newDist);
            }
        }
        return curSmallest;
    }

    //Split as 0 to middle-1 and middle to size - 1, recur
    int middle = sizeX/2;

    PointsDistance leftSmallest  = findSmalDisPair(pointsXSort         , pointsYSort, middle        , sizeY);
    PointsDistance rightSmallest = findSmalDisPair(pointsXSort + middle, pointsYSort, sizeX - middle, sizeY);
    
    PointsDistance smallest = minPointDist(leftSmallest, rightSmallest);

    //Find strip    
    int medianX = (pointsXSort[middle-1].x + pointsXSort[middle].x)/2;

    int lowestIndexInRange = middle - 1;
    for (int i = middle - 1; i > 0; i--){
        if (pointsXSort[i].x < medianX - smallest.dist){
            break;
        }
        lowestIndexInRange = i;
    }

    int highestIndexInRange = middle;
    for (int i = middle; i < sizeX; i++){
        if (pointsXSort[i].x > medianX + smallest.dist){
            break;
        }
        highestIndexInRange = i;
    }

    //Get from pointsXSort[lowestIndexInRange] to pointsXSort[highestIndexInRange] sorted by .y by referencing the already sorted array
    std::vector<Point> pointsYSortStrip;
    for (int i = 0; i < sizeY; i++){
        if(std::find(pointsXSort + lowestIndexInRange, pointsXSort + highestIndexInRange, pointsYSort[i]) == &pointsYSort[i]){
            pointsYSortStrip.push_back(pointsYSort[i]);
        }
    }

    //Check pairs in pointsYSortStrip
    for (int i = 0; i < pointsYSortStrip.size(); i++){

        for (int j = i +1; j <= i + 7 && j < pointsYSortStrip.size(); j++){ //limit to next seven neighbors or highest index
            PointsDistance newDist(pointsYSortStrip.at(i),pointsYSortStrip.at(j));
            smallest = minPointDist(smallest, newDist);
        }
    }
    return smallest;
}

int main(){
    std::vector<Point> pointsXsort = {
        {1,1},
        {45,8},
        {8,2},
        {3,4},
        {9,2},
        {5,7},
        {4,3},
        {1,2}
    };

    std::vector<Point> pointsYsort(pointsXsort);

    std::sort(pointsXsort.begin(), pointsXsort.end(), pointComparerX);
    std::sort(pointsYsort.begin(), pointsYsort.end(), pointComparerY);

    PointsDistance smallest = findSmalDisPair(&pointsXsort[0], &pointsYsort[0], pointsXsort.size(), pointsYsort.size());


    return 0;
}
