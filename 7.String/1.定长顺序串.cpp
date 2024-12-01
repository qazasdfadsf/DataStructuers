#include "init.h"
//静态数组存储
#define MAXLEN 255//定长
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;
bool SubString(SString &Sub,SString S,int pos,int len)
{//求子串
    if(pos+len-1>S.length)
    {//子串范围越界
        return false;
    }
    for(int i=pos;i<pos+len;i++)
    {
        Sub.ch[i-pos+1]=S.ch[i];
    }
    Sub.length=len;
    return true;
}
bool StrCompare(SString S,SString T)
{//比较操作
    for(int i=1;i<=S.length&&i<=T.length;i++)
    {
        if (S.ch[i]!=T.ch[i])
        {
            return S.ch[i]-T.ch[i];
        }
    }
    //扫描过的所有字符都相等。则长度长的串更大
    return S.length-T.length;
}
int StrLength(SString S)
{//串长度
    return S.length;
}
//===============================================
int index(SString S,SString T)
{//定位操作    朴素模式匹配算法
    int i=1;
    int n=StrLength(S);//S.length
    int m=StrLength(T);//T.length
    SString sub;
    while (i<=n-m+1)
    {
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0)    ++i;
        else    return i;
        return 0;
    }
}
int Index(SString S,SString T)
{//模式匹配 朴素模式匹配算法O(nm)
    int i=1;//主串S
    int j=1;//模式串T
    while(i<=S.length && j<=T.length)
    {
        if(S.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i=i-j+2;
            j=1;
        }
        if(j>T.length)
            return i-T.length;
        else
            return 0;
    }
}
void get_next(SString T,int next[])
{
    int i=1,j=0;
    next[1]=0;
    while (i<T.length)
    {
        if (j==0||T.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}
int Index_KMP(SString S,SString T,int next[])
{//KMP算法   O(n)    最坏O(n+m)
 //求next数组O(m)    
    int i=1;
    int j=1;
    while (i<=S.length&& j<=T.length)
    {
        if(j==0||S.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j=next[j];
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}
void get_nextval(SString T,int nextval[])
{//KMP优化后
    int i=1,j=0;
    nextval[1]=0;
    while (i<T.length)
    {
        if(j==0||T.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
            if (T.ch[i]!=T.ch[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[i];
        }
        else
            j=nextval[j];
    }
}
int main(){
    SString S;  
    S.ch[1]='w';
    // S.ch[7]="wangdao";
    // S.length=7;
    return 0;
}