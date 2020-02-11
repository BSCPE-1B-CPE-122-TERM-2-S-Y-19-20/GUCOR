#include<iostream>
using namespace std;
void complement(int set1[], int set2[],int size1,int size2)
{
  int i = 0, j = 0; 
  while (i<size1||j<size2) { 
    if(set1[i]<set2[j])
	{ 
      cout <<set1[i]<< " "; 
      i++; 
    } 
	else if(set1[i]>set2[j]) 
	{ 
      j++; 
    } 
	else if(set1[i]==set2[j]) 
	{ 
      i++; 
      j++; 
    } 
  }
  while (i<size2)  
    cout <<set1[i]<<" "; 	
}
void typeunion(int set1[], int set2[], int size1, int size2)
{
	int i=0, j=0;
	cout << "\nSet A Union Set B : ";
	while (i < size1 && j < size2)
	{
		if (set1[i] < set2[j])
			cout << set1[i++] << " ";
		else if (set2[j] < set1[i])
			cout << set2[j++] << " ";
    	else
		{
			cout << set2[j++] << " ";
			i++;
		}
	}
	while(i < size1)
		cout << set1[i++] << " ";
	while(j < size2)
    	cout << set2[j++] << " ";	
}
void intersection(int set1[], int set2[], int size1, int size2)
{
	int i=0, j=0;
	cout << "\nSet A Intersection Set B : ";
	while (i < size1 && j < size2)
	{
		if(set1[i] < set2[j])i++;
		else if(set2[j] < set1[i])j++;
		else
		{
			cout << set2[j] << " ";
			i++;
			j++;
		}
	}
}
int main()
{
	int choice,i,j,temp=0,size,k;
	int merge[100];
	int set1[100],size1;
	int set2[100],size2;
	
	cout << "Enter size of Set A : ";
	cin >> size1;
	cout << "\nEnter Elements : " << endl;
	for(i=0;i<size1;i++)
	{
		cin >> set1[i];
	}
	cout << "\nEnter size of Set B : ";
	cin >> size2;
	for(i=0;i<size2;i++)
	{
		cin >> set2[i];
	}
	menu:
	for (i=0;i<size1;i++) 
    {
		for (j=i+1;j<size1;j++)
        {
			if (set1[i]>set1[j])
			{
				temp=set1[i];
				set1[i]=set1[j];
				set1[j]=temp;
			}
		}
	}
	temp=0;
	for (i=0;i<size2;i++) 
    {
		for (j=i+1;j<size2;j++)
        {
			if (set2[i]>set2[j])
			{
				temp=set2[i];
				set2[i]=set2[j];
				set2[j]=temp;
			}
		}
	}	
	system("cls");
	cout << "\nSet A = ";
	for(i=0;i<size1;i++)
	{
		cout << set1[i] << ", ";
	}
	cout << "\nSet B = ";
	for(i=0;i<size2;i++)
	{
		cout << set2[i] << ", ";
	}
	cout << "\n\n1. Union\n2 Intersection\n3. Complement\n4.Exit\n\nEnter Choice : ";
	cin >> choice;
	switch(choice){
		case 1:typeunion(set1, set2, size1, size2);
			break;
		case 2:intersection(set1, set2, size1, size2);
			break;
		case 3:complement(set1, set2, size1,size2);
			break;
		case 4: cout << "\nExiting" <<endl;
				exit(0); 
			break;
		default:
			cout << "\nInvalid Choice!";
			system("pause");
			system("cls");
			goto menu;
	}
}