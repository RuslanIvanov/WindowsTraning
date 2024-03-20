void Minus_i (int *&pn,int &rN,int i)
{ for(int k=i;k<rN;k++)
	 { pn[k]=pn[k+1];
	 }
	//new mem - clear mem
	rN=rN-1;
	int *tmp=new int[rN];
	for(int j=0;j<rN;j++)
	 {
	  tmp[j]=pn[j];
	 }
	delete [] pn;
	pn=tmp; //new adr
 	tmp=0;
}