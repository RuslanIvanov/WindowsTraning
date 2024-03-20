void max(int *p1,int *p2,int *pout,int n)
{ for(int i=0;i<n;i++)
	{
	 if((*p1)>(*p2)) (*pout)=(*p1);
	 else (*pout)=(*p2);
	 p1++;
	 p2++;
	 pout++;
	}
}//End max