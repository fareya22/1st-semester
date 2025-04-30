#include<bits/stdc++.h>
using namespace std;

struct tokenInfo
{
     /*  string tokenName;
       string type;
       int lineNumber;*/
    int line_no;
    string word;

};

tokenInfo perLine[20000];


void commentsRemoval(FILE *inputFp,FILE*outputFp)
{
       char ch,nextCh;

      while ((ch = fgetc(inputFp)) != EOF)
    {
        if (ch == '/')
        {
            nextCh = fgetc(inputFp);
            if (nextCh == '/')
             {
                while ((ch= fgetc(inputFp)) != EOF && ch != '\n') {}
                if (ch == '\n')
                 {
                    fputc(ch, outputFp);
                }
             }
            else if (nextCh== '*')
                {
                while ((ch = fgetc(inputFp)) != EOF)
                {
                    if (ch == '*')
                    {
                        nextCh = fgetc(inputFp);
                        if (nextCh == '/')
                         {
                            break;
                        }
                       else
                        {
                            ungetc(nextCh, inputFp);
                        }
                    }
                }
              }
            else
            {
                fputc(ch, outputFp);
                fputc(nextCh, outputFp);
            }
         }
         else
            {
                  fputc(ch, outputFp);
           }
    }
}



int inputCodeInLineByLine( string inputFile )
{
    int totalLine = 0;
    string part;

    stringstream X( inputFile );
    while ( getline( X, part, '\n' ) )
    {
        perLine[ totalLine ].word = part + " ";
        perLine[ totalLine++ ].line_no = totalLine;
    }

    return totalLine;
}


int readInputCode()
{

        FILE *inputFp, *outputFp;
    char inputPerLine[20000], outputLine[20000];

     inputFp = fopen("code321.txt", "r");

    if (inputFp == NULL)
    {
        printf(" Error opening file\n");
        return 1;
    }

    outputFp = fopen("output.txt","w");
    if (inputFp == NULL)
    {
        printf(" Error opening file\n");
        return 1;
    }

        commentsRemoval(inputFp, outputFp);

    fclose(inputFp);
    fclose(outputFp);

    printf("Comment removal complete.\n");
}


int main()
{

     string codeText;

	codeText = readInputCode();
	int total_line = inputCodeInLineByLine( codeText );

    string str="";
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("sourceCode.txt");
    outputFile.open("Token.txt");

    if(inputFile.is_open())
    {
        cout<<"Input file is opened";
    }

}

