#include <iostream>
#include <stdio.h> 
#include <fstream> 
#include <sstream>
using namespace std;
int main()
{
/*FILE * fid;
fid=fopen("0.off","r");
FILE * fout;
fout=fopen("0_out.off","w");
char buff[1024];
while(fgets(buff,sizeof(buff),fid)!=NULL)
{
fputs(buff,fout);
}
cout<<"hello world"<<endl;
*/
const int len=100;
char buffer[100];
float metrix[4002][3];
for(int i=0;i<4002;i++)
{
for(int k=0;k<3;k++)
{
metrix[i][k]=0;
}
}
char temp[100];
float onecoor;
ofstream out("meanShape_spleen.off");
for(int offnumber=0;offnumber<5;offnumber++)
{//20 offfile read and average cooriditions
char offname[512];
sprintf(offname,"brain-%d.off",offnumber);
ifstream in(offname);//offin

in.getline(buffer,sizeof(buffer));//read the first line
in.getline(buffer,sizeof(buffer));//read the second line
//in.getline(buffer,sizeof(buffer));//skip the first three line
for(int i=0;i<4002;i++)
{
in.getline(temp,len);
stringstream stringin(temp);
int j=0;
while(stringin>>onecoor)//read one line and extract the float number(skip the space)
{
metrix[i][j]=metrix[i][j]+onecoor;
j++;
}
}
/*for(int i=0;i<4002;i++)
{for(int k=0;k<3;k++)
{
cout<<metrix[i][k]<<" ";

}
cout<<endl;
}*/
}
//write into meanshape_spleen.off with specific format
ifstream in_last("brain-0.off");//read one dataset
in_last.getline(buffer,sizeof(buffer));//read the first line
out<<buffer<<endl;//input the first line to meanshape.off
in_last.getline(buffer,sizeof(buffer));//read the second line
out<<buffer<<endl;//input the second line
//in_last.getline(buffer,sizeof(buffer));//skip the first three line
//out<<buffer<<endl;//input the third line
for(int i=0;i<4002;i++)
{
in_last.getline(temp,len);
for(int k=0;k<3;k++)
{
if(k==2)
{
metrix[i][k]=metrix[i][k]/5;//average all the cooriditions
out<<metrix[i][k];//write cooriditions into meanshape
}
else{
metrix[i][k]=metrix[i][k]/5;//average all the cooriditions
out<<metrix[i][k]<<" ";//write cooriditions into meanshape
}
}
out<<endl;
}
for(int line=0;line<8000;line++)
{
in_last.getline(temp,len);
out<<temp<<endl;
}
return 0;
}
