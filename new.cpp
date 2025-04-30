#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp1 = fopen("file1.c","r");
    FILE *fp2 = fopen("file2.c","w");

    char ch;
    if(fp1==NULL)
    {
        cout<<"Error opening file"<<endl;
        return 0;
    }
    while((ch=fgetc(fp1))!=EOF)
    {
       if(ch!=' ')
            fputc(ch,fp2);
    }
        fclose(fp1);
        fclose(fp2);
        FILE *fp = fopen("file2.c","r");
        string s =file2.c;
      while((ch=fgetc(fp))!=EOF)
      {
          cout<<ch;
      }


}
