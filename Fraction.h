#ifndef __FRACTION
#define __FRACTION

//分数类实现~~~0.8.5,实现于初中二年级，最初发表于2019.7.25
//fraction:分数
//numerator:分子
//denominator:分母
//输入分数时请以回车结尾
//输入部分如含有空格，则空格后面的部分会被忽略
//fraction可缩写为fac，计算机可以识别

#include <iostream>
#include <cmath>

#ifndef __fraction_h_
#define __fraction_h_

using namespace std;

namespace std
{

//分数类
class fraction
{
public:
    static long long MCF(long long a, long long b);

    friend ostream& operator<< (ostream& os,const fraction& the_fraction);
    friend istream& operator>> (istream& is,fraction& the_fraction);

    friend fraction operator+  (const fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator-  (const fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator*  (const fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator/  (const fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator+= (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator-= (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator*= (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator/= (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend fraction operator-  (const fraction& the_fraction);
    friend fraction operator++ (fraction& the_fraction);
    friend fraction operator++ (fraction& the_fraction,int);
    friend fraction operator-- (fraction& the_fraction);
    friend fraction operator-- (fraction& the_fraction,int);

    friend bool operator>  (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend bool operator<  (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend bool operator>= (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend bool operator<= (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend bool operator== (fraction& the_fraction_a,const fraction& the_fraction_b);
    friend bool operator!= (fraction& the_fraction_a,const fraction& the_fraction_b);

    fraction();
    fraction(long long the_numerator);
    fraction(long long the_numerator,long long the_denominator);
    fraction(fraction the_fraction_a,fraction the_fraction_b);

    double decimal();
    long long getnum();
    long long getden();
    void setnum(long long num);
    void setden(long long den);

private:
    long long numerator;
    long long denominator;

};



long long fraction::MCF(long long a, long long b)
{
    return a==0? b:MCF(b%a,a);
}



ostream& operator<< (ostream& os,const fraction& the_fraction)
{
    bool book=the_fraction.numerator>=0&&the_fraction.denominator>=0||the_fraction.numerator<0&&the_fraction.denominator<0;
    if(book==false)
        os<<"(-";
    if(the_fraction.denominator!=1)
        os<<abs(the_fraction.numerator)<<"/"<<abs(the_fraction.denominator);
    else
        os<<abs(the_fraction.numerator);
    if(book==false)
        os<<")";
    return os;
}

istream& operator>> (istream& is,fraction& the_fraction)
{
    char input[100];
    char ch;
    bool mid=false;
    bool is_pt=true;
    the_fraction.numerator=the_fraction.denominator=0;
    cin>>input;
    for(int i=0;;i++)
    {
        ch=input[i];
        if(ch=='\0')
            break;
        if(ch=='-')
        {
            is_pt=!is_pt;
            continue;
        }
        if(ch=='/')
        {
            mid=true;
            continue;
        }
        if(mid==false)
            the_fraction.numerator=the_fraction.numerator*10+(ch-'0');
        else
            the_fraction.denominator=the_fraction.denominator*10+(ch-'0');
    }
    if(mid==false)
        the_fraction.denominator=1;
    if(the_fraction.denominator==0)
    {
        cout<<"False,the denominator == 0!!!";
        return is;
    }
    long long mcf=fraction::MCF(the_fraction.numerator,the_fraction.denominator);
    the_fraction.numerator/=mcf;
    the_fraction.denominator/=mcf;
    if(!is_pt)
        the_fraction.numerator=-the_fraction.numerator;
    return is;
}



fraction operator+ (const fraction& the_fraction_a,const fraction& the_fraction_b)
{
    long long the_numerator=the_fraction_a.numerator*the_fraction_b.denominator+the_fraction_b.numerator*the_fraction_a.denominator;
    long long the_denominator=the_fraction_a.denominator*the_fraction_b.denominator;
    return fraction(the_numerator,the_denominator);
}

fraction operator- (const fraction& the_fraction_a,const fraction& the_fraction_b)
{
    long long the_numerator=the_fraction_a.numerator*the_fraction_b.denominator-the_fraction_b.numerator*the_fraction_a.denominator;
    long long the_denominator=the_fraction_a.denominator*the_fraction_b.denominator;
    return fraction(the_numerator,the_denominator);
}
fraction operator* (const fraction& the_fraction_a,const fraction& the_fraction_b)
{
    long long the_numerator=the_fraction_a.numerator*the_fraction_b.numerator;
    long long the_denominator=the_fraction_a.denominator*the_fraction_b.denominator;
    long long mcf=fraction::MCF(the_numerator,the_denominator);
    the_numerator/=mcf;
    the_denominator/=mcf;
    fraction the_fraction(the_numerator,the_denominator);
    return the_fraction;
}

fraction operator/(const fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a*fraction(the_fraction_b.denominator,the_fraction_b.numerator);
}

fraction operator+= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a=the_fraction_a+the_fraction_b;
}

fraction operator-= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a=the_fraction_a-the_fraction_b;
}

fraction operator*= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a=the_fraction_a*the_fraction_b;
}

fraction operator/= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a=the_fraction_a/the_fraction_b;
}

fraction operator-  (const fraction& the_fraction)
{
    return 0-the_fraction;
}

fraction operator++ (fraction& the_fraction)
{
    the_fraction=the_fraction+1;
    return the_fraction;
}
fraction operator++ (fraction& the_fraction,int)
{
    the_fraction=the_fraction+1;
    return the_fraction-1;
}
fraction operator-- (fraction& the_fraction)
{
    the_fraction=the_fraction-1;
    return the_fraction;
}
fraction operator-- (fraction& the_fraction,int)
{
    the_fraction=the_fraction-1;
    return the_fraction+1;
}



bool operator>  (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a.numerator*the_fraction_b.denominator>the_fraction_b.numerator*the_fraction_a.denominator;
}
bool operator<  (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a.numerator*the_fraction_b.denominator<the_fraction_b.numerator*the_fraction_a.denominator;
}
bool operator>= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a.numerator*the_fraction_b.denominator>=the_fraction_b.numerator*the_fraction_a.denominator;
}
bool operator<= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a.numerator*the_fraction_b.denominator<=the_fraction_b.numerator*the_fraction_a.denominator;
}
bool operator== (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a.numerator*the_fraction_b.denominator==the_fraction_b.numerator*the_fraction_a.denominator;
}
bool operator!= (fraction& the_fraction_a,const fraction& the_fraction_b)
{
    return the_fraction_a.numerator*the_fraction_b.denominator!=the_fraction_b.numerator*the_fraction_a.denominator;
}



fraction::fraction()
{
    numerator=0;
    denominator=1;
}

fraction::fraction(long long the_numerator)
{
    numerator=the_numerator;
    denominator=1;
}

fraction::fraction(long long the_numerator,long long the_denominator)
{
    long long mcf=fraction::MCF(the_numerator,the_denominator);
    numerator=the_numerator/mcf;
    denominator=the_denominator/mcf;
}

fraction::fraction(fraction the_fraction_a,fraction the_fraction_b)
{
    long long the_numerator=the_fraction_a.numerator*the_fraction_b.denominator;
    long long the_denominator=the_fraction_a.denominator*the_fraction_b.numerator;
    long long mcf=fraction::MCF(the_numerator,the_denominator);
    numerator=the_numerator/mcf;
    denominator=the_denominator/mcf;
}

double fraction::decimal()
{
    return 1.0*numerator/denominator;
}

long long fraction::getnum()
{
    return numerator;
}
long long fraction::getden()
{
    return denominator;
}
void fraction::setnum(long long num)
{
    numerator=num;
    long long mcf=fraction::MCF(numerator,denominator);
    numerator/=mcf;
    denominator/=mcf;
}
void fraction::setden(long long den)
{
    if(den!=0)
    {
        denominator=den;
        long long mcf=fraction::MCF(numerator,denominator);
        numerator/=mcf;
        denominator/=mcf;
    }
    else
    {
        cout<<"False,the denominator == 0!!!";
    }
}

typedef fraction fac;

}

#endif