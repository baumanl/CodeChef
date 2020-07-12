 #include <cstdio>
using namespace std;

//code borrowed from https://www.codechef.com/viewsolution/19239679
 
int board[9],q[178000]={123456789},powers[9]={100000000,10000000,1000000,100000,10000,1000,100,10,1};
	//Q: why 178000? how did he determine this number?
	//Q: what does the powers array do?

int posn,fromposn,front=-1,back=1;

char found[98765435]={0};
	//why 98765435? smallest is 12345678, largest is 98765432.
	//if a grid with ordering 435678129 is found -> found[43567812] = 1;
	//holds 1 + # of steps required to get to that grid.

bool prime[18]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1};
	//if i is prime then prime[i] == 1
 

//takes 2 integers which are indexes into a board. Subtracts the values stored at those indeces
//diffs smallest value is 1 (e.g. swapping 1 and 2) and the largest is 7 (swappping 2 and 9)
void moveit(int p1,int p2){
  int diff=board[p2]-board[p1];
  posn=fromposn+diff*powers[p1]-diff*powers[p2];
  int posndiv10=posn/10;
  if(!found[posndiv10]){
    found[posndiv10]=found[fromposn/10]+1;
    q[back++]=posn;
  }
}
 
int main(){
  int t,i,d;
 
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  found[12345678]=1;
  while(++front<back){
    for(posn=fromposn=q[front],i=8;i>=0;i--){
      board[i]=posn%10;
      posn/=10;
    }
    if(prime[board[0]+board[1]]) moveit(0,1);
    if(prime[board[0]+board[3]]) moveit(0,3);
    if(prime[board[1]+board[2]]) moveit(1,2);
    if(prime[board[1]+board[4]]) moveit(1,4);
    if(prime[board[2]+board[5]]) moveit(2,5);
    if(prime[board[3]+board[4]]) moveit(3,4);
    if(prime[board[3]+board[6]]) moveit(3,6);
    if(prime[board[4]+board[5]]) moveit(4,5);
    if(prime[board[4]+board[7]]) moveit(4,7);
    if(prime[board[5]+board[8]]) moveit(5,8);
    if(prime[board[6]+board[7]]) moveit(6,7);
    if(prime[board[7]+board[8]]) moveit(7,8);
  }
  scanf("%d",&t);
  while(t--){
    for(posn=i=0;i<8;i++){
      scanf("%d",&d);
      posn=posn*10+d;
    }
    scanf("%d",&d);
    if(found[posn]) printf("%d\n",found[posn]-1);
    else puts("-1");
  }
  return 0;
}   