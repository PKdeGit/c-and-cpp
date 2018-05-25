#include<iostream>
using namespace std;
#define MAX 1000000
int puzzle[3][3]={7,2,4,5,0,6,8,3,1};
typedef int position;
typedef int choice;
//choice{Up,Left,Right,Down};
int change[][2]={
-1,0,
0,-1,
0,1,
1,0
};
int hn[4]={};
unsigned int result[MAX];
int _abs(int a){
    return a>0?a:-a;
}

void show(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            cout<<puzzle[i][j]<<' ';
        cout<<endl;
    }
}

int GetHn(position x,position y,choice next_step){
    position xt,yt;
    int sum=0;
    int i,j;
    xt=x+change[next_step][0];
    yt=y+change[next_step][1];
    if(xt<0||xt>2||yt<0||yt>2) return 100;//直接去除边界外情况
    puzzle[x][y]=puzzle[xt][yt];
    puzzle[xt][yt]=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(puzzle[i][j]==0) continue;
            switch (puzzle[i][j]){
            case 1:
                sum+=_abs(i-0)+_abs(j-1);break;
            case 2:
                sum+=_abs(i-0)+_abs(j-2);break;
            case 3:
                sum+=_abs(i-1)+_abs(j-0);break;
            case 4:
                sum+=_abs(i-1)+_abs(j-1);break;
            case 5:
                sum+=_abs(i-1)+_abs(j-2);break;
            case 6:
                sum+=_abs(i-2)+_abs(j-0);break;
            case 7:
                sum+=_abs(i-2)+_abs(j-1);break;
            case 8:
                sum+=_abs(i-2)+_abs(j-2);break;
            }
        }
    }
    puzzle[xt][yt]=puzzle[x][y];
    puzzle[x][y]=0;
    return sum;
}
int main(){
    position x=1,y=1;
    int i,mini,t,n=0;
    choice next_step,pre_step=4;
    while(true){
        for(next_step=0;next_step<4;next_step++){
            hn[next_step]=GetHn(x,y,next_step);
        }
        for(i=0,mini=1000,t=0;i<4;i++){
            cout<<hn[i]<<' ';
            if(hn[i]<=mini&&i+pre_step!=3){//防止回到上一步
                mini=hn[i];
                t=i;
            }
        }
        cout<<endl;
        result[n++]=t;
        pre_step=t;
        cout<<t<<endl;
        //show();
        puzzle[x][y]=puzzle[x+change[t][0]][y+change[t][1]];
        x+=change[t][0];
        y+=change[t][1];
        puzzle[x][y]=0;
        show();cout<<endl;
        if(mini==0) break;
        //if(n==10) break;
    }
    //for(int i=0;i<n;i++)
      //  cout<<result[i]<<endl;
    return 0;
}
