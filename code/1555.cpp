#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
struct BIGNUM
{
    bool symbol; 
    vector<int>num;
    BIGNUM(string sNum = "0"){*this=sNum;}
    BIGNUM(int iNum){*this=iNum;}
    BIGNUM operator=(const int iNum)
    {
        num.erase(num.begin(), num.end());
        int tmp(iNum);
        if(iNum<0){symbol=true;tmp=-tmp;}
        else symbol=false;
        while(tmp >= 10){num.push_back(tmp % 10);tmp /= 10;}
        if(tmp != 0) num.push_back(tmp);
        else if(num.empty()) num.push_back(0);
        return *this;
    }
    BIGNUM operator = (const string sNum)
    {
        num.erase(num.begin(), num.end());
        for(string::size_type i(sNum.size() - 1); i > 0; --i)num.push_back(sNum[i] - '0');
        if(sNum[0] == '-')symbol = true;
        else
        {
            symbol = false;
            num.push_back(sNum[0] - '0');
        }
        for(vector<int>::size_type i(num.size() - 1); num[i] == 0 && i > 0; --i)num.pop_back();
        return *this;
    }
    BIGNUM operator = (const BIGNUM bInt)
    {
        num.erase(num.begin(), num.end());
        for(vector<int>::size_type i(0); i < bInt.num.size(); ++i){num.push_back(bInt.num[i]);}
        symbol = bInt.symbol;
        return *this;
    }
    BIGNUM operator + (const BIGNUM bInt) const
    {
        BIGNUM rslt;
        if(bInt.symbol == (*this).symbol){if(bInt.symbol) rslt.symbol = true;}
        else if((*this).symbol) 
        {
            rslt = bInt - (-*this);
            rslt.symbol = true;
            return rslt;
        }
        else if(bInt.symbol)
        {
            rslt = *this - (-bInt);
            return rslt;
        }
        vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), lng;
        lng = (lenA > lenB ? lenA : lenB); 
        for(vector<int>::size_type i(0); i < lng; ++i)
        {
            int tmp(rslt.num[rslt.num.size() - 1]); 
            if(i < lenA) tmp += num[i];
            if(i < lenB) tmp += bInt.num[i];
            rslt.num[rslt.num.size() - 1] = tmp % 10; 
            rslt.num.push_back(tmp / 10); 
        }
        if(rslt.num[lng] == 0) rslt.num.pop_back(); 
        return rslt;
    }
    BIGNUM operator - (BIGNUM bInt) const
    {
        BIGNUM rslt, myInt(*this), tmp;
        vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), lng, shrt, len;
        shrt = (lenA > lenB ? lenB : lenA);
        lng = (lenA > lenB ? lenA : lenB); 
        if(bInt.symbol == myInt.symbol)
        {
            if(!bInt.symbol)  
            {
                if(myInt < bInt)
                {
                    tmp = myInt; myInt = bInt; bInt = tmp;  
                    rslt.symbol = true;
                }
            }
            else  
            {
                if(myInt > bInt)
                {
                    tmp = myInt; myInt = bInt; bInt = tmp; 
                    rslt.symbol = false;
                }
                myInt = -myInt; bInt = -bInt;
                rslt.symbol = true;
            }
        }
        else if(myInt.symbol) return -(-myInt + bInt); 
        else if(bInt.symbol) return myInt + (-bInt);
        for(vector<int>::size_type i(0); i < lng; ++i)
        {
            if(i < shrt)
            {
                if(myInt.num[i] < bInt.num[i])
                {
                    myInt.num[i + 1] -= 1;
                    rslt.num[i] = myInt.num[i] + 10 - bInt.num[i]; 
                }
                else rslt.num[i] = myInt.num[i] - bInt.num[i]; 
            }
            else rslt.num[i] = myInt.num[i];
            rslt.num.push_back(0);
        }
        for(vector<int>::size_type i(rslt.num.size() - 1); rslt.num[i] == 0 && i > 0; --i)rslt.num.pop_back();
        return rslt;
    }
    BIGNUM operator-()const
    {
        BIGNUM rslt(*this);
        if(rslt!=0)rslt.symbol=!rslt.symbol;
        return rslt;
    }
    BIGNUM operator*(const BIGNUM bInt) const
    {
        BIGNUM rslt;
        vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), len(0);
        for(vector<int>::size_type i(0); i < lenA; ++i)
        for(vector<int>::size_type j(0); j < lenB; ++j)
        if(rslt.num.size() - 1 < i + j)
        {
            ++len;
            rslt.num.push_back(num[i] * bInt.num[j]); 
        }
        else rslt.num[i + j] += num[i] * bInt.num[j];
        ++len;
        for(vector<int>::size_type i(0); i < len; ++i)
        {
            if(i + 1 < rslt.num.size())rslt.num[i + 1] += rslt.num[i] / 10;
            else if(rslt.num[i] >= 10)
            {
                rslt.num.push_back(rslt.num[i] / 10);
                ++len;
            }
            else break;
            rslt.num[i] %= 10;
        }
        rslt.symbol=symbol^bInt.symbol;
        return rslt;
    }
    BIGNUM operator/(const BIGNUM bInt) const
    {
        BIGNUM tmp;
        string rsltS;
        if(bInt == 0)return BIGNUM(0);
        vector<int>::size_type lenA(num.size()), lenB(bInt.num.size()), len(0);
        vector<int>::size_type i(lenA);
        while(i--)
        {
            if(tmp == 0) tmp.num.pop_back();
            tmp.num.insert(tmp.num.begin(), num[i]); 
            BIGNUM tmp2;
            int i(10);
            while(i--) 
            {
                tmp2=(bInt<0?-bInt:bInt)*i;
                tmp2=tmp-tmp2; 
                if(tmp2>=0) 
                {
                    rsltS+=i+'0';
                    tmp = tmp2;
                    break;
                }
            }
        }
        BIGNUM rslt(rsltS);
        rslt.symbol=symbol^bInt.symbol;
        return rslt;
    }
    BIGNUM operator+=(const BIGNUM bInt)
    {
        *this=*this+bInt;
        return *this;
    }
    BIGNUM operator-=(const BIGNUM bInt)
    {
        *this=*this-bInt;
        return *this;
    }
    BIGNUM operator*=(const BIGNUM bInt)
    {
        *this=*this*bInt;
        return *this;
    }
    BIGNUM operator/=(const BIGNUM bInt)
    {
        *this=*this/bInt;
        return *this;
    }
    bool operator<(const BIGNUM bInt) const
    {
        vector<int>::size_type bLen(bInt.num.size());
        if(!bInt.symbol&&symbol)return true;
        else if(bInt.symbol&&!symbol)return false;
        else if(num.size()!=bLen)
        {
            if(!symbol) return num.size()<bLen;
            else return num.size()>bLen;
        }
        for(vector<int>::size_type i(bLen - 1);i>0;--i)
        {
            if(num[i] != bInt.num[i])
            {
                if(!bInt.symbol&&!(*this).symbol)return num[i]<bInt.num[i];
                else return bInt.num[i]<num[i];
            }
        }
        if(!bInt.symbol &&!symbol)return num[0]<bInt.num[0];
        else return bInt.num[0]<num[0];
    }
    bool operator > (const BIGNUM bInt) const{return bInt<*this;}
    bool operator <= (const BIGNUM bInt)const{return !(*this>bInt);}
    bool operator >= (const BIGNUM bInt)const{return !(*this<bInt);}
    bool operator != (const BIGNUM bInt)const{return (*this<bInt)||(*this>bInt);}
    bool operator == (const BIGNUM bInt)const{return !(*this!=bInt);}
};
istream& operator>>(istream &in,BIGNUM& x)
{
    string tmp;
    in>>tmp;
    x=tmp;
    return in;
}
ostream& operator<<(ostream &out,BIGNUM& x)
{
    if(x.symbol)cout<<'-';
    for(vector<int>::size_type i(x.num.size()-1);i>0;--i)out<<x.num[i];
    out<<x.num[0];
    return out;
}
int main()
{
	BIGNUM a,b;
	cin>>a>>b;
	BIGNUM c=a*b;
	cout<<c;
	return 0;
}