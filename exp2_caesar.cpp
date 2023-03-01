#include <bits/stdc++.h>
using namespace std;

string encrypt(string text,int s)
{ string result="";
   for(int i=0;i<text.length();i++)
   { if(isupper(text[i])) result+=char(int(text[i]+s-65)%26+65);
      else
      { result+=char(int(text[i]+s-97)%26+97);
      }
   }
   return result;
}
string decrypt(string text,int s)
{ string result="";
    for(int i=0;i<text.length();i++)
    { if(isupper(text[i])) result+=char(((int(text[i]-s-65)%26+26)%26)+65);
        else
        { result+=char(((text[i]-s-97)%26+26)%26+97);
        }
    }
    return result;
}
int main()
{ cout<<"Name : "<<endl;
   cout<<"Roll Number : "<<endl;
   cout<<"Enter the string : ";
   string text;
   cin>>text;
   cout<<"Enter the shift :";
   int shift;
   cin>>shift;
   string encrypt_string=encrypt(text,shift);
   cout<<"Encrypted String :"<<encrypt_string<<endl;
   cout<<"Decrypted String :"<<decrypt(encrypt_string,shift)<<endl;
   
   return 0;
}
