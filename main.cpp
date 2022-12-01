#include <cstdio>
#include <cmath>
#include <iostream>


class vector{
public:
    float x;
    float y;
    vector(){
        this->x = 0.f;
        this->y = 0.f;
    }
    vector(const float &x, const float &y){
        this->x = x;
        this->y = y;
    }
    vector(const vector &vector){
        this->x = vector.x;
        this->y = vector.y;
    }
    ~vector(){}


    void set(const float &x, const float &y){
        this->x = x;
        this->y = y;
    }
    void set(const vector &vector){
        this->x = vector.x;
        this->y = vector.y;
    }
    const float length() const{
        return sqrtf(
            powf(this->x,2.f) 
            + 
            powf(this->y,2.f)
        );
    }
};


class AimTarget2D{
private:
    static const float vec_to_rad(const vector &vector){
        if(vector.x == 0 && vector.y == 0) return 0;
        // to normalize vector and send to trigometric function value from 0 <= x <= 1
        float normalized_x = vector.x / vector.length();
        if      (vector.x<=0 && vector.y>0) return acosf(normalized_x) - M_PIf * 0.5f;
        else if (vector.x<0 && vector.y<=0) return asinf(normalized_x) + M_PIf * 1.0f;
        else if (vector.x>=0 && vector.y<0) return asinf(normalized_x) + M_PIf * 1.0f;
        else if (vector.x>0 && vector.y>=0) return acosf(normalized_x) + M_PIf * 1.5f;
        else return 0;
    }
    static const vector rad_to_vec(const float& radian){
        // return normalized vector
        return vector(sinf(-radian),cosf(radian));
    }
public:
    AimTarget2D(){}
    ~AimTarget2D(){}

    // degree and radian
    static const float to_degree(const float& radian){return radian / M_PIf * 180;}
    static const float to_radian(const float& degree){return degree / 180 * M_PIf;}
    
    // radian and vector
    static const float to_radian(const vector &vector){return AimTarget2D::vec_to_rad(vector);}
    static const vector to_vector(const float &radian){return AimTarget2D::rad_to_vec(radian);}

};


int main(){

    // #include "conio.h-master/conio.h"
    
    // to test it in practive 
    // to use it you also need conio.h 
    // but in linux i need to get it from git repository "conio.h-master"
    
    // float x=0.f,y=0.f;
    // while(true){
    //     char c = getch();
    //     switch (c){
    //         // 27
    //         // 91
    //         // c
    //     case 65: // ↑
    //         y+=1.f;
    //         break;
    //     case 66: // ↓
    //         y-=1.f;
    //         break;
    //     case 67: // →
    //         x+=1.f;
    //         break;
    //     case 68: // ←
    //         x-=1.f;
    //         break;
    //     default:
    //         break;
    //     }
    //     system("clear");
    //     const float radian = AimTarget2D::to_radian(vector(x,y));
    //     vector vector = AimTarget2D::to_vector(radian);
    //     printf("x:%.2f y:%.2f\n%.0f°\nx:%.2f y:%.2f\n",x,y,radian,vector.x,vector.y);
    //     for (int i=10; i>=-10; i--){
    //         for (int j=-10; j<=10; j++){
    //             if(j == (int)(x) && i == (int)(y)) printf("o");
    //             else if(j == 0 && i == 0) printf("+");
    //             else if(i == 0) printf("-");
    //             else if(j == 0) printf("|");
    //             else printf(" ");
    //         }
    //         printf("\n");
    //     }
    // }
}