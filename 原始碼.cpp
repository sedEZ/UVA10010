#include<iostream>

using namespace std;

int main(){
    int caseNum;
    cin>>caseNum;

    while(caseNum--){
        int row,col;

        cin>>row>>col;

        string grid[row];

        for(int i=0;i<row;i++){
            cin>>grid[i];

            for(int j=0;j<col;j++)
                if(grid[i][j]<='Z')
                    grid[i][j]+=('a'-'A');//turn to lower case
        }


        int wordNum;
        cin>>wordNum;
        string words[wordNum];

        for(int i=0;i<wordNum;i++){
            cin>>words[i];
            for(int j=0;j<words[i].length();j++){
                if(words[i][j]<='Z')
                    words[i][j]+=('a'-'A');
            }//turn to lower case
        }


        for(int i=0;i<wordNum;i++){


            //cout<<words[i];

            int ansR,ansC;//answer_row,answer_col


            for(int r=0;r<row;r++){
                bool brk = false;
                for(int c=0;c<col;c++){
                    bool m1=true,m2=true,m3=true,m4=true,m5=true,m6=true,m7=true,m8=true;
                    if(grid[r][c]==words[i][0]){
						for(int t1=0;t1<words[i].length();t1++){
                            if((c+t1)>col||words[i][t1]!=grid[r][c+t1]){
                                m1=false;
                                break;
                            }
                        }
                        for(int t2=0;t2<words[i].length();t2++){
                            if((c+t2)>col||(r+t2)>row||words[i][t2]!=grid[r+t2][c+t2]){
                                m2=false;
                                break;
                            }
                        }
                        for(int t3=0;t3<words[i].length();t3++){
                            if((r+t3)>row||words[i][t3]!=grid[r+t3][c]){
                                m3=false;
                                break;
                            }
                        }
                        for(int t4=0;t4<words[i].length();t4++){
                            if((r+t4)>row||(c-t4)<0||words[i][t4]!=grid[r+t4][c-t4]){
                                m4=false;
                                break;
                            }
                        }
                        for(int t5=0;t5<words[i].length();t5++){
                            if((c-t5)<0||words[i][t5]!=grid[r][c-t5]){
                                m5=false;
                                break;
                            }
                        }
                        for(int t6=0;t6<words[i].length();t6++){
                            if((r-t6)<0||(c-t6)<0||words[i][t6]!=grid[r-t6][c-t6]){
                                m6=false;
                                break;
                            }
                        }
                        for(int t7=0;t7<words[i].length();t7++){
                            if((r-t7)<0||words[i][t7]!=grid[r-t7][c]){
                                m7=false;
                                break;
                            }
                        }
                        for(int t8=0;t8<words[i].length();t8++){
                            if((r-t8)<0||(c+t8)>col||words[i][t8]!=grid[r-t8][c+t8]){
                                m8=false;
                                break;
                            }
                        }

                    }
                    else{m1=m2=m3=m4=m5=m6=m7=m8=false;}

                    if(m1||m2||m3||m4||m5||m6||m7||m8){
                        ansR = r;
                        ansC = c;
                        brk = true;
                        break;
                    }

                }
                if(brk)
                    break;

            }
            cout<<ansR+1<<" "<<ansC+1<<endl;

        }
        if(caseNum)
            cout<<endl;
    }


    return 0;
}

