#include <bits/stdc++.h>
using namespace std;

int main()
{ cout<<"Name : "<<endl;
   cout<<"Roll Number : "<<endl;
   cout<<"Enter the string : ";
   string s;
   cin>>s;
   vector<int>freq(26);
   for(auto c : s)
   { freq[c-'a']++;
   }
   for(int i=0;i<26;i++)
   { if(freq[i]!=0)
      { cout<<"Occurence of "<< char(i+'a')<<" is "<<freq[i]<<endl;
      }
   }
   return 0;
}
