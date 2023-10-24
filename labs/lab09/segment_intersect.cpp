#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x, y;
    Point(){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int direction(Point p, Point q, Point r){
    // pr × pq

    int prx = r.x - p.x;
    int pry = r.y - p.y;

    int pqx = q.x - p.x;
    int pqy = q.y - p.y;

    return (prx * pqy) - (pry * pqx);
}


int onSegment(Point p, Point q, Point r){
    if((r.x >= min(p.x,q.x) && r.x <= max(p.x,q.x)) && (r.y >= min(p.y,q.y) && r.y <= max(p.y,q.y))){
        return true;
    }
    return false;
}

bool segmentIntersect(Point p, Point q, Point r, Point s){
    // segment pq intersect with segment rs or not?
    int d1 = direction(p,q,r);
    int d2 = direction(p,q,s);
    int d3 = direction(r,s,p);
    int d4 = direction(r,s,q);

    if((d1 * d2) < 0 && (d3 * d4) < 0){
        return true;
    }
    if(d1 == 0 && onSegment(p,q,r)){
        return true;
    }
    if(d2 == 0 && onSegment(p,q,s)){
        return true;
    }
    if(d3 == 0 && onSegment(r,s,p)){
        return true;
    }
    if(d4 == 0 && onSegment(r,s,q)){
        return true;
    }
    return false;
}

int main(){
    Point p1(2,2);
    Point p2(8,3);
    Point p3(1,4);
    Point p4(6,5);

    // segment p1p2 intersect with segment p3p4 or not?
    if(segmentIntersect(p1,p2,p3,p4)){
        cout << "Intersect\n";
    }else{
        cout << "Not Intersect\n";
    }


    return 0;
}