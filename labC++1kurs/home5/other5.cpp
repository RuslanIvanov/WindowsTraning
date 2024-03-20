int Min (int *par,int n)
{int min =(*par);
 for(int i = 0;i<n;i++)
 {if(min>(*par)) min=(*par);
  par++;
 }
 return(min);
}
int Max (int *par,int n)
{int max =(*par);
 for(int i = 0;i<n;i++)
 {if(max<(*par)) max=(*par);
  par++;
 }
 return(max);
}

int Sred(int *par,int n)
{int Sum=0;
 int sr=0;
 for(int i = 0;i<n;i++)
 {
  Sum+=(*par);
  par++;
 }
 sr=Sum/n;
 return(sr);
}