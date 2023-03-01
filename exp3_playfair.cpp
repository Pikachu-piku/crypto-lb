#include<bits/stdc++.h>
using namespace std;
void tolowercase(string &plain){
    int i;
    for(i=0;i<plain.length();i++){
        if(plain[i]>64 && plain[i]<91){
            plain[i]+=32;
        }
    }
}
vector<vector<char> >create_matrix(string key){
    vector<vector<char> >mat(5,vector<char>(5,'x'));
    int i=0,j=0;
    set<char>s;
    for(int k=0;k<key.size();k++){
        if(s.find(key[k])!=s.end()) continue;
        mat[i][j]=key[k];
        j++;
        if(j>=5){
            i++;
            j=0;
        }
        s.insert(key[k]);
    }
    for(int k=0;k<26;k++){
        char c=char(k+'a');
        if(c!='j' && (s.find(c)==s.end())) {
            mat[i][j]=c;
            j++;
            if(j>=5){
                i++;
                j=0;
            }
            if(i>=5) break;
        }
        if(i>=5) break;
    }
    return mat;
}
pair<int,int>search(vector<vector<char> >mat,char c){
     if(c=='j') c='i';
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            if(mat[i][j]==c){
                return {i,j};
            }
        }
    }
    return {0,0};
}
string find_encrypt(char c1,char c2,vector<vector<char> >mat){
    pair<int,int>p1=search(mat,c1),p2=search(mat,c2);
    string s="";
    if(p1.first==p2.first){
        c1=mat[p1.first%5][(p1.second+1)%5];
        c2=mat[p2.first%5][(p2.second+1)%5];
        s+=c1;
        s+=c2;
    }
    else if(p1.second==p2.second){
        c1=mat[(p1.first+1)%5][(p1.second)%5];
        c2=mat[(p2.first+1)%5][(p2.second)%5];
        s+=c1;
        s+=c2;
    }
    else{
        c1=mat[p1.first][p2.second];
        c2=mat[p2.first][p1.second];
        s+=c1;
        s+=c2;
    }
    return s;
}
string find_decrypt(char c1,char c2,vector<vector<char> >mat){
    pair<int,int>p1=search(mat,c1),p2=search(mat,c2);
    string s="";
    if(p1.first==p2.first){
        c1=mat[p1.first%5][(p1.second+4)%5];
        c2=mat[p2.first%5][(p2.second+4)%5];
        s+=c1;
        s+=c2;
    }
    else if(p1.second==p2.second){
        c1=mat[(p1.first+4)%5][(p1.second)%5];
        c2=mat[(p2.first+4)%5][(p2.second)%5];
        s+=c1;
        s+=c2;
    }
    else{
        c1=mat[p1.first][p2.second];
        c2=mat[p2.first][p1.second];
        s+=c1;
        s+=c2;
    }
    return s;
}
vector<string>break_into_two(string s){
    string ans="";
    ans+=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]){
            ans+='x';
            ans+=s[i];
        }
        else ans+=s[i];
    }
    if(ans.size()%2!=0) ans+='z';
    vector<string>v;
    for(int i=0;i<ans.length();i+=2){
        v.push_back(ans.substr(i,2));
    }
    return v;
}
int main(){
    cout<<"Name: Durgam Priyanka \nRoll NO: 20115031 \n";
    string key,Text;
    cout<<"key:";
    cin>>key;
    cout<<"Text:";
    cin>>Text;
    tolowercase(key);
    tolowercase(Text);
    vector<vector<char> >v=create_matrix(key);
    vector<string>br=break_into_two(Text);
    string s;
    for(auto& c:br){
         //cout<<c<<endl;
        s+=find_encrypt(c[0],c[1],v);
    }
    cout<<"\n";
    cout<<"Cipher text: ";
    cout<<s<<"\n";
    vector<string>dbr=break_into_two(s);
    s="";
    for(auto c:dbr){
        s+=find_decrypt(c[0],c[1],v);
    }
    cout<<"Deciphered text: ";
    cout<<s<<"\n";
    return 0;
}
