/*************************************************************
	������������ ������� �3. ���������� �������.
							������������ ��������� ������.
							���������� ��������� ���������� � ������.
							������� ���������.
							������.
*************************************************************/


#define	  stop __asm nop
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <string>

#include  <iostream>
int main()
{

///////////////////////////////////////////////////////////////
//			���������� �������                               //
///////////////////////////////////////////////////////////////
/*
	//������� 1. �������� ���������� ������ � ����������� ���������
	//�������� ��������� ��������� �������:
	//�) ������������������ ������ ��� ����������
	//�) �������� �������������������� ������ � ��������� �������� ���������
	//	� ������� ����
	//					 |--------|		
	//				   / |3  3  3 |		
	//    			 |---------|3 |
    //			   / | 2  2  2 |3 |
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__| 
	//			  | 1  1  1 | /
	//			  |_________|
	//���������� ��������� ��������� ������������ ������ �������.
	//�) ������� ����� ��������� �������
	 
	//�) ������������������ ������ ��� ����������:
	//					 |--------|		
	//				   / |3  0  0 |		
	//    			 |---------|0 |
    //			   / | 2  0  0 |0 |
	//			  |---------|0 |__|
	//			  | 1  0  0 |0 | /
	//			  | 0  0  0 |__| 
	//			  | 0  0  0 | /
	//			  |_________|
  


	//�) ������������� �������� ���������� ����������:
	//�������� � ������������������ ���������� ���������� ��� �������:
	//���������� ������ � ������ ����������. �������� ������� � �������������
	//��������� ����� ��������.
*/
	//a                           //������// /*�*/
	int arr1[3][3][3] = {{{1,1,1},{1,1,1},{1,1,1}},{{2,2,2},{2,2,2},{2,2,2}},{{3,3,3},{3,3,3},{3,3,3}}};
	                     //----����-------------// 
   stop
	//b 
    int arr2[3][3][3]; 
    int *p=&arr2[0][0][0];//
	for (int i = 0;i<(sizeof(arr2)/sizeof(int));i++)// ��� �����
	{*p=i/(sizeof(arr2[0])/sizeof(int))+1;
	 ++p;
	}
	int Sum=0;
	int *ps=&arr2[0][0][0];
	for (int i = 0;i<(sizeof(arr2)/sizeof(int));i++)// ��� �����
	{*ps=i/(sizeof(arr2[0])/sizeof(int))+1;
	 Sum+=(*ps);
	 ++ps;
	}

	int arr3[3][3][3] = {{1},{2},{3}};	

	char arr_string [5][5]={{"ABCD"},{"EFGT"}};
	//char* arr_string1 [5]={{"ABCD"},{"EFGT"}};// ������ ����������//���� ������� ����� ��� ��� ����, ��� ����  �� ������ �����
	const char* arr_string1 [5]={{"ABCD"},{"EFGT"}};// ������ ����������//���� ������� ����� ��� ��� ����, ��� ����  �� ������ �����
	//const ��������� �����. (������ ������_�)
	char c1 = arr_string [0][1];
	char c2 = arr_string1 [0][1];
    arr_string [0][1] = 'm';
    //arr_string1 [0][1] = 'm';
	stop
///////////////////////////////////////////////////////////////
//			������������ ��������� ������                    //
///////////////////////////////////////////////////////////////
	//�������2. �������� ������������ ���������� ������ � �������������,
	//������������ � �������� ���������� ��������� - N*M.
	//������� �������� ��������� ������� ���������� ��������� �����.
	//�������  ����� ���������.
	//��������� 1: ��� ��������� ��������� ����� ����������� �������
	//����������� ���������� - rand() (<cstdlib>)
	//��������� 2: �� ����� ���� �� ��������, ������� ��������� ����������� ���������
	//����� �������� �����������������, �� ���� ��� ���� ���������������� ��������
	//���������� �� ��������� ��� ���������� ������������������ ��������.
	//��� ���� ����� ������������ "���������" �������� ���� ������� ��� ������ 
	//������� ���������� ����������� ������� ����������� ���������� srand() (<cstdlib>)
	//� time() (<ctime>).
	//������� srand() ������������ ��������� ������ ��������� � ���������� � �������� ��������� ��������.
	//������� time() ������ ��� ����� �������, �������� ������� �����
	
	srand( time( 0 ) );
//#include <cstdlib>
//#include <cstdlib>
//#include <ctime> // ������� � ������
int N,M;
//srand();
N = rand()%8 + 2;
//srand();
M= rand()%8 + 2;
printf("---------------2-------------------\n");
std::cout<<"N="<<N<<std::endl;
std::cout<<"M="<<M<<std::endl;
int* pn=new int[N*M];

for (int i =0;i<(N*M);i++)
{ 
	pn[i]=rand()%10;
    
	if(!(i%M)) printf("\n");
	std::cout<<pn[i];
}
 //delete[] pn;
 //pn=0;
    printf("\n");
    stop
	//�������2�. � �������������� ������� ������������ ������ ������ ��
	//�������� ��������. ����������� ���������� "�������"
	{//1
    int**ppn = new int *[N]; 
    //int n = N*M;
	for(int i=0;i<N;i++)
	 {ppn[i]=pn+i*M;
	 }
    for(int i=0; i<N; i++)  
	 {//for1
	  for(int j =0;j<M-1;j++)// n-1, ��� ��� ��������� ������������� �������� �� ����� �����
	   {//for2
		int max = j; 
		for(int k=j+1; k<M; k++)
		 {
		  if(ppn[i][k]>ppn[i][max])max=k;
		 }
		 int tmp = ppn[i][max];
		 ppn[i][max] = ppn[i][j];
		 ppn[i][j] = tmp;
	  }//for2'
	 }//for1'
  
   for(int i=0; i<N; i++)  
	 {printf("\n");
	  for(int j =0;j<M;j++)
		printf("%d ",ppn[i][j]);
     }
  // delete[] pn;
  // pn=0;
   delete [] ppn;
   ppn=0;
    }
/*
	for(int i=0; i<n-1; i++)  // n-1, ��� ��� ��������� ������������� �������� �� ����� �����
	{	
		int max = i; 
		for(int j=i+1; j<n; j++)
		{
		 if(pn[j]>pn[max])max=j;
		}
		int tmp = pn[max];
		pn[max] = pn[i];
		pn[i] = tmp;
    }
 	for (int i =0;i<(N*M);i++) //�����!
     {if(!(i%M)) printf("\n");
	  std::cout<<pn[i];
     }
	}//1'
    //delete[] pn;
    //pn=0;
*/
	stop
	//�������2�. �������� ���������� ������ ������������ N.
	//����������� �������� i-��� �������� ����������� �������  
	//������ �������� �������� ��������� i-�� ������
	//����������� �������
    double *p1=new double[N]; //���������� ���� N ����
	int j=0;
	int Sum1=0;
    int **ppmas = new int*[N];
	for(int i=0;i<N;i++)
	 { 
      ppmas[i]=pn+i*M;
	 }
    for(int i=0;i<N;i++)
	{Sum1=0;
	 for(int j=0;j<M;j++)
	  {Sum1+=ppmas[i][j];
	   p1[i]=(static_cast<double>(Sum1)/M);
	  }
	}
    
	printf("\n\n");
    for (int i=0;i<N;i++) //�����!
     {std::cout<<p1[i];
	  printf("_");
     }
	//��������� - �� �������� ���������� ������!
    delete[] pn;
	delete[] p1;
	delete[] ppmas;
	ppmas=0;
    pn=0;
	p1=0;
	stop	
	/////////////////////////////////////////////////////////////////////
	//������� 3. �) �������� �������� ����, ������� ������ NN ����� ����� � �������
	//������ ����� � ����������� ���� ���������� ���������� ������, ������ ���
	//������������ ���������� �������� �� �����������
#if 0
	printf("\n---------------3-------------------\n");
	{//2
     const int NN = 10;
  	 int m[NN];
	 int max=0;
	 printf("\nEnter mass:\n");
	 for(int i = 0;i<NN;i++)
	 {printf("Enter m[%d]:",i);
	  std::cin>>m[i];
	  int max = i;
	  for(int j=0; j<=i; j++)
	   {if(m[j]>m[max])
	     { max=j;
           int tmp = m[max];
	       m[max] = m[i];
		   m[i] = tmp;
	     }
	    printf("%d[%d].",m[j],j);
	   }
	} 
	   
	 printf("\n\nMass:");  
   	 for(int i = 0;i<NN;i++)
	  {
	   printf("%d[%d].",m[i],i);
	  }
	}//2'
	stop
    
	//�) ������� �����.
	//������������� ���������� ������� ��������� �������:��������� ��������
	//�������� � ������ ������ ��� �������, ��� ��� ��� ������ ��� (�� ���� 
	//����� ������������
    {//3//����� do_while
     printf("\n---------------3b-------------------\n");
     const int NN = 10;
  	 int m[NN];
	 int max=0;
	 printf("\nEnter mass2:\n");
	 int i =0;
     while(i<NN)
	 {printf("Enter m[%d]:",i);
	  std::cin>>m[i];
	  int max = i;
	  for(int j=0; j<i; j++)
	   {if(m[j]==m[i]) {printf("\nCopy!\n");i=i-1; break;}
        if(m[j]>m[i])
	     {max=j;
	      int tmp = m[max];
	      m[max] = m[i];
	      m[i] = tmp;
	     }
	   }
	  i=i+1;
	  for(int out=0;out<i;out++)
	   {printf("%d[%d].",m[out],out);
	   }
	 } 
	   
	 printf("\n\nMass2:");  
   	 for(int i = 0;i<NN;i++)
	  {
	   printf("%d[%d].",m[i],i);
	  }
	}//3'
	stop 
#endif
	 

	///////////////////////////////////////////////////////////////////////////
	//������� 4.� ������� ������ ��������� �������� ���������,
	//�������:
	//������ ������ � ���������� � ������� cin>>...
	//� ����������� ���� ���������� ���������� ������ 5*80 ��������� ���� char;
	//��������� ����� ����� �������� ������ * (�� ���� ������ - "*") ���
	//���������� ������� (������ ��������� ����� ���);
	//���������� ����� � ���������� �������. ���������: ������
	//�� ������������� ��� ���������� ������� �������� ���������
	//���������� �� � ������. ������� ����������� ������� ������
	//���������� �� ��������������� ������ � ���������� ������
	//���������.

    //���������: ��� ����������������� ��������� ����� �����������
	//�������� ����������� ���������� strcmp(...), ������������ ���� <string>.

	
	//���������� ����������� �������� ��� ���������
 //STOP_STRING  -  "*"	//������� "���������� ����"
 //M  -  80	//������������ ������ ����� ������
 //N  -  10	//������������ ���������� ����� � �������
#if 0
	{
	const char STOP_STRING ='*';
	const int M=80;//M-1 => \0
	const int N=10;

	//�������� ���������� ������ � ������ cBuffer ���� char �
	// ������������ N*M
	char cBuffer[N][M];
	char ch;// ��� ���� ����

	//�������� ������ (� ������ cPointers) ���������� �� ������
	//������������ N
	char* cPointers[N];
    int i=0;
    int j=0;
	int nIndex=0;
	int iN=0;
	//���� ����� �����:
	//�) �������� ����������� ��� �����
	printf("\nEnter string:\n");
	//�) ���� �� ������� ������ STOP_STRING ��� �� �������� ���� ������
	while(i<N)// ���� ���� ��������� ������
	{   //iN=i+1;//��� ������ 
		//���� ������ � ������ cBuffer:
		//cin>>cBuffer[i];
		std::cin>>&cBuffer[i][0];
	    //���� ������� ������ - ������� ���������, �� ����� �� �����
		if(cBuffer[i][0]==STOP_STRING){printf("STOP_STRING\n");iN=i;break;}
		//��������� �������� ������� cPointers � �������� nIndex
		//��������� �� ������ � ������� nIndex � ������� cBuffer
		cPointers[nIndex]=&cBuffer[i][0];
     nIndex++; 
     i++;
	 iN=i;
	}
    
	//������ ����������� � ���, ��� ����� ����� ��������.
	printf("\nEnd enter string!!!");
	printf("\nSave string:\n");
    for(int k=0;k<iN;k++)
	 {
		 std::cout<<"str"<<"["<<k<<"]:"<<cBuffer[k]<<std::endl;
	 }


	//������ ��������� ������:
   
    //���� ���������� ����� �� ������ "������������ ��������" �
	//������� �����������. �� ������ �������� - ������������� ������ 
	//��������������� �����
	/*i=0;
    while (i<iN)
	  {//while
       for(int ks=0;ks<(M-1);ks++) ///0
	    {//for1
		 bool pri_sort=false;
         for(int i_str=0;i_str<M-ks-1;i_str++)
		  {//for2
           if(*(cPointers[i]+i_str)>*(cPointers[i]+i_str+1))
		    {char tmp= *(cPointers[i]+i_str);
		    *(cPointers[i]+i_str)=*(cPointers[i]+i_str+1);//������������
			*(cPointers[i]+1+i_str)=tmp;
			pri_sort=true;
		   }
		  }//for2'
		 if(pri_sort==false) break;
	    }//for1'
	   std::cout<<"\nsort out"<<"["<<i<<"]:"<<cBuffer[i]<<std::endl;
	   i++;
	  }//while'
    printf("\nSortMassString:\n");
    for(int kk=0;kk<iN;kk++)
	 {
		 std::cout<<"str"<<"["<<kk<<"]:"<<cBuffer[kk]<<std::endl;
	 }//*/
	printf("\n");
    for(int ks=0;ks<iN;ks++) 
	 {//for1
	   bool pri_sort=false;
        for(int i_str=0;i_str<iN-ks-1;i_str++)
		  {//for2
		   int result = strcmp(cPointers[i_str], cPointers[i_str+1]);
		   if(result>0)//string1 greater than string2
		    {char *tmp =cPointers[i_str];
		     cPointers[i_str]=cPointers[i_str+1];
			 cPointers[i_str+1]=tmp;
			 pri_sort=true;
		    } 
		  }//for2'
		std::cout<<"str"<<"["<<ks<<"]:"<<cPointers[ks]/*cBuffer[ks]*/<<std::endl;
		if(pri_sort==false) break;
	 }//for1'
    printf("\nSortMassString:\n");
    for(int k=0;k<iN;k++)
	 {
		 std::cout<<"str"<<"["<<k<<"]:"<<cPointers[k]<<std::endl;
	 }
    stop
 	}

	//������� 5. ���������� ������� �4, ��������� �� ����������,
	//� ������������ ������� (������?)
	//��� ���� ����������� ��������� (�����������
	// ��������) ����������� � ������� ������ �����
	{
	int nStringNumber;
	int nStringSize;
	int iN=0;
	const char STOP_STRING ='*';
	printf("\nEnter StringNumber:");
	std::cin>>nStringNumber;
	printf("\nEnter StringSize:");
	std::cin>>nStringSize;
    char * pMStr =new char[nStringNumber*nStringSize];
	char **ppMStr=new char*[nStringNumber];
	for(int i=0;i<nStringNumber;i++)
	 {ppMStr[i]=pMStr+i*nStringSize;
	 }
 
	//���� ����� �����:
	int i=0;
    while(i<nStringNumber)// ���� ���� ��������� ������
	{std::cin>>ppMStr[i];
	  
	 //���� ������� ������ - ������� ���������, �� ����� �� �����
	 if(ppMStr[i][0]==STOP_STRING){printf("STOP_STRING\n");iN=i;break;}
		//��������� �������� ������� cPointers � �������� nIndex
		//��������� �� ������ � ������� nIndex � ������� cBuffer
		//cPointers[nIndex]=&cBuffer[i][0];
     //nIndex++; 
     i++;
	 iN=i;
	} 
    //������ ����������� � ���, ��� ����� ����� ��������.
	printf("\nEnd enter string!!!");
	printf("\nSave string:\n");
    for(int k=0;k<iN;k++)
	 {
		 std::cout<<"str"<<"["<<k<<"]:"<<ppMStr[k]<<std::endl;
	 }


	//���� ���������� ����� �� ������ "������������ ��������" �
	//������� ����������� ���� ������� �������
    for(int ks=0;ks<iN;ks++) 
	 {//for1
	   bool pri_sort=false;
        for(int i_str=0;i_str<iN-ks-1;i_str++)
		  {//for2
		   int result = strncmp(ppMStr[i_str], ppMStr[i_str+1],1);
		   if(result>0)//string1 greater than string2
		    {char *tmp =ppMStr[i_str];
		     ppMStr[i_str]=ppMStr[i_str+1];
			 ppMStr[i_str+1]=tmp;
			 pri_sort=true;
		    } 
		  }//for2'
		std::cout<<"\nstr"<<"["<<ks<<"]:"<<ppMStr[ks]/*cBuffer[ks]*/<<std::endl;
		if(pri_sort==false) break;
	 }//for1'
    printf("\nSortMassString:\n");
    for(int k=0;k<iN;k++)
	 {
		 std::cout<<"str"<<"["<<k<<"]:"<<ppMStr[k]<<std::endl;
	 }
  
	
	  
		
	//������������ ������� ������:
     delete [] ppMStr;
	 delete [] pMStr;
	 ppMStr=0;
     pMStr=0;
     stop
	}
#endif
	//������� 6.����� ���������� � ��������. ������� ����������
	//���������� ������ [3][3][3]. � ������� ���������� [] � *
	//������� ��������� �������� �������� [2][2][2] - ��������.
	//���������� ��������� ��������� ������������ ������ �������.
	{
    int Ar1[3][3][3]={{{1,1,1},{4,4,4},{8,8,8}}, {{5,5,5},{7,7,7},{2,2,2}}, {{3,3,3},{9,9,9},{6,6,6}}};
	int *pAr1 = &Ar1[0][0][0];
	int *p2=Ar1[0][0];
	int (*p)[3][3]=Ar1;// ���� �� ����
	printf("\nAr1[2][2][2]=%d",Ar1[2][2][2]);
    printf("\nAr1[2][2][2]=%d",*(*(*(Ar1+2)+2)+2));
    printf("\nAr1[2][2][2]=%d",*(*(*(p+2)+2)+2));
	printf("\nAr1[2][2][2]=%d",p2[3*3+3*3+3*2]); //???
	printf("\nAr1[2][2][2]=%d",p2[24]);

	stop
	}
/**/

	//������� 7. ���������� � ������������� ���������� �� �����������
	// �������. ������������������ ���������� ������
	//double dArray[4][3][3] ���, ��� �������� �� ������� � �������� ��������
	//����, ������� ������ ������� �������� ��������� ������
	//� �������� �����:
	//	����:			     |--------|		
	//  				   / |4  4  4 |		
	//					 |--------|	4 |	
	//				   / |3  3  3 |	4 |	
	//    			 |---------|3 |   |
    //			   / | 2  2  2 |3 | /
	//			  |---------|2 |__|
	//			  | 1  1  1 |2 | /
	//			  | 1  1  1 |__| 
	//			  | 1  1  1 | /
	//			  |_________|

	//	�����:			     |--------|		
	//  				   / |3  3  3 |		
	//					 |--------|	3 |	
	//				   / |4  4  4 |	3 |	
	//    			 |---------|4 |   |
    //			   / | 1  1  1 |4 | /
	//			  |---------|1 |__|
	//			  | 2  2  2 |1 | /
	//			  | 2  2  2 |__| 
	//			  | 2  2  2 | /
	//			  |_________|

	double dArray[4][3][3]={{{1,1,1},{1,1,1},{1,1,1}},
	                        {{2,2,2},{2,2,2},{2,2,2}},
	                        {{3,3,3},{3,3,3},{3,3,3}},
	                        {{4,4,4},{4,4,4},{4,4,4}}};
	double (*pdAr)[3][3]= dArray;// ��������� �� 1 ����
	double *p_str=dArray[0][0];
	double *p_el=&dArray[0][0][0];// ��������� �� 1 ��
	const int nN = sizeof(dArray)/sizeof(dArray[0]); //����� �����
	const int nNN = sizeof(dArray[0])/sizeof(dArray[0][0][0]);//���_�� ��������� � ����
	const int nNNN = sizeof(dArray)/sizeof(dArray[0][0][0]); // ����������� �� � �������
	const int nNstr =sizeof(dArray[0][0])/sizeof(dArray[0][0][0]);/// ����������� �� � ������
	const int nMstr =(sizeof(dArray)/sizeof(dArray[0][0]))/nN;
	stop
	for(int i=0; i<nN-1;)
	  {
	   //--
	   double *p7=reinterpret_cast<double*>(&dArray[i]);// ���� �� ������ ���� i
       double *p8=reinterpret_cast<double*>(&dArray[i+1]);//���� �� ������ ���� i+1
	   for(int j=0; j<nNN;j++)
	    {double tmp = *(p7+j);
	     *(p7+j) = *(p8+j);
		 *(p8+j)=tmp;
	    }
	   i=i+2;
	  }
	printf("\nSl:");
	for(int i=0;i<nNNN;i++)
	{printf("%1.1f  ",*(p_el+i));}
//---
	for(int t=0; t<nN;)
	  {
	   double(*ptr)[3]=dArray[t];
       double(*ptr2)[3]=dArray[t+1];
	   for(int k=0;k<nMstr;k++)
	    for(int j=0; j<nNstr;j++)
		{double tmp = ptr[k][j];
	     ptr[k][j] = ptr2[k][j];
		 ptr2[k][j]=tmp;
		 if(j==nNstr-1)
		  stop
        }
	   t=t+2;
	   stop
	  }
/*
	for(int t=0; t<nN-1;)
	  {
	   double(*ptr)[3]=dArray[t];
       double(*ptr2)[3]=dArray[t+1];
	   for(int j=0; j<nNstr;j++)
		{double tmp = ptr[t][j];
	     ptr[t][j] = ptr2[t][j];
		 ptr2[t][j]=tmp;
		 stop
        }
	   t=t+2;
	  }*/

	printf("\nS2:");
	for(int i=0;i<nNNN;i++)
	{printf("%1.1f  ",*(p_el+i));}

	stop

	///////////////////////////////////////////////////////////////////////////
	//������� 8�. �������� ���������� ���������� ������ ��������� ���� char.
	//��������� ������ ����������� ������� char � ������� ���������� ��������� 
	//����� ����������� ('*') - �� ����, ���� � ������ ������ ���������, �� ������ ���
	//������� �������� � ������� ���������� ��������� ����� �������� � ���������
	//0-9 � �������� � ����������� ����� �������� �������� ��������� ��� ������� '*'.
	//��������, ��� ��� ����� ���������� ������� ��� ��������� ��������� ��������
	//��������� ��������� ���, � ��� ��������� - �� ����.

	//� ������ ������ "�������� ���������" � ������ ������, ��������:
	//���� - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
	//�����: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
	//� ������������ ������ �� ������� - "��������� �������������"
	{char cArr [10][15];
	 char *p=&cArr[0][0];
	 int ind=0;
	 const int N =sizeof(cArr)/sizeof(cArr[0]);
	 const int M=sizeof(cArr[0])/sizeof(char);
	 
    for(int i = 0;i<N;i++)
	{//1
     for(int j=0;j<M;j++)
	 {//2
   	  cArr[i][j]=' ';
	  for(int k=0;k<M;k++)
	  {//3
       ind = rand()%M;
	  }//3'
	  cArr[i][ind]='*';
	 }//2'
	}//1'
   printf("\nFirst:");
   for(int i=0;i<(N);i++)
	 {printf("\n");
	  for(int j=0;j<M;j++)
	  {printf("%c",cArr [i][j]);
	  }
	 }
   ///
  for (int i=0;i<N;i++)
   {//for1
    int k=0;
    for(int j=0;j<M;j++)
	 {//for2
		 if(cArr [i][j]=='*')
		  {
           cArr [i][j]=' ';
		   cArr [i][k]='*';
		   k++;
		  }
	 }//for2'
   }//for1'
   /*
   for (int i=0;i<N;i++)
   {//for1
    for(int j=0;j<M-1;j++)
	 {int pr=j;// ����� ' '
	  for(int k=j+1;k<M;k++)
	   {if((cArr[i][pr]=='*')&&(cArr[i][k]==' '))
	     pr=k;
	    char tmp = cArr[i][pr];
        cArr[i][pr]=cArr[i][k];
		cArr[i][k]=tmp;
	  
	   } 
	}
   }//for1'
   ///*/
    printf("\nTwo:");
	for(int i=0;i<(N);i++)
	 {printf("\n");
	  for(int j=0;j<M;j++)
	  {printf("%c",cArr [i][j]);
	  }
	 }
    }	
   stop




	// 8�. ������������� ���������� ������� ��������� ��������:
	//����� ���������� ������� � ������� ���������� ��������� �����
	//"��������" ��������� �� �������� ���� � ������������ ����������
	//"�������������"
    {
	 char cArr [10][15];
	 char *p=&cArr[0][0];
	 int ind=0;
	 const int N=sizeof(cArr)/sizeof(cArr[0]);
	 const int M=sizeof(cArr[0])/sizeof(char);
	 
     for(int i = 0;i<N;i++)
	 {//1
      for(int j=0;j<M;j++)
	   {//2
   	    cArr[i][j]=' ';
	    for(int k=0;k<M;k++)
	     {//3
          ind = rand()%M;
	     }//3'
	    cArr[i][ind]='*';
	  }//2'
	}//1'
    printf("\nFirst2:");
    for(int i=0;i<(N);i++)
	 {printf("\n");
	  for(int j=0;j<M;j++)
	 {printf("%c",cArr [i][j]);
	 }
	}
   ///
  //for (int j=M;j>=0;j--)
  for (int j=0;j<M;j++)
   {//for1
    int k=N-1;
    for(int i=N-1;i>=0;i--)
	 {//for2
		 if(cArr [i][j]=='*')
		  {
           cArr [i][j]=' ';
		   cArr [k][j]='*';
		   k--;
		  }
	 }//for2'
   }//for1'
	/*
   for (int j=0;j<M;j++)
   {//for1
    for(int i=0;i<N-1;i++)
	 {int pr=i;// ����� ' '
	  for(int k=i+1;k<N;k++)
	   {if((cArr[pr][j]==' ')&&(cArr[k][j]=='*'))
	     pr=k;
	    char tmp = cArr[pr][j];
        cArr[pr][j]=cArr[k][j];
		cArr[k][j]=tmp;
	  
	   } 
	}
   }//for1'
   */
   ///
   printf("\nTwo2:");
   for(int i=0;i<(N);i++)
    {printf("\n");
     for(int j=0;j<M;j++)
      {printf("%c",cArr [i][j]);
	  }
	 }
    }
    stop

	/////////////////////////////////////////////////////////////////////////////
	// ������� 9. ������.
	//�������� ������ �� ��� double. ����������� ������ �������� ��������
     double aa=1;
	 double &raa=aa;
	 raa++;
	 printf("\naa %f",aa);


	//���������������� ��������� ������. ��� ������� �������, �����
	//linker �� ������� ������ ��� �������� exe-�����
	//extern int& ref;
	 int bb=1;
	 int &ref=bb;
     // ���� ��� ���������� � ������������� � ��.����� ������� 
       stop
 
       
	//���������������� ��������� ������. ��� ������� �������, �����
	//���������� �� ������� ������ 
	const int& ref1 = 1;// ������ ������� ��������� ����������



	//����� ���������:
	char c='A';
	char* pc = &c;//&c ��������� � 
	//�������� ������ �� ���������. ����������� ������ ��������
	char *&rpc = pc;
	//�) �������� �� ������
      *rpc='D';
	  printf("\nc=%c",c);
	//�) ��� �����
	   rpc=rpc+1;
    printf("\nc=%c",*rpc);
	
stop
	return 0;
}