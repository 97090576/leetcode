//

class Solution {
public:
    int lengthOfLastWord(string s) {
        string str;
        int i=s.size();
        bool flag=true; //true biaoshi zai zhao kongge
        int res=0;
        while(--i>=0){
            if(flag&&(s[i]==' ')) continue;
            if(flag&&(s[i]!=' ')) {flag=false;++res;}
            else if(!flag&&(s[i]!=' ')) ++res;
            else if(!flag&&(s[i]==' '))  break;
        }
        return res;
    }
};

//实际上2次遍历就行，首先找完所有空格，然后走完所有非空格,不需要用到flag
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int res=0;
        //guolv houmian suoyou kongge
        while(--n>=0&&s[n]==' '){
        }
        if(n<0) return 0;
        //zuihouyigedanci
        while(n>=0&&s[n--]!=' '){
            ++res;
        }
        return res;
    }
};
