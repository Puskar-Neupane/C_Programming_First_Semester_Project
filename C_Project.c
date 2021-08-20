#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#define SIZE 50
float absof(float x)
{
int n=(int)x;
if(n>=0)
return(x);
else
{
x=x*(-1);
return(x);
}
}
//THISISTHECODEFORTHECALCULATIONOFDETERMNINANT
int determinant(int  matrix[50][50],int n){
int det=0;
int submatrix[50][50];
if(n==2)
return((matrix[0][0]*matrix[1][1])-(matrix[1][0]*
matrix[0][1]));
else
{
for(int x=0;x<n;x++)
{
int subi=0;
for(int i=1;i<n;i++)
{
int subj=0;
for(int j=0;j<n;j++)
{
if(j==x)
continue;
submatrix[subi][subj]=matrix[i][j];
subj++;
}
subi++;
}
det=det+(pow(-1,x)*matrix[0][x]*
determinant(submatrix,n-1));
}
}
return det;
}
//THISISTHECODEFORTHEINPUTOFVOLTAGES
void voltage(float v[],int m)
{
int i;
float cv[50],ncv[50];
for(i=0;i<m;++i)
{
 printf("\nEnter voltage in direction of current in loop no%d",i+1);

scanf("%f",&cv[i]);
}
for(i=0;i<m;++i)
{
printf("\nEnter voltage opposite to direction of current in loopno%d",i+1);

scanf("%f",&ncv[i]);
}
for(i=0;i<m;++i)
{
v[i]=cv[i]-ncv[i];
}
for(i=0;i<m;++i)
{
printf("\nVoltages of mesh%d:",i+1);
printf("%.3f Volt",v[i]);
}
printf("\n\n\n");
}
int main()
{
int temp[100],st[100];
int mesh,i,j,cm;
int m;
float current[100];
printf("HELLO USER!!!You are in the program which can calculate current flowing in any resistor and simplest loop(mesh)of any complicated circuit.\nNOTE : Mesh is the simplest loop which doesn't contain any further loop inside it.\n");



printf("\n\n\nEnter the no of meshes:");
scanf("%d",&mesh);
int a[SIZE][SIZE];
//THISCODEISTHEINPUTFORRESISTANCE
for(i=0;i<mesh;i++)
{
for(j=0;j<=i;j++)
{
if(i==j)
{
printf("Enter total resistance of loop%d:",i+1);
scanf("%d",&a[i][j]);
}
else
{
printf("Enter the common resistance of loop %d and loop %d:",i+1,j+1);

scanf("%d",&cm);
a[i][j]=cm*(-1);
}
}
}
for(i=0;i<mesh;i++)
{
for(j=0;j<mesh;j++)
{
if(i<j)
a[i][j]=a[j][i];
}
}
printf("\nResistance:\n");
for(i=0;i<mesh;i++)
{
for(j=0;j<mesh;++j)
{
printf("%d",a[i][j]);
}
printf("\n");
}
float v[SIZE];
voltage(v,mesh);
m=determinant(a,mesh);
for(i=0;i<mesh;i++)
{
for(j=0;j<mesh;j++)
{
temp[j]=a[j][i];
a[j][i]=v[j];//THIS IS THE PART WHERE COLUMN OF RESISTANCES IS SWAPED BY VOLTAGES
}
}
int x;
st[i]=determinant(a,mesh);//THIS IS THE PART WHERE CALCULATED DELTA 1,2,3,... GET SSTORED

for(x=0;x<mesh;x++){
a[x][i]=temp[x];
}
for(i=0 ;i < mesh;i++)
{
current[i]=(float)st[i]/m;
}
for(i=0;i<mesh;i++)
{
for(j=0;j<=i;j++)
{
if(i==j)
{
if(current[i]<0)
printf("Current flowing in the loop%d=%.3fA,but opposite in direction of assigned current\n",i+1,current[i]*(-1));

else
printf("Current flowing in the loop%d=%.3fA,in the same direction of assigned current\n",i+1,current[i]);

}
else if(a[i][j]==0)
printf("There is no resistance common loop %d and loop %d \n",i+1,j+1);

else
{
if(absof(current[i]-current[j])<0)
{
printf("Current flowing in the common resistance %d of loop %d and %d=%.3fA,in the direction of current assigned in loop %d\n",a[i][j]*(-1),i+1,j+1,absof(current[i]-current[j])*(-1),j+1);
}


else
printf("\nCurrent flowing in the common resistance of %d of loop %d and %d=%.3fA,in the direction of current assigned in loop %d\n",a[i][j]*(-1),i+1,j+1,absof(current[i]-current[j]),i+1);


}
}}
printf("\nThank you");
return 0;
}
